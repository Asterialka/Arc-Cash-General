#ifndef HASH_TABLE
#define HASH_TABLE


typedef struct hashnode hashnode;
typedef struct Hash Hash;

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

struct hashnode
{
    int value;
    node *point;
    hashnode *next;
    hashnode *prev;
};

struct Hash
{
    int capacity;
    hashnode **array;
};

// create hashnode
hashnode* create_hashnode(int value, node *point, hashnode *prev);
// create array
hashnode **init_array(int capacity);
// create hashtable
Hash* create_HASH_TABLE(int capacity);
// add node to hash
Hash* hashTableAdd(Hash *table, node *point, int value);
// search for element in hashtable
hashnode* find_element_in_hash(Hash *hash, int page);
// hash function
int hash_function(int value, Hash *table);
// free the hash branch
void free_the_branch(hashnode *tmp);
// free hash table
void free_HASH(Hash *hash);
// delete element from hash table
void hash_delete_elem(int page, Hash *s);

#endif
