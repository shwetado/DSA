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

	testStarted("test_insert_first_node");
	setup();
		test_insert_first_node();
	tearDown();
	testEnded();
	testStarted("test_insert_two_nodes_one_root_and_a_child");
	setup();
		test_insert_two_nodes_one_root_and_a_child();
	tearDown();
	testEnded();
	testStarted("test_insert_three_nodes");
	setup();
		test_insert_three_nodes();
	tearDown();
	testEnded();
	testStarted("test_insert_node_at_depth_two");
	setup();
		test_insert_node_at_depth_two();
	tearDown();
	testEnded();
	testStarted("test_search_root_node");
	setup();
		test_search_root_node();
	tearDown();
	testEnded();
	testStarted("test_search_nodes_depth_one");
	setup();
		test_search_nodes_depth_one();
	tearDown();
	testEnded();
	testStarted("test_search_at_depth_two");
	setup();
		test_search_at_depth_two();
	tearDown();
	testEnded();
	testStarted("test_delete_a_node_from_tree");
	setup();
		test_delete_a_node_from_tree();
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
