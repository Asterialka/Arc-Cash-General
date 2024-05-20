#ifndef HASH_TESTS_H
#define HASH_TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include "hash.h"

// Функция для загрузки чисел из файла
void load_numbers_from_file(const char* filename, int* numbers, int max_count);

// Тест добавления и поиска большого количества элементов
void test_hash_table_large(Hash* hash_table, int* numbers, int num_numbers);

// Тест для проверки коллизий
void test_hash_collisions();

// Тест для проверки перезаписи значений
void test_overwrite_values();

// Тест для проверки корректности удаления элементов
void test_removal();

// Проверка, полностью ли заполнена таблица
int is_table_full(Hash* table);

// Тест для проверки поведения при попытке добавления элементов в полностью заполненную таблицу
void test_full_table();

// Тест для проверки поведения при попытке поиска несуществующего элемента
void test_search_non_existing();

// Тест для проверки поведения при попытке удаления несуществующего элемента
void test_delete_non_existing();

// Тест для проверки работы с пустой таблицей
void test_empty_table();

// Тест для проверки последовательных добавлений и удалений
void test_sequential_add_and_remove();

// Тест для проверки работы с большим количеством повторяющихся элементов
void test_repeated_elements();

// Тест для проверки работы с большими значениями
void test_large_values();

// Тест для проверки удаления элемента из середины цепочки
void test_remove_middle_of_chain();

// Тест для проверки работы с нулевыми значениями
void test_null_values();

// Тест для проверки добавления элементов с одинаковыми ключами, но разными значениями
void test_same_key_different_values();

// Тест для проверки производительности
void test_performance();

#endif
