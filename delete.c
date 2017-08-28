#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "delete.h"

status delete_first(Slist_t **head, Slist_t **tail)
{
    // if list doesnot exists return Failure
    if (*head == NULL)
    return Failure;

    // if list contains only one node then delete entire list
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return Success;
    }

    // delete node and update head
    Slist_t *ptr = *head;
    *head = ptr->next;
    free(ptr);
    return Success;
}

status delete_last(Slist_t **head, Slist_t **tail)
{
    // if there is no list we have nothing to delete
    if (*head == NULL)
    return Failure;

    // if head and tail are same that is only one element in the list
    if ( *head == *tail )
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return Success;
    }

    // find the node before last and update the tail
    Slist_t *prev = *head, *next = *head;

    // go till the end
    while (next->next != NULL)
    {
        prev = next;
        next = next->next;
    }

    // insert NULL at the end
    prev->next = NULL;
    *tail = prev;
    return Success;
}

status delete_element(Slist_t **head, Slist_t **tail ,int key)
{
    // if there is no list
    if ( *head == NULL )
    return Failure;

    // if only one node in the list and head contain the key delete list
    if ( *head == *tail && (*head)->data == key)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return Success;
    }

    // more than one element and head contain the element
    if ( (*head)->data == key )
    {
        delete_first(head, tail);
        return Success;
    }

    // if tail contain the element
    if ( (*tail)->data == key )
    {
        delete_last(head, tail);
        return Success;
    }

    // find the element
    Slist_t *prev = *head, *next = *head;
    while( next && next->data != key )
    {
        prev = next;
        next = next->next;
    }

    // key not found
    if ( next == NULL )
    return Failure;

    // join the links
    prev->next = next->next;

    // free node
    free(next);
    return Success;
}
