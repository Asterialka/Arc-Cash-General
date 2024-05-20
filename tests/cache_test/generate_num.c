#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


void generate(int cache_size, int n_size, int max_page, const char* filename){
    FILE *file = fopen(filename, "w");
	srand(time(NULL));

	fprintf(file, "%d ", cache_size);
	fprintf(file, "%d\n", n_size);

	for (int i = 0; i < n_size; i++)
	{
		int num = rand() % max_page + 1;
		assert(num >= 0);
		fprintf(file, "%d\n", num);
	}

    fclose(file);
}

int main(){
    int cash_size = 0, n_size = 0;
    scanf( "%i %i", &cash_size, &n_size);
    generate(cash_size, n_size, 1000, "tests/cache_test/test1.txt");
    printf("File 'test1.txt' has been generated with random numbers for cash.\n");
    return 0;

}
