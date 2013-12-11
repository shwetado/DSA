#include "testUtils.h"
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(List* actual,List* expected){
	int resHead,resPrev,resNext;
	resHead = memcmp(actual->head->data,expected->head->data,sizeof(List));
	resPrev = memcmp(actual->head->prev,expected->head->prev,sizeof(List));
	resNext = memcmp(actual->head->next,expected->head->next,sizeof(List));
	return 0 == resHead && resPrev && resNext;
};

void test_creates_a_list_containing_head_of_length_0_and_pointing_to_null(){
	List* list = create();
	ASSERT(list->head == NULL);
	ASSERT(list->length == 0);
};

void test_inserts_a_node_at_first_place_into_the_list_for_integers(){
	List* list = create();
	int result;
	int element = 40;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->length == 1);
	ASSERT(NULL == list->head->next);
	ASSERT(NULL == list->head->prev);
	ASSERT(&element == list->head->data);
};

void test_inserts_a_node_at_first_place_into_the_list_for_floats(){
	List* list = create();
	int result;
	float element = 40.0f;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->length == 1);
	ASSERT(NULL == list->head->next);
	ASSERT(NULL == list->head->prev);
	ASSERT(&element == list->head->data);
};

void test_inserts_a_node_at_first_place_into_the_list_for_doubles(){
	List* list = create();
	int result;
	double element = 40.0;
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->length == 1);
	ASSERT(NULL == list->head->next);
	ASSERT(NULL == list->head->prev);
	ASSERT(&element == list->head->data);
};

void test_inserts_a_node_at_first_place_into_the_list_for_characters(){
	List* list = create();
	int result;
	char element = 's';
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->length == 1);
	ASSERT(NULL == list->head->next);
	ASSERT(NULL == list->head->prev);
	ASSERT(&element == list->head->data);
};

void test_inserts_a_node_at_first_place_into_the_list_for_strings(){
	List* list = create();
	int result;
	String element = "hello";
	result = insert(list, 0, &element);
	ASSERT(result == 1);
	ASSERT(list->length == 1);
	ASSERT(NULL == list->head->next);
	ASSERT(NULL == list->head->prev);
	ASSERT(&element == list->head->data);
};

void test_inserts_a_node_at_last_place_into_the_list_for_integers(){
	List* list = create();
	int result;
	int element1 = 40 , element2 = 50 , element3 = 60;
	insert(list, 0, &element1);
	insert(list, 1, &element2);
	result = insert(list, 2, &element3);
	ASSERT(result == 1);
	ASSERT(list->length == 3);
	ASSERT(NULL == list->head->prev);
	ASSERT(list->head->next == list->end);
	ASSERT(&element1 == list->head->data);
	// ASSERT(&element3 == list->end->data);
	ASSERT(&element2 == list->head->next->data);
};

// void test_inserts_a_node_at_last_place_into_the_list_for_floats(){
// 	List* list = create();
// 	int result;
// 	float element1 = 40.0f;
// 	float element2 = 500.0f;
// 	insert(list, 0, &element1);
// 	insert(list, 1, &element1);
// 	result = insert(list, 2, &element2);
// 	ASSERT(result == 1);
// 	ASSERT(list->length == 3);
// 	ASSERT(NULL == list->head->prev);
// 	ASSERT(list->head->next == list->end->prev);
// 	ASSERT(&element1 == list->head->data);
// };

// void test_inserts_a_node_at_last_place_into_the_list_for_doubles(){
// 	List* list = create();
// 	int result;
// 	double element1 = 40.0;
// 	double element2 = 440.0;
// 	insert(list, 0, &element1);
// 	insert(list, 1, &element1);
// 	result = insert(list, 2, &element2);
// 	ASSERT(result == 1);
// 	ASSERT(list->length == 3);
// 	ASSERT(NULL == list->head->prev);
// 	ASSERT(list->head->next == list->end->prev);
// 	ASSERT(&element1 == list->head->data);
// };

// void test_inserts_a_node_at_last_place_into_the_list_for_characters(){
// 	List* list = create();
// 	int result;
// 	char element1 = 'a';
// 	char element2 = 'b';
// 	insert(list, 0, &element1);
// 	insert(list, 1, &element1);
// 	result = insert(list, 2, &element2);
// 	ASSERT(result == 1);
// 	ASSERT(list->length == 3);
// 	ASSERT(NULL == list->head->prev);
// 	ASSERT(list->head->next == list->end->prev);
// 	ASSERT(&element1 == list->head->data);
// };

// void test_inserts_a_node_at_last_place_into_the_list_for_Strings(){
// 	List* list = create();
// 	int result;
// 	String element1 = "halllo";
// 	String element2 = "world";
// 	insert(list, 0, &element1);
// 	insert(list, 1, &element1);
// 	result = insert(list, 2, &element2);
// 	ASSERT(result == 1);
// 	ASSERT(list->length == 3);
// 	ASSERT(NULL == list->head->prev);
// 	ASSERT(list->head->next == list->end->prev);
// 	ASSERT(&element1 == list->head->data);
// 	ASSERT(&element2 == list->end->data);
// };

// void test_inserts_a_node_at_2nd_place_into_the_list_for_integers(){
// 	List* list = create();
// 	int result;
// 	int element1 = 1, element2 = 2, element3 = 3, element4 = 4; 
// 	insert(list, 0, &element1);
// 	insert(list, 1, &element2);
// 	insert(list, 2, &element3);
// 	result = insert(list, 2, &element4);
// 	ASSERT(result == 1);
// 	ASSERT(list->length == 4);
// 	ASSERT(NULL == list->head->next);
// 	ASSERT(list->head->next == list->end->prev);
// 	ASSERT(&element1 == list->head->data);
// 	ASSERT(&element3 == list->end->data);
// };