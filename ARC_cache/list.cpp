#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

node* create_node()
{
	node *new_node = (node*) malloc(sizeof(node));
	return new_node;
}

LinkedList* List(int size)
{
	LinkedList *list = NULL;
	list = (LinkedList*) malloc((sizeof(LinkedList)));
	list->size = size;
	list->now_size = 0;
	list->head = NULL;
	list->tail = NULL;

	return list;

}

void list_free(LinkedList **list)
{
	node *tmp = (*list)->head;
	node *next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}

	free(*list);
	(*list) = NULL;
}

void push_front(LinkedList *list, int data)
{
	node *tmp = (node*) malloc(sizeof(node));
	assert(tmp != NULL);
	
	tmp->val = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
	{
		list->head->prev = tmp;
	}
	list->head = tmp;
	if (list->tail == NULL)
	{
		list->tail = tmp;
	}
	list->now_size++;
}

void delete_back_element(LinkedList *list)
{
	assert(list->tail != NULL);

	node * next;
	next = list->tail->prev;
	free(list->tail);
	list->tail = next;

	if(list->tail != NULL)
	{
		list->tail->next = NULL;
	}
	else
	{
		list->head = NULL;
	}
	list->now_size--;
}


void print_list(LinkedList* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int find_element(LinkedList* list, int value, const char* listName) {
    node* current = list->head;
    while (current != NULL) {
        if (current->val == value) {
            printf("Элемент %d найден в списке %s\n", value, listName);
            return 1;
        }
        current = current->next;
    }
    printf("Элемент %d не найден в списке %s\n", value, listName);
	return 0;
}



void delete_element(LinkedList* list, int value) {
    node* current = list->head;
    node* prev = NULL;
    while (current != NULL) {
        if (current->val == value) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
			list->now_size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("The element was not found\n");
}
