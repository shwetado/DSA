typedef char String[256];

typedef struct{
    int run;
    int wait;
    int end;
} Status;

typedef struct process{
    String pName;
    int pTime;
    Status pStatus;
    int priority;
    struct process *next;
} Process;

typedef struct{
    Process *front;
    int length;
} Schedular;

Schedular* create();
typedef int compareFunc(void* element1, void* element2);
int addProcess(Schedular *queue,Process *process,compareFunc* compare);        
int removeProcess(Schedular *queue);