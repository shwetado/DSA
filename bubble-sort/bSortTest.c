#include "testUtils.h"
#include "bSort.h"
#include <string.h>
#include <memory.h>

typedef char String[256] ;

int compareInts(void* a, void* b){
	return *(int*)a - *(int*)b;
};

int compareFloats(void* a, void* b){
	return *(float*)a - *(float*)b;
};

int compareDoubles(void* a, void* b){
	return *(double*)a - *(double*)b;
};

int compareStrings(void* a, void* b){
	return strcmp(*(String*)a,*(String*)b);
};

int areEqual(void* element1, void* element2,size_t size){
	int res = memcmp(element1,element2,sizeof(element1)*size);
	return 0 == res;
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_integers() {
	int elements[5] = {140,120,110,130,150};
	int expected[5] = {110,120,130,140,150};
	bSort(elements, 5, sizeof(int), compareInts);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_integers() {
	int elements[5] = {11,12,13,14,15};
	int expected[5] = {11,12,13,14,15};
	bSort(elements, 5, sizeof(int), compareInts);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_float() {
	float elements[5] = {14.0f,12.0f,11.0f,13.0f,15.0f};
	float expected[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	bSort(elements, 5, sizeof(float), compareFloats);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_float() {
	double elements[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	double expected[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	bSort(elements, 5, sizeof(double), compareFloats);
	ASSERT(areEqual(&elements,&elements,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_double() {
	double elements[5] = {14.0,12.0,11.0,13.0,15.0};
	double expected[5] = {11.0,12.0,13.0,14.0,15.0};
	bSort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_double() {
	double elements[5] = {11.0,12.0,13.0,14.0,15.0};
	double expected[5] = {11.0,12.0,13.0,14.0,15.0};
	bSort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_String() {
	String elements[5] = {"dello","bello","aello","cello","eello"};
	String expected[5] = {"aello","bello","cello","dello","eello"};
	bSort(elements, 5, sizeof(String), compareStrings);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_String() {
	String elements[5] = {"aello","bello","cello","dello","eello"};
	String expected[5] = {"aello","bello","cello","dello","eello"};
	bSort(elements, 5, sizeof(String), compareStrings);
	ASSERT(areEqual(&elements,&expected,5));
};