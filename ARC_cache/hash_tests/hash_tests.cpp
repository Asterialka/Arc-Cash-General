#include "hash_test.h"

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
    printf("Loaded %d numbers from file.\n", count);
}

// Тест добавления и поиска большого количества элементов
void test_hash_table_large(Hash* hash_table, int* numbers, int num_numbers)
{
    printf("Running test_hash_table_large...\n");
    for (int i = 0; i < num_numbers; ++i)
    {
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
    printf("test_hash_table_large passed.\n");
}

// Тест для проверки коллизий
void test_hash_collisions()
{
    printf("Running test_hash_collisions...\n");
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
    printf("test_hash_collisions passed.\n");
}

// Тест для проверки перезаписи значений
void test_overwrite_values()
{
    printf("Running test_overwrite_values...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 5);
    hashTableAdd(hash_table, NULL, 5);

    assert(find_element_in_hash(hash_table, 5) != NULL);

    free_HASH(hash_table);
    printf("test_overwrite_values passed.\n");
}

// Тест для проверки корректности удаления элементов
void test_removal()
{
    printf("Running test_removal...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 5);
    assert(find_element_in_hash(hash_table, 5) != NULL);
    hash_delete_elem(5, hash_table);
    assert(find_element_in_hash(hash_table, 5) == NULL);

    free_HASH(hash_table);
    printf("test_removal passed.\n");
}


// Проверка, полностью ли заполнена таблица
int is_table_full(Hash *table) {
    int num_elements = 0;
    for (int i = 0; i < table->capacity; ++i) {
        hashnode *cur = table->array[i];
        while (cur != NULL) {
            num_elements++;
            cur = cur->next;
        }
    }
    return num_elements >= table->capacity;
}

// Тест для проверки поведения при попытке добавления элементов в полностью заполненную таблицу
void test_full_table()
{
    printf("Running test_full_table...\n");
    const int capacity = 10;
    Hash* hash_table = create_HASH_TABLE(capacity);
    // Добавляем capacity элементов
    for (int i = 0; i < capacity; ++i)
    {
        hashTableAdd(hash_table, NULL, i);
    }
    // Попытка добавления еще одного элемента
    assert(is_table_full(hash_table));
    free_HASH(hash_table);
    printf("test_full_table passed.\n");
}

// Тест для проверки поведения при попытке поиска несуществующего элемента
void test_search_non_existing()
{
    printf("Running test_search_non_existing...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    // Поиск несуществующего элемента
    assert(find_element_in_hash(hash_table, 100) == NULL);
    free_HASH(hash_table);
    printf("test_search_non_existing passed.\n");
}

// Тест для проверки поведения при попытке удаления несуществующего элемента
void test_delete_non_existing()
{
    printf("Running test_delete_non_existing...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    // Попытка удаления несуществующего элемента
    hash_delete_elem(100, hash_table);
    free_HASH(hash_table);
    printf("test_delete_non_existing passed.\n");
}

// Тест для проверки работы с пустой таблицей
void test_empty_table()
{
    printf("Running test_empty_table...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    // Попытка удаления элемента из пустой таблицы
    hash_delete_elem(100, hash_table);
    free_HASH(hash_table);
    printf("test_empty_table passed.\n");
}

// Тест для проверки последовательных добавлений и удалений
void test_sequential_add_and_remove()
{
    printf("Running test_sequential_add_and_remove...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    for (int i = 0; i < 10; ++i)
    {
        hashTableAdd(hash_table, NULL, i);
        assert(find_element_in_hash(hash_table, i) != NULL);
        hash_delete_elem(i, hash_table);
        assert(find_element_in_hash(hash_table, i) == NULL);
    }
    free_HASH(hash_table);
    printf("test_sequential_add_and_remove passed.\n");
}

// Тест для проверки работы с большим количеством повторяющихся элементов
void test_repeated_elements()
{
    printf("Running test_repeated_elements...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    for (int i = 0; i < 100; ++i)
    {
        hashTableAdd(hash_table, NULL, 5);
    }
    assert(find_element_in_hash(hash_table, 5) != NULL);
    hash_delete_elem(5, hash_table);
    assert(find_element_in_hash(hash_table, 5) == NULL);
    free_HASH(hash_table);
    printf("test_repeated_elements passed.\n");
}

// Тест для проверки работы с большими значениями
void test_large_values()
{
    printf("Running test_large_values...\n");

    Hash* hash_table = create_HASH_TABLE(10);


    hashTableAdd(hash_table, NULL, INT_MAX);
    assert(find_element_in_hash(hash_table, INT_MAX) != NULL);
    hash_delete_elem(INT_MAX, hash_table);
    assert(find_element_in_hash(hash_table, INT_MAX) == NULL);
    hashTableAdd(hash_table, NULL, INT_MIN);
    assert(find_element_in_hash(hash_table, INT_MIN) != NULL);
    hash_delete_elem(INT_MIN, hash_table);
    assert(find_element_in_hash(hash_table, INT_MIN) == NULL);

    free_HASH(hash_table);

    printf("test_large_values passed.\n");
}

// Тест для проверки удаления элемента из середины цепочки
void test_remove_middle_of_chain() {
    printf("Running test_remove_middle_of_chain...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 1);
    hashTableAdd(hash_table, NULL, 11);
    hashTableAdd(hash_table, NULL, 21);
    hash_delete_elem(11, hash_table); // Удаление элемента 11
    assert(find_element_in_hash(hash_table, 1) != NULL); // Элемент 1 должен остаться
    assert(find_element_in_hash(hash_table, 11) == NULL); // Элемент 11 должен быть удален
    assert(find_element_in_hash(hash_table, 21) != NULL); // Элемент 21 должен остаться
    free_HASH(hash_table);
    printf("test_remove_middle_of_chain passed.\n");
}

// Тест для проверки работы с нулевыми значениями
void test_null_values()
{
    printf("Running test_null_values...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, NULL, 0);
    assert(find_element_in_hash(hash_table, 0) != NULL);
    hash_delete_elem(0, hash_table);
    assert(find_element_in_hash(hash_table, 0) == NULL);
    free_HASH(hash_table);
    printf("test_null_values passed.\n");
}

// Тест для проверки добавления элементов с одинаковыми ключами, но разными значениями
void test_same_key_different_values()
{
    printf("Running test_same_key_different_values...\n");
    Hash* hash_table = create_HASH_TABLE(10);
    hashTableAdd(hash_table, (node*)1, 5);
    assert(find_element_in_hash(hash_table, 5)->point == (node*)1);
    hashTableAdd(hash_table, (node*)2, 5);
    assert(find_element_in_hash(hash_table, 5)->point == (node*)2);
    hash_delete_elem(5, hash_table);
    assert(find_element_in_hash(hash_table, 5) == NULL);
    free_HASH(hash_table);
    printf("test_same_key_different_values passed.\n");
}

// Тест для проверки производительности
void test_performance()
{
    printf("Running test_performance...\n");
    const int num_elements = 1000000;
    Hash* hash_table = create_HASH_TABLE(num_elements * 2);

    // Замеряем время добавления элементов
    clock_t start = clock();
    for (int i = 0; i < num_elements; ++i)
    {
        hashTableAdd(hash_table, NULL, i);
    }
    clock_t end = clock();
    printf("Time taken to add %d elements: %f seconds\n", num_elements, (double)(end - start) / CLOCKS_PER_SEC);

    // Замеряем время поиска элементов
    start = clock();
    for (int i = 0; i < num_elements; ++i)
    {
        assert(find_element_in_hash(hash_table, i) != NULL);
    }
    end = clock();
    printf("Time taken to find %d elements: %f seconds\n", num_elements, (double)(end - start) / CLOCKS_PER_SEC);

    // Замеряем время удаления элементов
    start = clock();
    for (int i = 0; i < num_elements; ++i)
    {
        hash_delete_elem(i, hash_table);
    }
    end = clock();
    printf("Time taken to delete %d elements: %f seconds\n", num_elements, (double)(end - start) / CLOCKS_PER_SEC);

    free_HASH(hash_table);
    printf("test_performance passed.\n");
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
    test_sequential_add_and_remove();
    test_repeated_elements();
    test_large_values();
    test_remove_middle_of_chain();
    test_null_values();
    test_same_key_different_values();
    test_performance();

    free_HASH(hash_table);

    printf("All tests passed successfully.\n");
    return 0;
}
