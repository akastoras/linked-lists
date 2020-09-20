/*A simple program demonstrating the usage of my linked list library
The data in this program is an int number*/

#include "linked_lists.h"
#include <stdio.h>

void help();

int main(int argc, char **argv)
{   
    if (argc > 1) {
        printf("Usage: %s\n", argv[0]);
        return 0;
    }
    linked_list *ll = init_linked_list();
    node *nd;
    char string[17] = {'\0'};
    char c = '\0';
    int num, res;

    help();

    while (c != 'q') {
        scanf(" %c", &c);

        switch (c){
        case 'a': {
            scanf("%16s %d", string, &num);

            res = insert_to_linked_list(ll, string, &num);
            if (res == 1) {
                printf("Existing string.\n");
            }
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
            scanf("%16s", string);

            res = delete_from_linked_list(ll, string);
            if (res == 1) {
                printf("Non existing node.\n");
            }
            break;
        }
        case 'c': {
            delete_linked_list(ll);
            ll = init_linked_list();
            break;
        }
        case 'p': {
            print_linked_list(ll);
            break;
        }
        case 'q': {
            delete_linked_list(ll);
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
    printf("\n* * * * * * * * * * * * * * * * * * * *\n");
    printf("* a <name> <num>: to add to list      *\n");
    printf("* f <name>: to find in list           *\n");
    printf("* d <name>: to delete from list       *\n");
    printf("* c: to clear list                    *\n");
    printf("* p: to print list                    *\n");
    printf("* q: to quit                          *\n");
    printf("* * * * * * * * * * * * * * * * * * * * \n");
}
