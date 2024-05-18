#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.cpp"
#include "list-test.h"


int main()
{
    LinkedList* test_list = List(TEST_LIST_SIZE);

    assert(test_list->head == NULL);
    assert(test_list->tail == NULL);
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
    assert(test_list->tail->next == NULL);
    assert(test_list->tail->prev->val == TEST_NUMBER_2 && test_list->tail->val == TEST_NUMBER_1);

    delete_element(test_list, TEST_NUMBER_1);
    delete_element(test_list, TEST_NUMBER_2);
    
    print_list(test_list);
    assert(test_list->head == NULL);
   
    push_front(test_list, TEST_NUMBER_4);
    push_front(test_list, TEST_NUMBER_5);
    push_front(test_list, TEST_NUMBER_6);

    assert(test_list->now_size == SIZE_NUMBER);
    
    delete_back_element(test_list);

    assert(test_list->now_size == SIZE_NUMBER - 1);
    assert(test_list->head->next->next == NULL);
    assert(test_list->head->next->val == TEST_NUMBER_5 && test_list->head->val == TEST_NUMBER_6);
    assert(test_list->tail->val == TEST_NUMBER_5 && test_list->tail->prev->val == TEST_NUMBER_6);

    printf("All tests passed successfully \n");
}