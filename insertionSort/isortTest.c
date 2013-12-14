#include "testUtils.h"
#include <string.h>
#include <memory.h>
#include "isort.h"

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
	int elements[5] = {14,12,11,13,15};
	int expected[5] = {11,12,13,14,15};
	isort(elements, 5, sizeof(int), compareInts);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_integers() {
	int elements[5] = {11,12,13,14,15};
	int expected[5] = {11,12,13,14,15};
	isort(elements, 5, sizeof(int), compareInts);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_float() {
	float elements[5] = {14.0f,12.0f,11.0f,13.0f,15.0f};
	float expected[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	isort(elements, 5, sizeof(float), compareFloats);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_float() {
	double elements[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	double expected[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	isort(elements, 5, sizeof(double), compareFloats);
	ASSERT(areEqual(&elements,&elements,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_double() {
	double elements[5] = {14.0,12.0,11.0,13.0,15.0};
	double expected[5] = {11.0,12.0,13.0,14.0,15.0};
	isort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_double() {
	double elements[5] = {11.0,12.0,13.0,14.0,15.0};
	double expected[5] = {11.0,12.0,13.0,14.0,15.0};
	isort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_String() {
	String elements[5] = {"dello","bello","aello","cello","eello"};
	String expected[5] = {"aello","bello","cello","dello","eello"};
	isort(elements, 5, sizeof(String), compareStrings);
	ASSERT(areEqual(&elements,&expected,5));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_String() {
	String elements[5] = {"aello","bello","cello","dello","eello"};
	String expected[5] = {"aello","bello","cello","dello","eello"};
	isort(elements, 5, sizeof(String), compareStrings);
	ASSERT(areEqual(&elements,&expected,5));
};