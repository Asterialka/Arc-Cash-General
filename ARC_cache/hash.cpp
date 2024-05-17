#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

// узел в хэш-таблице
hashnode* create_hashnode(int value, node *point, hashnode *prev)
{
    hashnode *tmp = (hashnode*) malloc(sizeof(hashnode));
    tmp->value = value;
    tmp->point = point;
    tmp->prev = prev;
    tmp->next = NULL;
    return tmp;
}

// функция для инициализации массива в хэш таблице
hashnode **init_array(int capacity)
{
    hashnode **array = (hashnode **) malloc(capacity * sizeof(hashnode*));
    for (int i = 0; i < capacity; i++)
    {
        array[i] = NULL;
    }
    return array;
}

// Функция для создания новой хэш-таблицы
Hash* create_HASH_TABLE(int capacity)
{
    Hash *our_hash = (Hash*) malloc(sizeof(Hash));
    our_hash->capacity = capacity;
    our_hash->array = init_array(capacity);
    return our_hash;
}


// Функция для добавления элемента в хэш-таблицу
Hash* hashTableAdd(Hash *table, node *point, int value)
{
    int index = hash_function(value, table);
    hashnode *tmp = table->array[index];

    // Проверяем, есть ли уже элемент с таким ключом в таблице
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            tmp->point = point;
            return table;
        }
        tmp = tmp->next;
    }

    // Если элемент с таким ключом не найден, добавляем новый элемент в конец цепочки
    tmp = table->array[index];
    if (tmp == NULL)
    {
        table->array[index] = create_hashnode(value, point, NULL);
    }
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = create_hashnode(value, point, tmp);
    }

    // Проверяем, что таблица не полностью заполнена
    int num_elements = 0;
    for (int i = 0; i < table->capacity; ++i)
    {
        hashnode *cur = table->array[i];
        while (cur != NULL)
        {
            num_elements++;
            cur = cur->next;
        }
    }
    if (num_elements > table->capacity)
    {

        return NULL;
    }

    return table;
}


// Ищем элемент в хэш таблице
hashnode* find_element_in_hash(Hash *hash, int page)
{
    int pl = hash_function(page, hash);
    hashnode *tmp = hash->array[pl];
    while (tmp != NULL)
    {
        if (tmp->value == page)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL; // Возвращаем NULL, если элемент не найден
}

// Hash-function
int hash_function(int value, Hash *table)
{
    return value % table->capacity;
}

// Освобождение элементов ветки
void free_the_branch(hashnode *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    free_the_branch(tmp->next);
    free(tmp);
}

// Print_hash
void print_hash(Hash *hash)
{
    if (hash)
    {
        for (int i = 0; i < hash->capacity; i++)
        {
            hashnode *ptr = hash->array[i];
            if (ptr)
            {
                while (ptr != NULL)
                {
                    printf("%d ", ptr->value);
                    ptr = ptr->next;
                }
                printf("\n");
            }
        }
    }
}

void free_HASH(Hash *hash)
{
    for (int i = 0; i < hash->capacity; i++)
    {
        hashnode *tmp = hash->array[i];
        if (tmp != NULL)
        {
            free_the_branch(tmp);
        }
    }
    free(hash->array);
    free(hash);
}

void hash_delete_elem(int page, Hash *s)
{
    hashnode *h_node = find_element_in_hash(s, page);
    if (h_node == NULL)
    {
        return;
    }
    if (h_node->prev == NULL)
    {
        if (h_node->next == NULL)
        {
            s->array[hash_function(page, s)] = NULL;
        }
        else
        {
            s->array[hash_function(page, s)] = h_node->next;
            h_node->next->prev = NULL;
        }
    }
    else
    {
        h_node->prev->next = h_node->next;
        if (h_node->next != NULL)
        {
            h_node->next->prev = h_node->prev;
        }
    }
    free(h_node);
}

