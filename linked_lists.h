#ifndef __LINKED_LISTS__H__
#define __LINKED_LISTS__H__ 1

// Structs

typedef struct node {
    char *string;
    void *data;
    node *next;
} node;

typedef struct linked_list {
    node *head; //head.string = NULL and head.data = NULL
    int size;
} linked_list;

// Functions

linked_list *init_linked_list();
//initialize new linked list, returns pointer to it. NULL for fail.
    
node *init_node(char *string, void *data);
//create a node, set data pointer to struct data. NULL for fail.

void insert_after_node(node *old_node, node *new_node);
//Adds new_node after old_node.

int insert_to_linked_list(linked_list *linked_list, node *new_node);
/* 
 * Adds a new node to a linked list.
 * return value: 0 -> success
 *               1 -> node is NULL
 */

node *find_in_linked_list_previous(linked_list *linked_list, char *string);
//finds the node of the given string and returns pointer to the previous node. Else returns NULL

node *find_in_linked_list(linked_list *linked_list, char *string);
//finds the node of the given string and returns pointer to it. Else returns NULL

int delete_from_linked_list(linked_list *linked_list, node *node);
/* 
 * Adds a new node after old node.
 * return value: 0 -> success
 *               1 -> node is NULL
 *               2 -> uninitialized list
 *              -1 -> fail
 */

void delete_linked_list(linked_list *linked_list);
//deletes linked list

void print_linked_list(linked_list *linkedlist);
//prints all nodes (just the strings)

#endif  //!__LINKED_LISTS__H__