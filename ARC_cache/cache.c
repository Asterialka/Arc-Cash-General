#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "cache.h"

long long int min(long long int a, long long int b)
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

long long int max(long long int a, long long int b)
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

//initializes ARC cache with size_of_cache
cache_ARC* init_cache(int size_of_cache)
{
	assert(size_of_cache >= 0);
	cache_ARC *cache = (cache_ARC*) malloc(sizeof(cache_ARC));
	assert(cache);
	cache->T1 = init_List(0);	//init with 0 linked list
	assert(cache->T1);
	cache->T2 = init_List(0);	//init with 0 linked list
	assert(cache->T2);
	cache->B1 = init_List(0);	//init with 0 linked list
	assert(cache->B1);
	cache->B2 = init_List(0);	//init with 0 linked list
	assert(cache->B2);
	cache->hash_ARC = create_HASH_TABLE(10000);	//size 2c
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
	free_HASH(cache->hash_ARC);
	free(cache);

}

cache_ARC* ARC(cache_ARC *ARC, long long int page)
{
	hashnode *tmp = find_element_in_hash(ARC->hash_ARC, page);

	node *tt2 = find_element(ARC->T2, page);
	node *tt1 = find_element(ARC->T1, page);

	if ((tt1 != NULL) || (tt2 != NULL))	//case 1
	{
		//node *ptr = tmp->point;
		hash_delete_elem(page, ARC->hash_ARC);
		if (tt1 != NULL)
		{
			delete_by_point(tt1, ARC->T1);
			//printf("element was in t1\n");
		}
		else
		{
			delete_by_point(tt2, ARC->T2);
			//printf("element was in t2\n");
		}

		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page);
		ARC->hit++;
		return ARC;
	}

	node *b1 = find_element(ARC->B1, page);
	if (b1 != NULL)
	{
		*(ARC->p) = min(ARC->size_ARC, *(ARC->p) + max(ARC->B2->now_size / ARC->B1->now_size, 1));
		replace(ARC, page);
		delete_by_point(b1, ARC->B1);
		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page);
		//printf("element was in b1\n");

		return ARC;
	}

	node *b2 = find_element(ARC->B2, page);
	if (b2 != NULL)
	{
		*(ARC->p) = max(0, *(ARC->p) - max(ARC->B1->now_size / ARC->B2->now_size, 1));
		replace(ARC, page);
		delete_by_point(b2, ARC->B2);
		pushFront(ARC->T2, page);
		hashTableAdd(ARC->hash_ARC, ARC->T2->head, page);
		//printf("element was in b2\n");
		return ARC;
	}
	else
	{
		if ((ARC->B1->now_size + ARC->T1->now_size) == ARC->size_ARC)
		{
			if (ARC->T1->now_size < ARC->size_ARC)
			{
				popBack(ARC->B1);
				replace(ARC, page);
				//printf("case 1.1\n");
			}
			else
			{
				popBack(ARC->T1);
				hash_delete_elem(ARC->T1->tail->val, ARC->hash_ARC);
				//printf("case 1.2\n");
			}
		}

		if (((ARC->B1->now_size + ARC->T1->now_size) < ARC->size_ARC) && (((ARC->B1->now_size + ARC->T1->now_size) + (ARC->B2->now_size + ARC->T2->now_size)) >= ARC->size_ARC))
		{
			if (((ARC->B1->now_size + ARC->T1->now_size) + (ARC->B2->now_size + ARC->T2->now_size)) == 2 *ARC->size_ARC)
			{
				//printf("case 2.3\n");
				if (ARC->B2->now_size != 0)
				{
					popBack(ARC->B2);
				}

				//printf("%d", ARC);

				replace(ARC, page);
			}
		}

		//printf("new\n");

		pushFront(ARC->T1, page);
		hashTableAdd(ARC->hash_ARC, ARC->T1->head, page);
		return ARC;
	}
}

void replace(cache_ARC *arc, long long int page)
{
	assert((*arc->p != 0) && (*arc->p < arc->size_ARC) && "incorrect parament p in replace");
	assert((arc->p != 0) && (arc->T1 != 0) && (arc->T2 != 0) && (arc->B1 != 0) && (arc->B2 != 0) && "Was given NULL pointer");
	if ((arc->T1->now_size >= 1) && ((((find_element(arc->B2, page) != NULL) && (arc->T1->now_size == *(arc->p)) || (arc->T1->now_size > *(arc->p))))))
	{
		popBack(arc->T1);
		hash_delete_elem(arc->T1->tail->val, arc->hash_ARC);
		pushFront(arc->B1, page);
		printf("the first");
	}
	else
	{
		popBack(arc->T2);
		hash_delete_elem(arc->T2->tail->val, arc->hash_ARC);
		pushFront(arc->B2, page);
		printf("the second");
	}
}
