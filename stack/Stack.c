#include "stack.h"
#include <stdlib.h>
#include <memory.h>

void dispose(Stack* pStack){
    free(pStack->elements);
    free(pStack);
};

Stack* create(int length){
    Stack* pStack = calloc(1,sizeof(Stack));
    pStack->elements = calloc(length,sizeof(void*));
    pStack->top = 0;
    pStack->length = length;
    return pStack;
};

int isFull(Stack* pStack){
    return pStack->top == pStack->length;
};

int push(Stack* pStack,void* element){
    if(isFull(pStack)){
        pStack->length *= 2;
        pStack->elements = realloc(pStack->elements, pStack->length * sizeof(void*));
    }
    *(pStack->elements+pStack->top++) = element;
    return 1;
};

int isEmpty(Stack* pStack){
    return pStack->top == 0;
};

void* top(Stack* pStack){
    void* topElement;
    if(isEmpty(pStack))     return NULL;
    topElement = *(pStack->elements+pStack->top-1);
    return topElement;
};

void* pop(Stack* pStack){
    void *element;
    element = top(pStack);
    if(isEmpty(pStack))     return NULL;
    --(pStack->top);
    return element;
};
