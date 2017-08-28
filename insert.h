#ifndef INSERT_H
#define INSERT_H

// function to create a node of the link list
Slist_t* create_node(int data);

// function to insert data at head position of the list
status insert_at_first(Slist_t **head, Slist_t **tail, int data);

// function to insert data at last position of the list
status insert_at_last(Slist_t **head, Slist_t **tail, int data);

// function to insert data before a given key
status insert_before(Slist_t **head, Slist_t **tail, int data, int key);

// function to insert data after a given key
status insert_after(Slist_t **head, Slist_t **tail, int data, int key);

#endif
