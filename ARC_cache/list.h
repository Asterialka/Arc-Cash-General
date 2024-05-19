#ifndef DOUBLE_LIST
#define DOUBLE_LIST

typedef struct node node;
typedef struct LinkedList LinkedList;

struct node
{
	int val;
	node * next;
	node * prev;
};

struct LinkedList
{
	int size;
	int now_size;
	node * head;
	node * tail;
};

node* create_node();
LinkedList* List(int size);
int find_element(LinkedList* list, int value, char* listName);
void list_free(LinkedList **list);
void push_front(LinkedList *list, int data);
void delete_back_element(LinkedList *list);
void print_list(LinkedList* list);
void delete_element(LinkedList* list, int value);

#endif
