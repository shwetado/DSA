// #include "/linked-list/linkedList.h"
#ifndef _ITERATOR_
#define _ITERATOR_
typedef struct Iterator{
	void* current;
	void* list;
	void* (*next)(struct Iterator* it);
	int (*hasNext)(struct Iterator* it);
	int position;
} Iterator;
#endif
