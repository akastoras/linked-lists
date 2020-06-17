/*A simple program demonstrating the usage of my linked list library
The data in this program is an int number*/

#include "linked_lists.h"
#include <stdio.h>

int main(void) {
    help();

    linked_list *init_linked_list();

    char c = '\0';

    while (c != 'q') {
        scanf("%c", c);

        switch (c){
        case 'a': {
            break;
        }
        case 'f': {
            break;
        }
        case 'd': {
            break;
        }
        case 'c': {
            break;
        }
        case 'p': {
            break;
        }
        case 'q': {
            break;
        }
        default:
            help();
            continue;
        }

    }
}

void help() {
    printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("a <name> <num>: to add to list\n");
    printf("f <name>: to find in list\n");
    printf("d <name>: to delete from list\n");
    printf("c: to clear list\n");
    printf("p: to print list\n");
    printf("q: to quit\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n");
}