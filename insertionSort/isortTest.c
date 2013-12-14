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

int comparechars(void* a, void* b){
	return *(char*)a - *(char*)b;
};

int compareStrings(void* a, void* b){
	return strcmp(*(String*)a,*(String*)b);
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_integers() {
	int elements[5] = {14,12,11,13,15};
	isort(elements, 5, sizeof(int), compareInts);
	ASSERT(elements[0] == 11);
	ASSERT(elements[1] == 12);
	ASSERT(elements[2] == 13);
	ASSERT(elements[3] == 14);
	ASSERT(elements[4] == 15);
};

void test_sorts_the_elements_when_given_an_sorted_list_for_integers() {
	int elements[5] = {11,12,13,14,15};
	isort(elements, 5, sizeof(int), compareInts);
	ASSERT(elements[0] == 11);
	ASSERT(elements[1] == 12);
	ASSERT(elements[2] == 13);
	ASSERT(elements[3] == 14);
	ASSERT(elements[4] == 15);
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_float() {
	float elements[5] = {14.0f,12.0f,11.0f,13.0f,15.0f};
	isort(elements, 5, sizeof(float), compareFloats);
	ASSERT(elements[0] == 11.0f);
	ASSERT(elements[1] == 12.0f);
	ASSERT(elements[2] == 13.0f);
	ASSERT(elements[3] == 14.0f);
	ASSERT(elements[4] == 15.0f);
};

void test_sorts_the_elements_when_given_an_sorted_list_for_float() {
	double elements[5] = {11.0f,12.0f,13.0f,14.0f,15.0f};
	isort(elements, 5, sizeof(double), compareFloats);
	ASSERT(elements[0] == 11.0f);
	ASSERT(elements[1] == 12.0f);
	ASSERT(elements[2] == 13.0f);
	ASSERT(elements[3] == 14.0f);
	ASSERT(elements[4] == 15.0f);
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_double() {
	double elements[5] = {14.0,12.0,11.0,13.0,15.0};
	isort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(elements[0] == 11.0);
	ASSERT(elements[1] == 12.0);
	ASSERT(elements[2] == 13.0);
	ASSERT(elements[3] == 14.0);
	ASSERT(elements[4] == 15.0);
};

void test_sorts_the_elements_when_given_an_sorted_list_for_double() {
	double elements[5] = {11.0,12.0,13.0,14.0,15.0};
	isort(elements, 5, sizeof(double), compareDoubles);
	ASSERT(elements[0] == 11.0);
	ASSERT(elements[1] == 12.0);
	ASSERT(elements[2] == 13.0);
	ASSERT(elements[3] == 14.0);
	ASSERT(elements[4] == 15.0);
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_char() {
	char elements[5] = {'d','b','a','c','e'};
	isort(elements, 5, sizeof(char), comparechars);
	ASSERT(elements[0] == 'a');
	ASSERT(elements[1] == 'b');
	ASSERT(elements[2] == 'c');
	ASSERT(elements[3] == 'd');
	ASSERT(elements[4] == 'e');
};

void test_sorts_the_elements_when_given_an_sorted_list_for_char() {
	char elements[5] = {'a','b','c','d','e'};
	isort(elements, 5, sizeof(char), comparechars);
	ASSERT(elements[0] == 'a');
	ASSERT(elements[1] == 'b');
	ASSERT(elements[2] == 'c');
	ASSERT(elements[3] == 'd');
	ASSERT(elements[4] == 'e');
};

void test_sorts_the_elements_when_given_an_unsorted_list_for_String() {
	String elements[5] = {"dello","bello","aello","cello","eello"};
	isort(elements, 5, sizeof(String), compareStrings);
	ASSERT(0 == strcmp(elements[0],"aello"));
	ASSERT(0 == strcmp(elements[1],"bello"));
	ASSERT(0 == strcmp(elements[2],"cello"));
	ASSERT(0 == strcmp(elements[3],"dello"));
	ASSERT(0 == strcmp(elements[4],"eello"));
};

void test_sorts_the_elements_when_given_an_sorted_list_for_String() {
	String elements[5] = {"aello","bello","cello","dello","eello"};
	isort(elements, 5, sizeof(String), compareStrings);
	ASSERT(0 == strcmp(elements[0],"aello"));
	ASSERT(0 == strcmp(elements[1],"bello"));
	ASSERT(0 == strcmp(elements[2],"cello"));
	ASSERT(0 == strcmp(elements[3],"dello"));
	ASSERT(0 == strcmp(elements[4],"eello"));
};