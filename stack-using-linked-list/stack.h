#include "../linked-list/linkedList.h"

typedef struct{
    List* list;
}Stack;

Stack* createStack();

int push(Stack* stack, void* element);
int pop(Stack* stack);

int isEmpty(Stack* stack);

void* top(Stack* stack);

void dispose(Stack* stack);