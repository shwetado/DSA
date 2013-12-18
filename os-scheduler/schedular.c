#include "schedular.h"
#include <stdlib.h>

Schedular* create(){
    Schedular *queue = calloc(sizeof(Schedular),1);
    return queue;
}

int addAtStart(Schedular *queue, Process *process){
    if(queue->front == NULL)
        process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return queue->length;        
};

int addProcess(Schedular *queue, Process *process,compareFunc* compare){
    Process *previous,*next,*temp;
    int i;
    temp = queue->front;
    if(queue->length == 0 || (compare(&process->priority,&temp->priority) < 0))                
        return addAtStart(queue, process);
    for(i = 0;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(process->priority < next->priority){
            previous->next = process;
            process->next = next;
            return ++queue->length;
        }
    };
    temp->next = process;
    process->next = NULL;
    return ++queue->length;
};

int removeProcess(Schedular *queue){
    Process *temp,*previous,*next;
    int i;
    temp = queue->front;
    if(queue->length == 1){
        if(temp->pTime == 0)
            queue->front = NULL;
        return --queue->length;
    }
    if(temp->pTime == 0)
        queue->front = temp->next;
    for(i = 0;temp->next != NULL;temp = temp->next){
        previous = temp;
        next = temp->next;
        if(next->pTime == 0){
            previous->next = next->next;
            return --queue->length;
        }
    }
    if(NULL == temp->next){
        previous->next = NULL;
        return --queue->length;
    };
    return 0;
};