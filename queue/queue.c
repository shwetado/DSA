#include "queue.h"
#include <stdlib.h>
#include <string.h>

Queue* create(int typeSize, int capacity){
    Queue* Q = (Queue*)calloc(1,sizeof(Queue));
    Q->elements = calloc(capacity,typeSize);
    Q->typeSize = typeSize;
    Q->capacity = capacity;
    Q->front = 0;
    Q->rear = -1;
    return Q;
};

int isFull(Queue* queue){
    return (queue->rear+1 == queue->capacity);
};

int enqueue(Queue *queue,void* element){
	void* offset = queue->elements+(++queue->rear)*(queue->typeSize);
	if(isFull(queue))
		return 0;
    if(queue->rear == queue->capacity)
        queue->rear = 0;
    memcpy(offset,element,queue->typeSize);
    return 1;
};

int isEmpty(Queue* queue){
	return ((queue->rear) == -1);
};

void* dequeue(Queue *queue){
	void* element = malloc(queue->typeSize);
	void* nxtElement = queue->elements+queue->typeSize;
	if(isEmpty(queue))	return NULL;
	memcpy(element, queue->elements, queue->typeSize);
	memmove(queue->elements, nxtElement, queue->capacity-1);
	queue->rear--;
    return element;
};