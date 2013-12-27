#include "linkedList.h"

typedef struct {
	Node* current;
	List* list;
} Iterator;

void* next(Iterator* it);

int hasNext(Iterator* it);