/*Implementation of single link list */
#include <stdio.h>
#include "constants.h"
#include "insert.h"
#include "delete.h"
#include "utility.h"

int main(int argc, char *argv[] )
{
		Slist_t *head = NULL, *tail = NULL; 		// pointer to hold head and tail of list
		delete_first(&head, &tail);
		insert_at_last(&head, &tail, 5);
		print_list(head);
		delete_last(&head, &tail);
		print_list(head);
		delete_first(&head, &tail);
		print_list(head);
		insert_at_last(&head, &tail, 10);
		insert_at_last(&head, &tail, 15);
		insert_at_last(&head, &tail, 20);
		insert_at_last(&head, &tail, 19);
		insert_at_last(&head, &tail, 25);
		print_list(head);
		printf("count %d\n",get_nodes_recursive(head));
		return 0;
}
