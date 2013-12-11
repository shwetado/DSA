#include "linkedList.h"
#include <stdlib.h>

List* create(){
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;
	list->end = NULL;
	return list;
};

int insertFirst(List* list,Node* node,void* data){
	printf("insertFirst\n");	
	node->data = data;
	node->prev = list->head;
	list->head = node;
	list->length++;
	return 1;
};

int insertLast(List* list,Node* node,void* data){
	printf("insertLast\n");
	node->data = data;
	node->next = list->end;
	list->end = NULL;
	list->length++;
	return 1;
};

int insertBefore(List* list,int index,Node* node,void* data){
	printf("insertBefore\n");
	list->length++;
	return 1;
};

int insert(List* list,int index, void* data){
	int validIndex = index >= 0 && index <= list->length;
	int result;
	Node* node;
	if(!validIndex)
		return 0;
	node = calloc(1, sizeof(Node));
	if(index == 0)
		result = insertFirst(list, node, data);
	else if(index == list->length)
		result = insertLast(list, node ,data);
	else
		result = insertBefore(list, index, node, data);
	return result;
};