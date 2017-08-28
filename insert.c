#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "insert.h"

Slist_t* create_node(int data)
{
    Slist_t *new = malloc(sizeof(Slist_t));

    // Heap is out of memory
    if ( new == NULL )
    return NULL;

    new->data = data;
    new->next = NULL;

    return new;
}

status insert_at_first(Slist_t **head, Slist_t **tail, int data)
{
    // list doesnot exists create first node
    if( *head == NULL )
    {
        Slist_t *new = create_node(data);
        if (new == NULL)
        return Failure;
        *head = new;
        *tail = new;
        return Success;
    }

    // update head of the list
    Slist_t *new = create_node(data);
    if (new == NULL)
    return Failure;

    new->next = *head;
    *head = new;
    return Success;
}

status insert_at_last(Slist_t **head, Slist_t **tail, int data)
{
    // if list doesnot exists create first node and update head and tail
    if( *head == NULL )
    {
        Slist_t *new = create_node(data);
        if (new == NULL)
        return Failure;

        *head = new;
        *tail = new;
        return Success;
    }

    // create a node
    Slist_t *new = create_node(data);
    if (new == NULL)
    return Failure;

    // update tail
    (*tail)->next = new;
    *tail = new;
    return Success;
}

status insert_before(Slist_t **head, Slist_t **tail, int data, int key)
{
      // list doesnot exists then return failure
      if (*head == NULL)
      return Failure;

      // if head contain the key
      if ((*head)->data == key)
      {
          insert_at_first(head, tail, data);
          return Success;
      }

      // list exists and head and tail doesnot contain the data then find the key
      Slist_t *prev = *head, *next = *head;

      /* prev will hold the address of previous node
         loop will stop if the data if found or NULL is reached
      -------         ----------
      data| next----> data| next---->
      -------         ----------
      prev pointer     next pointer */
      while ( next && next->data != key )
      {
          prev = next;
          next = next->next;
      }

      // either the key is found or NULL is reached check if NULL is reached then no insertion return Failure
      if (next == NULL)
      return Failure;

      // key is found create node and make links
      Slist_t *new = create_node(data);

      prev->next = new;
      new->next = next;
      return Success;
}

status insert_after(Slist_t **head, Slist_t **tail, int data, int key)
{
      // list doesnot exists then return failure
      if (*head == NULL)
      return Failure;

      // if tail contain the key
      if ((*tail)->data == key)
      {
          insert_at_last(head, tail, data);
          return Success;
      }

      // list exists and head and tail doesnot contain the data then find the key
      Slist_t *ptr = *head;

      /* prev will hold the address of previous node
         loop will stop if the data if found or NULL is reached */
      while ( ptr && ptr->data != key )
      {
          ptr = ptr->next;
      }

      // if key is not found return Failure
      if (ptr == NULL)
      return Failure;

      // key is found create node and make links
      Slist_t *new = create_node(data);
      new->next = ptr->next;
      ptr->next = new;
      return Success;
}
