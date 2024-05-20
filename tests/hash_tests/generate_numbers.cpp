#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 10000
#define MAX_VALUE 10000

void generate_random_numbers(const char* filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < NUM_COUNT; i++) {
        int num = rand() % MAX_VALUE + 1;
        fprintf(file, "%d\n", num);
    }
    fprintf(file, "hfbvh");

    fclose(file);
}

int main() {
    generate_random_numbers("numbers.txt");
    printf("File 'numbers.txt' has been generated with random numbers.\n");
    return 0;
}
