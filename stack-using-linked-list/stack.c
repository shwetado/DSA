#include "stack.h"
#include <stdlib.h>

Stack* createStack(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->list = create();
    return newStack;
};

int push(Stack* stack, void* element){
    return insert(stack->list, stack->list->length, element);
};

int pop(Stack* stack){
    return deleteNode(stack->list, stack->list->length - 1);
};

int isEmpty(Stack* stack){
    return 0 == stack->list->length;
};

void* top(Stack *stack){
    Node* head;
    if(isEmpty(stack))
        return NULL;
    head = stack->list->head;
    while(head->next!=NULL){
        head = head->next;
    }
    return head->data;
};

void dispose(Stack* stack){
    free(stack->list);
    free(stack);
}