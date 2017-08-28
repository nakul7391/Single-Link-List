#ifndef CONSTANTS_H
#define CONSTANTS_H
/*  prototype for link list
 ------------      -------------
 | data | next---> | data | next----->
 ------------			 ------------- */
typedef struct Slist {
		int data;
		struct Slist *next;
} Slist_t;

// return status
typedef enum {
	Failure,
	Success
} status;


#endif
