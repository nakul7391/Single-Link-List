#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utility.h"

status print_list(Slist_t *head)
{
    // if no list exists
    if (head == NULL)
    return Failure;

    Slist_t *ptr = head;

    while( ptr )
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
    return Success;
}

// return number of nodes in the link list
int get_nodes(Slist_t *head)
{
    // if there is no list
    if (head == NULL)
    return 0;

    // count the node
    int count = 0;
    Slist_t *ptr = head;
    while (ptr)
    {
        ptr = ptr->next;
        count++;
    }

    return count;
}

/*
5-> ##only one node
return 1 + 0;
5->10->15 ## three nodes
return 1 + 1 + 1 + 0;
*/
int get_nodes_recursive(Slist_t *head)
{
    if (head == NULL)
    return 0;
    else
    {
       return 1 + get_nodes_recursive(head->next);
    }
}
