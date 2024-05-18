int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

struct cache_ARC
{
	int size_ARC;	// size c 
	LinkedList * T1;
	LinkedList * B1;
	LinkedList * T2;
	LinkedList * B2;
	int *p;	// parametr thar regul 
	Hash * hash_ARC;	// hash_table size c
	int hit;

};

//initializes ARC cache with size_of_cache
cache_ARC* init_cache(int size_of_cache)
{
	assert(size_of_cache >= 0);
	cache_ARC *cache = (cache_ARC*) malloc(sizeof(cache_ARC));
	assert(cache);
	cache->T1 = init_List(0, 1);	//init with 0 linked list
	assert(cache->T1);
	cache->T2 = init_List(0, 2);	//init with 0 linked list
	assert(cache->T2);
	cache->B1 = init_List(0, 3);	//init with 0 linked list
	assert(cache->B1);
	cache->B2 = init_List(0, 4);	//init with 0 linked list
	assert(cache->B2);
	cache->hash_ARC = create_HASH_TABLE(size_of_cache);	//size 2c
	assert(cache->hash_ARC);
	cache->p = 0;
	cache->size_ARC = size_of_cache;
	cache->hit = 0;
	return cache;
}

void free_cache(cache_ARC *cache)
{
	assert(cache);
	list_free(cache->T1);
	list_free(cache->T2);
	list_free(cache->B1);
	list_free(cache->B2);
	free_hash(cache->hash_ARC);
	free(cache);

}

void ARC(cache_ARC *ARC, int page)
{
	hashnode *tmp = find_element_in_hash(ARC->hash_ARC, page);
	if (tmp != NULL)	//case 1
	{
		node *ptr = tmp->point;
		hash_delete_elem(page, ARC->hash_ARC);
		if (find_element(ARC->T1, page) != NULL)
		{
			ARC->T1 = delete_by_point(ptr, ARC->T1);
		}
		else
		{
			ARC->T2 = delete_by_point(ptr, ARC->T2);
		}

		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page, 2);
		ARC->hit++;
		return;
	}

	hashnode *b1 = find_element(ARC->B1, page);
	if (b1 != NULL)
	{
		*(ARC->p) = min(ARC->size_ARC, *(ARC->p) + max(ARC->B2->now_size / ARC->B1->now_size, 1));
		replace(ARC, page);
		ARC->B1 = delete_by_point(b1, ARC->B1);
		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page, 2);

		return;
	}

	hashnode *b2 = find_element(ARC->B2, page);
	if (b2 != NULL)
	{
		*(ARC->p) = max(0, *(ARC->p) - max(ARC->B1->now_size / ARC->B2->now_size, 1));
		replace(ARC, page);
		ARC->B2 = delete_by_point(b2, ARC->B2);
		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page, 2);
		return;
	}
	else
	{
		if ((ARC->B1->now_size + ARC->T1->now_size) == ARC->size_ARC)
		{
			if (ARC->T1->now_size < ARC->size_ARC)
			{
				popBack(ARC->B1);
				replace(ARC, page);
			}
			else
			{
				int page = ARC->T1->tail->val;
				popBack(ARC->T1);
				hash_delete_elem(page, ARC->hash_ARC);
				printf("i");
			}
		}

		if (((ARC->B1->now_size + ARC->T1->now_size) < ARC->size_ARC) && (((ARC->B1->now_size + ARC->T1->now_size) + (ARC->B2->now_size + ARC->T2->now_size)) >= ARC->size_ARC))
		{
			if (((ARC->B1->now_size + ARC->T1->now_size) + (ARC->B2->now_size + ARC->T2->now_size)) == 2 *ARC->size_ARC)
			{
				if (ARC->B2->now_size != 0)
				{
					popBack(ARC->B2);
				}

				replace(ARC, page);
			}
		}

		pushFront(ARC->T1, page);
		hashTableAdd(ARC->hash_ARC, ARC->T1->head, page, 1);
	}
}

void replace(cache_ARC *arc, int page)
{
	if ((arc->T1->now_size >= 1) && ((((find_element(arc->B2, page) != NULL) && (arc->T1->now_size == *(arc->p)) || (arc->T1->now_size > *(arc->p))))))
	{
		int page = arc->T1->tail->val;
		popBack(arc->T1);
		hash_delete_elem(page, arc->hash_ARC);
		pushFront(arc->B1, page);
	}
	else
	{
		int page = arc->T2->tail->val;
		popBack(arc->T2);
		hash_delete_elem(page, arc->hash_ARC);
		pushFront(arc->B2, page);
	}
}
