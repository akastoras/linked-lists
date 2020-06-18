#ifndef __LINKED_LISTS__H__
#define __LINKED_LISTS__H__ 1

// Structs

typedef struct node {
    char *string;
    void *data;
    struct node *next;
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

int insert_node_to_linked_list(linked_list *ll, node *new_node);
/* 
 * Adds a new node to a linked list.
 * return value: 0 -> success
 *               1 -> node is NULL
 */

int insert_to_linked_list(linked_list *ll, char *string, void *data);
/*
 * Create node and insert it to list
 * return value: 0 -> success
 *               1 -> existing string
 */

node *find_in_linked_list_previous(linked_list *ll, char *string);
//finds the node of the given string and returns pointer to the previous node. Else returns NULL

node *find_in_linked_list(linked_list *ll, char *string);
//finds the node of the given string and returns pointer to it. Else returns NULL

int delete_next_node(node *prev_node);
/*
 *Deletes the node after the given node
 *return value: 0 -> success
 *              1 -> not existing node
 */
int delete_from_linked_list(linked_list *ll, char *string);
/* 
 * Deletes a new node after old node.
 * return value: 0 -> success
 *               1 -> node is NULL
 */

void delete_linked_list(linked_list *ll);
//deletes linked list

void print_linked_list(linked_list *ll);
//prints all nodes (just the strings)

#endif  //!__LINKED_LISTS__H__