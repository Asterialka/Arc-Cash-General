#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#include "hash.cpp"
#include "list.cpp"

void print_lists(LinkedList* listT1, LinkedList* listT2, LinkedList* listB1, LinkedList* listB2);


int main() {
    // Создаем новую хэш-таблицу
    HashTable* table = newHashTable(1000);

    // Создаем списки
    LinkedList* listT1 = List(100);
    LinkedList* listT2 = List(100);
    LinkedList* listB1 = List(100);
    LinkedList* listB2 = List(100);

    //
    pushFront(listT1, 2);

    //IsPresent(listT1, 2);

    pushFront (listT2, 3);

    print_lists(listT1, listT2, listB1, listB2);

    hashTableAdd(table, 2, T1);

    hashTableAdd(table, 3, T2);

    printHashTable(table);

    find_element(listT1, 2, "T1");
    delete_element(listT1, 2);

    pushFront(listT2, 2);

    hashTableUpdate(table, 2, T2);

    print_lists(listT1, listT2, listB1, listB2);

    int test = getHashTableValue(table, 2);
    printf("Полученное значение по ключу = %d \n", test);

    printHashTable(table);

    return 0;
}

void print_lists(LinkedList* listT1, LinkedList* listT2, LinkedList* listB1, LinkedList* listB2){
    printf("\n");
    printf("Содержимое списка T1: ");
    print_list(listT1);
    printf("\n");
    printf("Содержимое списка T2: ");
    print_list(listT2);
    printf("\n");
    printf("Содержимое списка B1: ");
    print_list(listB1);
    printf("\n");
    printf("Содержимое списка B2: ");
    print_list(listB2);
    printf("\n");

}







