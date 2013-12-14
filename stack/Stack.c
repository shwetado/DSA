#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack* create(int sizeOfElement,int maxElements){
    Stack *temp = calloc(sizeof(Stack),1);
    temp->array = calloc(maxElements,sizeOfElement);
    temp->sizeOfElement = sizeOfElement;
    temp->maxElements = maxElements;
    temp->top = -1;
    return temp;
};

int push(Stack *stack,void *element){
    void* newElement;
    if(isFull(stack))        
    	return 0;
    newElement = stack->array+((stack->top+1)*stack->sizeOfElement);
    memcpy (newElement, element, stack->sizeOfElement);
    stack->top++;
    return 1;
};

void* pop(Stack *stack){
    void* element;
    if(isEmpty(stack))        
    	return NULL;
    element = stack->array+(stack->top*stack->sizeOfElement);
    stack->top--;
    return element;
};

void* top(Stack *stack){
    void* element = stack->array+(stack->top*stack->sizeOfElement);
    return element;
};

int isEmpty(Stack *stack){
    if(stack->top==-1)        
    	return true;
    return false; 
};

int isFull(Stack *stack){
    if(stack->top==stack->maxElements-1)        
    	return true;
    return false; 
}