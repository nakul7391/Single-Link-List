#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "find.h"


status find_element(Slist_t *head, int key)
{
    // if there is no list
    if (head == NULL)
    return Failure;

    Slist_t *ptr = head;

    // find the element
    while ( ptr && ptr->data != key )
    ptr = ptr->next;

    // if data not found
    if ( ptr == NULL )
    return Failure;

    // else data is found
    return Success;
}

status find_element_recursive(Slist_t *head, int key)
{
    // exit condition
    if (head == NULL)
    return Failure;
    else
    {
        if (head->data == key)
        return Success;
        else
        find_element_recursive(head->next,key);
    }
}
