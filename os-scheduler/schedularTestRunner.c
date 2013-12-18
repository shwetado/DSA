#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_creates_a_new_process_in_schedular");
	setup();
		test_creates_a_new_process_in_schedular();
	tearDown();
	testEnded();
	testStarted("test_adds_front_process");
	setup();
		test_adds_front_process();
	tearDown();
	testEnded();
	testStarted("test_adds_process_that_have_high_priority_rather_than_first");
	setup();
		test_adds_process_that_have_high_priority_rather_than_first();
	tearDown();
	testEnded();
	testStarted("test_adds_process_with_priority_in_between_process_queue");
	setup();
		test_adds_process_with_priority_in_between_process_queue();
	tearDown();
	testEnded();
	testStarted("test_adds_process_with_lowest_priority");
	setup();
		test_adds_process_with_lowest_priority();
	tearDown();
	testEnded();
	testStarted("test_removes_the_only_process_in_schedular");
	setup();
		test_removes_the_only_process_in_schedular();
	tearDown();
	testEnded();
	testStarted("test_removes_the_middle_process_from_the_schedular");
	setup();
		test_removes_the_middle_process_from_the_schedular();
	tearDown();
	testEnded();
	testStarted("test_removes_the_last_process_from_the_schedular");
	setup();
		test_removes_the_last_process_from_the_schedular();
	tearDown();
	testEnded();
	testStarted("test_removes_the_first_process_from_the_schedular");
	setup();
		test_removes_the_first_process_from_the_schedular();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
