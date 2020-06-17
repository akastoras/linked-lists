/*A simple program demonstrating the usage of my linked list library
The data in this program is an int number*/

#include "linked_lists.h"
#include <stdio.h>


void help();

int main(void)
{
    linked_list *ll = init_linked_list();
    node *nd;
    char string[17] = {'\0'};
    char c = '\0';
    int num;

    help();

    while (c != 'q') {
        scanf(" %c", &c);

        switch (c){
        case 'a': {
            scanf("%16s %d", string, &num);

            insert_to_linked_list(ll, string, &num);
            break;
        }
        case 'f': {
            scanf("%16s", string);

            nd = find_in_linked_list(ll, string);
            if (nd == NULL) {
                printf("Not Found.\n");
            }
            else {
                printf("%s %d\n", nd->string, *((int *)nd->data));
            }
            break;
        }
        case 'd': {
            break;
        }
        case 'c': {
            break;
        }
        case 'p': {
            print_linked_list(ll);
            break;
        }
        case 'q': {
            return 0;
            break;
        }
        default:
            help();
            break;
        }

    }
}

void help()
{
    printf("\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
    printf("a <name> <num>: to add to list\n");
    printf("f <name>: to find in list\n");
    printf("d <name>: to delete from list\n");
    printf("c: to clear list\n");
    printf("p: to print list\n");
    printf("q: to quit\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n\n");
}