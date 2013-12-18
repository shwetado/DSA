// #include "../linkedList/linkedList.h"

// typedef struct {
//     void* data;
//     int priority;
// } PQueue;

void* createPQueue();
int enQueue(void* pQueue,void* data, int priority);
int deQueue(void* pQueue);