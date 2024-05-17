#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.cpp"

#define TEST_LIST_SIZE 100

#define TEST_NUMBER_1 1
#define TEST_NUMBER_2 2
#define TEST_NUMBER_3 3
#define TEST_NUMBER_4 4
#define TEST_NUMBER_5 5
#define TEST_NUMBER_6 6

#define SIZE_NUMBER 3


int main()
{
    LinkedList* test_list = List(TEST_LIST_SIZE);

    assert(test_list->head == NULL);
    assert(test_list->size == TEST_LIST_SIZE);

    push_front(test_list, TEST_NUMBER_1);
    push_front(test_list, TEST_NUMBER_2);
    push_front(test_list, TEST_NUMBER_3);
    assert(test_list->head != NULL);
    assert(test_list->head->next != NULL);
    assert(test_list->head->next->next != NULL);

    delete_element(test_list, TEST_NUMBER_3);
    
    assert(test_list->head->next->next == NULL);
   
    assert(test_list->head->next->val == TEST_NUMBER_1 && test_list->head->val == TEST_NUMBER_2);

    delete_element(test_list, TEST_NUMBER_1);
    delete_element(test_list, TEST_NUMBER_2);
    
    assert(test_list->head == NULL);

    push_front(test_list, TEST_NUMBER_4);
    push_front(test_list, TEST_NUMBER_5);
    push_front(test_list, TEST_NUMBER_6);

    assert(test_list->now_size == SIZE_NUMBER);
    
    delete_back_element(test_list);

    assert(test_list->now_size == SIZE_NUMBER - 1);
    assert(test_list->head->next->next = NULL);
    print_list(test_list);

    printf("All tests passed successfully");
}