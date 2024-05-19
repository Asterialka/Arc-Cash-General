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

LinkedList* init_List(int size)
{
	LinkedList *list = NULL;
	list = (LinkedList*) malloc((sizeof(LinkedList)));
	list->size = size;
	list->now_size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void list_free(LinkedList *list)
{
  if (list) {
	  
	  if ((list)->head) {
	    node *tmp = (list)->head;
	    node *next = NULL;
	    while (tmp)
	    {
		    next = tmp->next;
		    free(tmp);
		    tmp = next;
	    }
	 
	  }
    free(list);
    (list) = NULL;
  }

}
void pushFront(LinkedList *list, int data)
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

void popBack(LinkedList *list)
{
	assert(list->tail != NULL);
	node * next = list->tail->prev;
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

node *find_element(LinkedList* list, long long int value) {
    node* current = list->head;
    while (current != NULL) {
        if (current->val == value) {
            //printf("Элемент %d найден в списке \n", value);
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void delete_by_point(node *point, LinkedList *list) {
 if (point == NULL) {
  return;
  }
  else {
  
    if (point->prev == NULL && point->next == NULL) {
      list->head = list->tail = NULL;
      free(point);

      point = NULL;
      list->now_size--;
      return ;
    }
    if (point->prev == NULL) {
      list->head = point->next;
      point->next->prev = NULL;
      free(point);
      list->now_size--;
      return;
    
    }
    if (point->next == NULL) {
      point->prev->next = NULL;
      free(point);
     
      point = NULL;
      list->now_size--;
      return;
  
    }
      point->prev->next = point->next;
      point->next->prev = point->prev;
      point->val = 0;
      free(point);
      point = NULL;
      list->now_size--;
    return ;
  
  }
}

void delete_element(LinkedList* list, int value)
{
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
