#include <stdbool.h>
typedef struct{
    void *array;
    int top;
    int sizeOfElement;
    int maxElements;
} Stack;

typedef char String[256];

Stack* create(int sizeOfElement,int maxElements);

int isEmpty(Stack *stack);
int isFull(Stack *stack);

int push(Stack *stack,void *element);
void* pop(Stack *stack);

void* top(Stack *stack);