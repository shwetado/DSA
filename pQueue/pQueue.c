#include "pQueue.h"
#include <stdlib.h>
#include "customTypes.h"

void* createPQueue(){
	List* queue = create();
	return queue;
};

PQElement* createElement(void* data, int priority){
	PQElement* pQItem = calloc(1, sizeof(PQElement));
	pQItem->data = data;
	pQItem->priority = priority;
	return pQItem;
};

int enQueue(void* list, void* data, int priority){
	List* queue = list;
	PQElement* pQItem = createElement(data, priority);
	int index = 1;
	Node* head = queue->head;
	PQElement* head_data;
	if(NULL == queue->head)
        return insert(queue, 0, pQItem);
	head_data = head->data;
	if(head_data->priority > pQItem->priority)
        return insert(queue, 0, pQItem);
	while(head->next != NULL){
        head = head->next;
        head_data = head->data;
        if(head_data->priority > pQItem->priority)
            return insert(queue, index,pQItem);
        index++;
	}
	return insert(queue, index, pQItem);
};

int deQueue(void* list){
	List* queue = list;
	int result = deleteNode(queue, 0);
	return result;
};