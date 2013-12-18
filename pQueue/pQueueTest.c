#include <stdlib.h>
#include "testUtils.h"
#include "pQueue.h"
#include "customTypes.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_inserts_the_element_at_the_starting_of_queue(){
	void* pQueue = createPQueue();
	int data = 40;
	ASSERT(1 == enQueue(pQueue, &data, 5));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_lower_priority_int(){
	void* pQueue = createPQueue();
	int data1 = 10 , data2 = 20;
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_higher_priority_int(){
	void* pQueue = createPQueue();
	int data1 = 10 , data2 = 20;
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_higher_priority_float(){
	void* pQueue = createPQueue();
	float data1 = 10.0f , data2 = 20.0f;
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_lower_priority_float(){
	void* pQueue = createPQueue();
	float data1 = 10.0f , data2 = 20.0f;
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_higher_priority_double(){
	void* pQueue = createPQueue();
	double data1 = 10.0 , data2 = 20.0;
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_lower_priority_double(){
	void* pQueue = createPQueue();
	double data1 = 10.0 , data2 = 20.0;
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_higher_priority_char(){
	void* pQueue = createPQueue();
	char data1 = 'a' , data2 = 'b';
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_lower_priority_char(){
	void* pQueue = createPQueue();
	char data1 = 'a' , data2 = 'b';
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_higher_priority_String(){
	void* pQueue = createPQueue();
	String data1 = "a" , data2 = "b";
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};

void test_inserts_the_element_first_having_lower_priority_String(){
	void* pQueue = createPQueue();
	String data1 = "a" , data2 = "b";
	ASSERT(1 == enQueue(pQueue, &data1, 1));
	ASSERT(1 == enQueue(pQueue, &data2, 2));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(1 == deQueue(pQueue));
	ASSERT(0 == deQueue(pQueue));
};
