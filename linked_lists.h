/*
 *  The following Functions are used to implement a simple
 * linked list sorted by strings with pointers to
 * non preundefined data.
 * 
 * Code by: Athanasios Kastoras
 * Electrical and Computer Engineering | University of Thessaly
 */
#ifndef __LINKED_LISTS__H__
#define __LINKED_LISTS__H__ 1

/*   Structs   */

typedef struct node {
    char *string;
    void *data;
    struct node *next;
} node;

typedef struct linked_list {
    node *head;
    int size;
} linked_list;

/*   Functions   */

/*
 * Initialize new linked list, returns pointer to it. NULL for fail.
 */ 
linked_list *init_linked_list();

/*
 * create a node, set data pointer to struct data. NULL for fail.
 */
node *init_node(char *string, void *data);

/*
 * Adds new_node after old_node.
 */
void insert_after_node(node *old_node, node *new_node);

/* 
 * Adds a new node to a linked list.
 * return value: 0 -> success
 *               1 -> node is NULL
 */
int insert_node_to_linked_list(linked_list *ll, node *new_node);

/*
 * Create node and insert it to list
 * return value: 0 -> success
 *               1 -> existing string
 */
int insert_to_linked_list(linked_list *ll, char *string, void *data);

/*
 * Finds the node of the given string and returns pointer to the previous node.
 * Else returns NULL.
 */
node *find_in_linked_list_previous(linked_list *ll, char *string);

/*
 * Finds the node of the given string and returns pointer to it.
 * Else returns NULL.
 */
node *find_in_linked_list(linked_list *ll, char *string);

/*
 *Deletes the node after the given node
 *Return value: 0 -> success
 *              1 -> not existing node
 */
int delete_next_node(node *prev_node);

/* 
 * Deletes a new node after old node.
 * Return value: 0 -> success
 *               1 -> node is NULL
 */
int delete_from_linked_list(linked_list *ll, char *string);


/*
 * Deletes linked list.
 */
void delete_linked_list(linked_list *ll);

/*
 * Prints all nodes (just the strings).
 */
void print_linked_list(linked_list *ll);


#endif  //!__LINKED_LISTS__H__
