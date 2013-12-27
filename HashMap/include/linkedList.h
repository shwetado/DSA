#include "../../iterator.h"

#ifndef _NODE_
#define _NODE_
typedef struct Node{
	void* data;
	struct Node* prev;
	struct Node* next;
} Node;
#endif

#ifndef _LIST_
#define _LIST_
typedef struct {
	struct Node* head;
	int length;
} List;
#endif

typedef char String[256];

List* create();
Node* createNode(Node *prev, Node *next);
int insert(List* list,int index, void* data);
int deleteNode(List* list,int index);
Iterator getIterator(List* dList);
int length(List* dList);