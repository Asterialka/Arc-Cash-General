#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void generate(int cache_size, int n_size, int max_page, FILE *file)
{
	srand(time(NULL));

	fprintf(file, "%d ", cache_size);
	fprintf(file, "%d\n", n_size);

	for (int i = 0; i < n_size; i++)
	{
		int num = rand() % max_page + 1;
		assert(num >= 0);
		fprintf(file, "%d\n", num);
	}
}
