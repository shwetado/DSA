#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack* create(int sizeOfElement,int maxElements){
    Stack *stack = calloc(sizeof(Stack),1);
    stack->base = calloc(maxElements,sizeOfElement);
    stack->sizeOfElement = sizeOfElement;
    stack->maxElements = maxElements;
    stack->top = -1;
    return stack;
};

int push(Stack *stack,void *element){
    void* newElement;
    if(isFull(stack))        
    	return 0;
    newElement = stack->base+((stack->top+1)*stack->sizeOfElement);
    memcpy (newElement, element, stack->sizeOfElement);
    stack->top++;
    return 1;
};

void* pop(Stack *stack){
    void* element;
    if(isEmpty(stack))        
    	return NULL;
    element = stack->base+(stack->top*stack->sizeOfElement);
    stack->top--;
    return element;
};

void* top(Stack *stack){
    void* element = stack->base+(stack->top*stack->sizeOfElement);
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