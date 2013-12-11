#include "testUtils.h"
#include "schedular.h"
#include "../linkedList/linkedList.h"
#include <String.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_creates_a_process(){
	String pName = "browser";
	int pTime = 100;	int priority = 1;
	Process* browser = createProcess(pName,pTime,priority);
	ASSERT(0 == strcmp(browser->pName , pName));
	ASSERT(browser->pTime == pTime);
	ASSERT(browser->priority == priority);
};