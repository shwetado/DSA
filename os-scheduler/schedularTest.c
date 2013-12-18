#include "testUtils.h"
#include "schedular.h"
#include <stdio.h>

void test_creates_a_new_process_in_schedular(){
    Schedular expected = {NULL,0};
    Schedular* pSchedular = create();
    ASSERT(pSchedular -> length == expected.length);
    ASSERT(pSchedular -> front == expected.front);
};

int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
};

void test_adds_front_process(){
    Schedular expected = {NULL,0};
    Status status = {0,1,0};
    Process sublime = {"sublime",3000,status,10,NULL};
    Schedular* pSchedular = create();
    ASSERT(1 == addProcess(pSchedular, &sublime,compareInt));
    ASSERT(pSchedular -> front == &sublime);
    ASSERT(pSchedular -> front->next == NULL);
};

void test_adds_process_that_have_high_priority_rather_than_first(){
    Schedular expected = {NULL,0};
    Status status = {0,1,0};
    Process sublime = {"sublime",3000,status,7,NULL};
    Process browser = {"browser",900,status,1,NULL};
    Schedular* pSchedular = create();
    ASSERT(1 == addProcess(pSchedular, &sublime,compareInt));
    ASSERT(2 == addProcess(pSchedular, &browser,compareInt));
    ASSERT(pSchedular -> front == &browser);
    ASSERT(pSchedular -> front->next == &sublime);
};

void test_adds_process_with_priority_in_between_process_queue(){
    Schedular expected = {NULL,0};
    Status status = {0,1,0};
    Process *_2,*_3;
    Process sublime = {"sublime",3000,status,7,NULL};
    Process browser = {"browser",900,status,1,NULL};
    Process paint = {"paint",400,status,2,NULL};
    Schedular* pSchedular = create();
    ASSERT(1 == addProcess(pSchedular, &sublime,compareInt));
    ASSERT(2 == addProcess(pSchedular, &browser,compareInt));
    ASSERT(3 == addProcess(pSchedular, &paint,compareInt));
    ASSERT(pSchedular -> front == &browser);
    _2 = pSchedular -> front->next;
    _3 = _2->next;
    ASSERT(_2 == &paint);
    ASSERT(_3 == &sublime);
    ASSERT(_3->next == NULL);
};

void test_adds_process_with_lowest_priority(){
    Status status = {0,1,0};
    Process *_2,*_3,*_4,*_5;
    Process browser = {"browser",1000,status,5,NULL};
    Process paint = {"paint",500,status,1,NULL};
    Process taskManager = {"taskManager",400,status,3,NULL};
    Process sublime = {"sublime",400,status,2,NULL};
    Process git = {"git",400,status,8,NULL};
    Schedular* pSchedular = create();
    ASSERT(1 == addProcess(pSchedular, &browser,compareInt));
    ASSERT(2 == addProcess(pSchedular, &paint,compareInt));
    ASSERT(3 == addProcess(pSchedular, &taskManager,compareInt));
    ASSERT(4 == addProcess(pSchedular, &sublime,compareInt));
    ASSERT(5 == addProcess(pSchedular, &git,compareInt));
    _2 = pSchedular -> front->next;
    _3 = _2->next;    _4 = _3->next;
    _5 = _4->next;
    ASSERT(_5 == &git);
    ASSERT(NULL == _5->next);
};

void test_removes_the_only_process_in_schedular(){
    Status status = {0,1,0};
    Process browser = {"browser",0,status,5,NULL};
    Schedular* pSchedular = create();
    addProcess(pSchedular, &browser,compareInt);
    ASSERT(0 == removeProcess(pSchedular));
    ASSERT(NULL == pSchedular -> front);
};

void test_removes_the_middle_process_from_the_schedular(){
    Status status = {0,1,0};
    Process browser = {"browser",1000,status,1,NULL};
    Process paint = {"paint",0,status,5,NULL};
    Process taskManager = {"taskManager",1000,status,7,NULL};
    Schedular* pSchedular = create();
    addProcess(pSchedular, &browser,compareInt);
    addProcess(pSchedular, &paint,compareInt);
    addProcess(pSchedular, &taskManager,compareInt);
    ASSERT(2 == removeProcess(pSchedular));
    ASSERT(pSchedular -> front->next == &taskManager);
};

void test_removes_the_last_process_from_the_schedular(){
    Status status = {0,1,0};
    Process browser = {"browser",1000,status,1,NULL};
    Process paint = {"paint",10,status,5,NULL};
    Process taskManager = {"taskManager",0,status,7,NULL};
    Schedular* pSchedular = create();
    addProcess(pSchedular, &browser,compareInt);
    addProcess(pSchedular, &paint,compareInt);
    addProcess(pSchedular, &taskManager,compareInt);
    ASSERT(2 == removeProcess(pSchedular));
    ASSERT(pSchedular -> front->next->next == NULL);
};

void test_removes_the_first_process_from_the_schedular(){
    Status status = {0,1,0};
    Process browser = {"browser",0,status,1,NULL};
    Process paint = {"paint",10,status,5,NULL};
    Process taskManager = {"taskManager",65,status,7,NULL};
    Schedular* pSchedular = create();
    addProcess(pSchedular, &browser,compareInt);
    addProcess(pSchedular, &paint,compareInt);
    addProcess(pSchedular, &taskManager,compareInt);
    ASSERT(2 == removeProcess(pSchedular));
    ASSERT(pSchedular -> front == &paint);
};