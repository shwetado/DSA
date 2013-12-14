typedef struct {
    void** elements;
    int top;
    int length;
} Stack;

typedef char String[256];

Stack* create(int length);
void** getElement(Stack* stack,int top);
int push(Stack* stack,void* element);
void* pop(Stack* stack);

void* top(Stack* stack);

int isEmpty(Stack* stack);
int isFull(Stack* stack);