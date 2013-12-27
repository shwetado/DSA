#include "arrayList.h"
#include <stdlib.h>

ArrayList createArrList(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
};

void shiftRight(ArrayList *list, int index) {
	int i;
	if (index < list->length)
		for (i = list->length - 1; i >= index; i--)
			list->base[i+1] = list->base[i];
};

int isFull(ArrayList *list) {
	return list->length == list->capacity;
};

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
};

int insertToList(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;
	increaseCapacity(list);
	shiftRight(list, index);
	list->base[index] = data;
	list->length++;
	return 1;
};

int add(ArrayList *list, void* data){
	if(data == NULL) return 0;
	insertToList(list, list->length, data);
	return 1;
};

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
};

void dispose(ArrayList *list) {
	free(list->base);
};

int search(ArrayList *list, void* dataToSearch, compare* cmp){
	int i;
	for(i = 0; i < list->length; i++)
		if(0 == cmp(list->base[i],dataToSearch))
			return 1;
	return 0;
};

void shiftLeft(ArrayList *list, int index) {
	int i;
    if (index < list->length-1) 
        for (i = index; i < list->length; i++) 
            list->base[i] = list->base[i+1];
};

int removeFromList(ArrayList *list, int index){
	if(index < 0 || index >= list->length) return 0;
    shiftLeft(list, index);
    list->length--;
    return 1;
};


Iterator getArrayIterator(ArrayList* list){
    Iterator it;
    it.list = list;
    it.position = 0;
    return it;
}

void iterate(ArrayList list, ForEach* forEach){
    int index;
    for(index = 0;index < list.length ;index++)
        forEach(list.base[index]);
}