#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "cash_arc.c"
#include <stdlib.h>

void contest(FILE *stream)
{
	int cache_size = 0, npages = 0;
	fscanf(stream, "%d %d", &cache_size, &npages);
	assert(cache_size >= 0);
	assert(npages >= 0);
	cache_ARC *arc = init_cache(cache_size);
	assert(arc);
	long int start_t = 0;
	long int end_t = 0;
	double slow_t = 0.0;
	double fast_t = 0.0;
	start_t = clock();
	int i = 0;

	while (!feof(stream))
	{
		fscanf(stream, "%d", &i);
		ARC(arc, i);
	}

	end_t = clock();
	slow_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;

	printf("Time spent %lg seconds\n", slow_t);
	printf("%d - number of hits", arc->hit);
	free_cache(arc);

}

int main()
{
	FILE *stream = fopen("file.txt", "r");
	assert(stream);
	contest(stream);
	fclose(stream);

}
