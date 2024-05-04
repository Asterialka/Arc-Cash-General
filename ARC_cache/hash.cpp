#include <stdio.h>
#include <stdlib.h>

#include "hash.h"


// Функция для создания нового элемента хэш-таблицы
HashItem* newHashItem(int key, ListType value) {
    HashItem* item = (HashItem*)malloc(sizeof(HashItem));
    item->key = key;
    item->value = value;
    return item;
}

// Функция для создания новой хэш-таблицы
HashTable* newHashTable(int capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->items = (HashItem**)malloc(capacity * sizeof(HashItem*));
    for (int i = 0; i < capacity; i++) {
        table->items[i] = NULL;
    }
    table->capacity = capacity;
    return table;
}


// Функция для добавления элемента в хэш-таблицу
void hashTableAdd(HashTable* table, int key, ListType value) {
    int index = key % table->capacity;
    HashItem* item = newHashItem(key, value);
    table->items[index] = item;
}

// Функция для вывода содержимого хэш-таблицы
void printHashTable(HashTable* table) {
    printf("Содержимое хэш-таблицы: ");
    for (int i = 0; i < table->capacity; i++) {
        if (table->items[i] != NULL) {
            printf("%d (%d) ", table->items[i]->key, table->items[i]->value);
        }
    }
    printf("\n");
}

// Функция для обновления значения элемента в хэш-таблице
void hashTableUpdate(HashTable* table, int key, ListType newValue) {
    int index = key % table->capacity;
    HashItem* item = table->items[index];
    if (item != NULL && item->key == key) {
        item->value = newValue;
    } else {
        printf("Ключ %d не найден в хэш-таблице\n", key);
    }
}

ListType getHashTableValue(HashTable* table, int key)
{
    int index = key % table->capacity;
    if(table->items[index] != NULL && table->items[index]->key == key)
    {
        return table->items[index]->value;
    }
    return ListType();
}

