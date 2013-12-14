#include "stack.h"
#include <stdlib.h>
#include <memory.h>

Stack* create(int length){
    Stack* stack = calloc(sizeof(Stack), 1);
    stack->elements = calloc(sizeof(void*), length);
    stack->top = 0;
    stack->length = length;
    return stack;
};

int isFull(Stack* stack){
    return stack->top == stack->length;
};

void** getElement(Stack* stack,int top){
    return stack->elements + top * sizeof(stack->elements);
};

int push(Stack* stack,void* element){
    void* temp;
    if(isFull(stack)){
        temp = realloc(stack->elements, stack->length * 2 * sizeof(void*));
        if(!temp)
            return 0;
        stack->elements = temp;
        stack->length *= 2;
    }
    *(getElement(stack, stack->top++)) = element;
    return 1;
};

int isEmpty(Stack* stack){
    return stack->top == 0;
};

void* pop(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return *(getElement(stack,--(stack->top)));
};

void* top(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return *(getElement(stack, (stack->top-1)));
};