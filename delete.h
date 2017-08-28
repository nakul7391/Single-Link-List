#ifndef DELETE_H
#define DELETE_H

// function to delete first element of the link list
status delete_first(Slist_t **head, Slist_t **tail);

// function to delete last node of the link list
status delete_last(Slist_t **head, Slist_t **tail);

// function to delete node using key
status delete_element(Slist_t **head, Slist_t **tail ,int key);

#endif
