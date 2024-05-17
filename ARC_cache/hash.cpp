#include <stdio.h>
#include <stdlib.h>

#include "hash.h"


//узел в хэш-таблице
hashnode* create_hashnode(int value, node *point, hashnode *prev)
{
	hashnode *tmp = NULL;
	tmp = (hashnode*) malloc(sizeof(hashnode));
	tmp->value = value;
	tmp->point = point;
	tmp->prev = prev;
	tmp->next = NULL;

	return tmp;
}


//функция для инициализации массива в хэш таблице
hashnode **init_array(int capacity)
{
	hashnode **array = NULL;
	array = (hashnode **) malloc(capacity* sizeof(hashnode*));
	for (int i = 0; i < capacity; i++)
	{
		(array)[i] = NULL;
	}

	return array;

}

// Функция для создания новой хэш-таблицы
Hash* create_HASH_TABLE(int capacity)
{
	hashnode **array = NULL;
	Hash *our_hash = NULL;
	our_hash = (Hash*) malloc(sizeof(Hash));
	our_hash->capacity = capacity;
	array = init_array(capacity);
	our_hash->array = array;

	return our_hash;
}

// Функция для добавления элемента в хэш-таблицу
Hash* hashTableAdd(Hash *table, node *point, int value)
{
	int index = hash_function(value, table);
	hashnode *tmp = (table->array)[index];
	if (tmp == NULL)
	{
		tmp = create_hashnode(value, point, NULL);
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = create_hashnode(value, point, tmp);
	}

	(table->array)[index] = tmp;
	return table;
}

//ищем элемент в хэш таблице 
hashnode* find_element_in_hash(Hash *hash, int page)
{
	int pl = hash_function(page, hash);
	hashnode *tmp = (hash->array)[pl];
	while (tmp != NULL)
	{
		if ((tmp->value) == page)
		{
			return tmp;
		}

		tmp = tmp->next;
	}

	return NULL;
}

//hash-function
int hash_function(int value, Hash *table)
{
	int index = value % (table->capacity);
	return index;
}

Hash* free_the_branch(hashnode *tmp)
{
	if (tmp == NULL)
	{
		return;
	}

	free_the_branch(tmp->next);
	free_item(tmp);
}
//free hash item
void free_item(hashnode *node)
{
	node->point = NULL;
	node->value = 0;
	free(node);
}

//print hash
void print_hash(Hash *hash)
{
	if (hash)
	{
		for (int i = 0; i < hash->capacity; i++)
		{
			hashnode *ptr = hash->array[i];
			if (ptr)
			{
				while (ptr != NULL)
				{
					printf("%d", ptr->value);
					ptr = ptr->next;
				}
			}
		}
	}
}
void free_HASH(Hash *hash)
{
	for (int i = 0; i < hash->capacity; i++)
	{
		hashnode *tmp = hash->array[i];
		if (tmp != NULL)
		{
			free_the_branch(tmp);
		}
	}

	free(hash->array);
	free(hash);
}
void hash_delete_elem(int page, Hash *s)
{
	hashnode * h_node;
	hashnode * h_node_next;

	h_node = find_element_in_hash(s, page);
	if (h_node == NULL)
		return;

	if (h_node->prev == NULL)
	{
		if (h_node->next == NULL)
		{
			h_node->value = 0;
			h_node->point = NULL;
			return;
		}

		h_node_next = h_node->next;
		*h_node = *(h_node->next);
		h_node->prev = NULL;

		free(h_node_next);

		if (h_node->next != NULL)
			h_node->next->prev = h_node;

		return;
	}

	h_node->prev->next = h_node->next;

	if (h_node->next != NULL)
		h_node->next->prev = h_node->prev;

	free(h_node);
}
