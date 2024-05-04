#ifndef HASH_TABLE
#define HASH_TABLE


// Определение enum для списков
typedef enum {
    T1,
    T2,
    B1,
    B2
} ListType;

// Определение структуры элемента хэш-таблицы
typedef struct HashItem {
    int key;
    ListType value;
} HashItem;

// Определение структуры хэш-таблицы
typedef struct HashTable {
    HashItem** items;
    int capacity;
} HashTable;

// Функция для создания нового элемента хэш-таблицы
HashItem* newHashItem(int key, ListType value);
// Функция для создания новой хэш-таблицы
HashTable* newHashTable(int capacity);
// Функция для добавления элемента в хэш-таблицу
void hashTableAdd(HashTable* table, int key, ListType value);
// Функция для вывода содержимого хэш-таблицы
void printHashTable(HashTable* table);
// Функция для обновления значения элемента в хэш-таблице
void hashTableUpdate(HashTable* table, int key, ListType newValue);
////////
ListType getHashTableValue(HashTable* table, int key);


#endif
