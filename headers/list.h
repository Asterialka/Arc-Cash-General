#ifndef DOUBLE_LIST
#define DOUBLE_LIST

typedef struct LinkedList LinkedList;

#ifndef CURSED_NODE
#define CURSED_NODE
typedef struct node node;
struct node
{
    int val;
    node * next;
    node * prev;
};
#endif


struct LinkedList
{
	int size;
	int now_size;
	node * head;
	node * tail;
};

node* create_node();
LinkedList* List(int size);
node* find_element(LinkedList* list, long long value);
void list_free(LinkedList *list);
void pushFront(LinkedList *list, int data);
void delete_by_point(node *point, LinkedList *list);
void delete_back_element(LinkedList *list);
void print_list(LinkedList* list);
void delete_element(LinkedList* list, int value);
void popBack(LinkedList *list);
LinkedList* init_List(int size);

#endif
