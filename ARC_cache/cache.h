#pragma once

#include <stdlib.h>

#include "list.h"
#include "hash.h"

typedef struct cache_ARC cache_ARC;

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

cache_ARC* init_cache(int size_of_cache); /* initializes ARC cache with size_of_cache */

void free_cache(cache_ARC *cache); /* free cache */

void ARC(cache_ARC *ARC, long long int page); /* the main function of cache */

void replace(cache_ARC *arc, long long int page); /* special replace function */
