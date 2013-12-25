// #include "iterator.h"

typedef struct Node{
	void* data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct {
	struct Node* head;
	int length;
} List;

typedef char String[256]; // should not be here

List* create();
Node* createNode(Node *prev, Node *next);
int insert(List* list,int index, void* data);
int deleteNode(List* list,int index);
// Iterator getIterator(DoubleList dList);