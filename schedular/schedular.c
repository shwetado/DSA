#include "schedular.h"
#include "../linkedList/linkedList.h"
#include <stdlib.h>
#include <string.h>

Process* createProcess(String pName,int pTime,int priority){
	Process* newProcess = malloc(sizeof(Process));
	strcpy(newProcess -> pName , pName);
	newProcess -> pTime = pTime;
	newProcess -> priority = priority;
	return newProcess;
};