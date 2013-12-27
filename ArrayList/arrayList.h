#include "iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (compare) (void* element1,void* element2);
typedef void ForEach(void* data);

ArrayList createArrList(int capacity);

int add(ArrayList *list, void* data);
int insertToList(ArrayList *list, int index, void* data);
int removeFromList(ArrayList *list, int index);

void* get(ArrayList *list, int index);

int search(ArrayList *list, void* dataToSearch, compare* cmp);

void dispose(ArrayList *list);

Iterator getArrayIterator(ArrayList* list);
void iterate(ArrayList list, ForEach* forEach);