#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
Intern tanbirka = {43343, "Tanbir Ka"};
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
};

void tearDown() {
	dispose(internsPtr);	
};

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
};

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
};

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
};

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
};

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
};

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
};

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
};

void test_adds_multiple_elements() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;
	insert(internsPtr, 0, &prateek);
	add(internsPtr, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
};

void test_should_not_add_when_data_is_null() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;
	insert(internsPtr, 0, &prateek);
	ASSERT(0 == add(internsPtr, NULL));
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(NULL == get(internsPtr, 1));
};

int compareInts(void* element1, void* element2){
	Intern i1 = *(Intern*)element1;
	Intern i2 = *(Intern*)element2;
	return i1.id - i2.id;
};

void test_searches_element() {
	int result;
	insert(internsPtr, 0, &prateek);
	result = search(internsPtr, &prateek, compareInts);
	ASSERT(1 == result);
};

void test_does_not_search_when_element_absent() {
	int result;
	insert(internsPtr, 0, &prateek);
	result = search(internsPtr, &ji, compareInts);
	ASSERT(0 == result);
};

void test_removes_element() {
	int result;
	insert(internsPtr, 0, &prateek);
	result = remove(internsPtr, 0);
	ASSERT(1 == result);
};

void test_deletes_and_shifts_elements_left(){
    int result;
    insert(internsPtr, 0, &prateek);
    insert(internsPtr, 0, &ji);
    ASSERT(2 == interns.length);
    result = remove(internsPtr, 0);
    ASSERT(&prateek == get(internsPtr, 0));
    ASSERT(NULL == get(internsPtr, 1));
    ASSERT(result == SUCCESS);        
};

void printId(void* data){
    Intern intern = *(Intern*)data;
    printf("%d\n", intern.id);
};

void test_prints_data_of_each_element(){
    add(internsPtr, &prateek);
    add(internsPtr, &ji);
    iterate(interns, printId);
};