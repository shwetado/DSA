typedef struct {
    void** elements;
    int top;
    int length;
} Stack;

Stack* create(int length);
void dispose();

int push(Stack* stack,void* element);
void* pop(Stack* stack);

void* top(Stack* stack);

int isEmpty(Stack* stack);