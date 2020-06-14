#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_lists.h"


linked_list *init_linked_list()
{
    //allocate memory for the linked list struct
    linked_list *ll;
    do {    
        ll = (linked_list *)malloc(sizeof(linked_list));
    } while (ll == NULL);

    //initialize size to zero
    ll->size = 0;

    //allocate memory for the head node
    do {    
        ll->head = (node *)malloc(sizeof(node));
    } while(ll->head == NULL);

    //initialize head node
    ll->head->data = NULL;  
    ll->head->string = NULL;
    ll->head->next = NULL;

    return ll;
}

node *init_node(char *string, void *data)
{
    //allocate memory for the new node
    node *nd;
    do {
        nd = (node *)malloc(sizeof(node));
    } while(nd == NULL);

    //initialize node
    do {
        nd->string = malloc(strlen(string) * sizeof(char));
    } while(nd->string == NULL);

    char *res = strcpy(nd->string, string);
    if (res != nd->string) { fprintf(stderr, "linked_lists.c/init_node/strcpy() unexpected return value.\n"); exit(1); }

    nd->data = (typeof(data))data;
    nd->next = NULL;    

    return nd;
}

void insert_after_node(node *old_node, node *new_node)
{
    //set new node's next pointer to the old node's, and
    new_node->next = old_node->next;
    //set the old node's to point at the new node
    old_node->next = new_node;
}

int insert_to_linked_list(linked_list *linked_list, node *new_node)
{
    if (new_node == NULL) {
        return 1;
    }

    node *ptr;

    //find the last node with lower value than the new node
    for (ptr = linked_list->head; ptr->next != NULL && strcmp(ptr->next->string, new_node->string) > 0; ptr = ptr->next);
    
    //add the new node afther the node we found
    insert_after_node(ptr, new_node);
    
    return 0;
}

node *find_in_linked_list_previous(linked_list *linked_list, char *string)
{
    node *ptr;

    for (ptr = linked_list->head; ptr->next != NULL && strcmp(ptr->next->string, string) != 0; ptr = ptr->next);

    if (ptr->next == NULL) {
        return NULL;
    }
    else {
        return ptr;
    }
}

node *find_in_linked_list(linked_list *linked_list, char *string)
{
    node *ptr = find_in_linked_list_previous(linked_list, string);

    if (ptr == NULL) {
        return NULL;
    }
    else {
        return ptr->next;
    }
}

int delete_next_node(node *prev_node)
{
    if (prev_node->next) {
        return 1;
    }

    //change the pointers
    node *ptr = prev_node->next;
    prev_node->next = ptr->next;
    
    //free memory
    free(ptr);

    return 0;
}

int delete_from_linked_list(linked_list *linked_list, char *string)
{
    //fing previous node
    node *prev_node = find_in_linked_list_previous(linked_list, string);

    if (prev_node == NULL) {
        return 1;
    }

    int res = delete_next_node(prev_node);

    if (res == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

void delete_linked_list(linked_list *linked_list)
{
    node *ptr;

    for (ptr = linked_list->head; ptr != NULL; ptr = ptr->next) {
        free(ptr);
    }

    free(linked_list);
    linked_list = NULL;
}

void print_linked_list(linked_list *linkedlist)
{
    node *ptr;

    printf("##");
    for (ptr = linkedlist->head; ptr->next != NULL; ptr = ptr->next) {
        printf("%s\n", ptr->next->string);
    }
}

