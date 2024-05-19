#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../list.c"
#include "list-test.h"

void test1()
{
    LinkedList* test_list = init_List(TEST_LIST_SIZE);

    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
    assert(test_list->size == TEST_LIST_SIZE);

    list_free(test_list);
}

void test2()
{
    LinkedList* test_list = init_List(TEST_LIST_SIZE);

    pushFront(test_list, TEST_NUMBER_1);
    pushFront(test_list, TEST_NUMBER_2);
    pushFront(test_list, TEST_NUMBER_3);
    assert(test_list->head != NULL);
    assert(test_list->head->next != NULL);
    assert(test_list->head->next->next != NULL);

    delete_element(test_list, TEST_NUMBER_3);
    
    assert(test_list->head->next->next == NULL);
    assert(test_list->head->next->val == TEST_NUMBER_1 && test_list->head->val == TEST_NUMBER_2);
    assert(test_list->tail->next == NULL);
    assert(test_list->tail->prev->val == TEST_NUMBER_2 && test_list->tail->val == TEST_NUMBER_1);

    list_free(test_list);
}

void test3()
{
    LinkedList* test_list = init_List(TEST_LIST_SIZE);

    pushFront(test_list, TEST_NUMBER_1);
    pushFront(test_list, TEST_NUMBER_2);
    pushFront(test_list, TEST_NUMBER_3);
   
    print_list(test_list);

    list_free(test_list);
} 

void test4()
{
    LinkedList* test_list = init_List(TEST_LIST_SIZE);

    pushFront(test_list, TEST_NUMBER_4);
    pushFront(test_list, TEST_NUMBER_5);
    pushFront(test_list, TEST_NUMBER_6);

    assert(test_list->now_size == SIZE_NUMBER);
    
    popBack(test_list);

    assert(test_list->now_size == SIZE_NUMBER - 1);
    assert(test_list->head->next->next == NULL);
    assert(test_list->head->next->val == TEST_NUMBER_5 && test_list->head->val == TEST_NUMBER_6);
    assert(test_list->tail->val == TEST_NUMBER_5 && test_list->tail->prev->val == TEST_NUMBER_6);

    print_list(test_list);

    list_free(test_list);
}

void test5()
{
    LinkedList* test_list = init_List(TEST_LIST_SIZE);

    pushFront(test_list, TEST_NUMBER_4);
    pushFront(test_list, TEST_NUMBER_5);
    pushFront(test_list, TEST_NUMBER_6);


    assert(find_element(test_list, TEST_NUMBER_5) == 1);
    assert(find_element(test_list, TEST_NUMBER_2) == 0);

    print_list(test_list);
    
    list_free(test_list);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    printf("All tests passed successfully \n");
}
