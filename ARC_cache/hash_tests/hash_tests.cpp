#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

// Функция для загрузки чисел из файла
void load_numbers_from_file(const char* filename, int* numbers, int max_count)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (count < max_count && fscanf(file, "%d", &numbers[count]) != EOF)
    {
        count++;
    }
    fclose(file);
}

// Тест добавления и поиска большого количества элементов
void test_hash_table_large(Hash* hash_table, int* numbers, int num_numbers)
{
    for (int i = 0; i < num_numbers; ++i)
    {
        // Проверяем, что элемент не существует, прежде чем его добавить
        if (find_element_in_hash(hash_table, numbers[i]) == NULL) {
            hashTableAdd(hash_table, NULL, numbers[i]);
        }
    }

    for (int i = 0; i < num_numbers; ++i)
    {
        assert(find_element_in_hash(hash_table, numbers[i]) != NULL);
    }

    for (int i = 0; i < num_numbers; ++i)
    {
        hash_delete_elem(numbers[i], hash_table);
        assert(find_element_in_hash(hash_table, numbers[i]) == NULL);
    }
}

// Тест для проверки коллизий
void test_hash_collisions()
{
    Hash* hash_table = create_HASH_TABLE(10);
    int values[] = {1, 11, 21, 31};

    for (int i = 0; i < 4; ++i)
    {
        hashTableAdd(hash_table, NULL, values[i]);
    }

    for (int i = 0; i < 4; ++i)
    {
        assert(find_element_in_hash(hash_table, values[i]) != NULL);
    }

    free_HASH(hash_table);
}

// Тест для проверки перезаписи значений
void test_overwrite_values()
{
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 5);
    hashTableAdd(hash_table, NULL, 5);

    assert(find_element_in_hash(hash_table, 5) != NULL);

    free_HASH(hash_table);
}

// Тест для проверки корректности удаления элементов
void test_removal()
{
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 5);
    assert(find_element_in_hash(hash_table, 5) != NULL);
    hash_delete_elem(5, hash_table);
    assert(find_element_in_hash(hash_table, 5) == NULL);

    free_HASH(hash_table);
}

// Тест для проверки поведения при попытке добавления элементов в полностью заполненную таблицу

void test_full_table()
{
    const int capacity = 10;
    Hash* hash_table = create_HASH_TABLE(capacity);
    // Добавляем capacity элементов
    for (int i = 0; i < capacity; ++i)
    {
        hashTableAdd(hash_table, NULL, i);
    }
    // Попытка добавления еще одного элемента
    assert(hashTableAdd(hash_table, NULL, capacity + 1) == NULL);
    free_HASH(hash_table);
}


// Тест для проверки поведения при попытке поиска несуществующего элемента
void test_search_non_existing()
{
    Hash* hash_table = create_HASH_TABLE(10);
    // Поиск несуществующего элемента
    assert(find_element_in_hash(hash_table, 100) == NULL);
    free_HASH(hash_table);
}

// Тест для проверки поведения при попытке удаления несуществующего элемента
void test_delete_non_existing()
{
    Hash* hash_table = create_HASH_TABLE(10);
    // Попытка удаления несуществующего элемента
    hash_delete_elem(100, hash_table);
    free_HASH(hash_table);
}

// Тест для проверки работы с пустой таблицей
void test_empty_table()
{
    Hash* hash_table = create_HASH_TABLE(10);
    // Попытка удаления элемента из пустой таблицы
    hash_delete_elem(100, hash_table);
    free_HASH(hash_table);
}

int main()
{
    const int num_numbers = 10000;
    int numbers[num_numbers];

    load_numbers_from_file("numbers.txt", numbers, num_numbers);

    Hash* hash_table = create_HASH_TABLE(num_numbers * 2);

    test_hash_table_large(hash_table, numbers, num_numbers);
    test_hash_collisions();
    test_overwrite_values();
    test_removal();
    test_full_table();
    test_search_non_existing();
    test_delete_non_existing();
    test_empty_table();

    free_HASH(hash_table);

    printf("All tests passed successfully.\n");
    return 0;
}
