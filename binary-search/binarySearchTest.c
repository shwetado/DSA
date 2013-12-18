#include "binarySearch.h"
#include "testUtils.h"
#include <string.h>

int compareInts (const void* a, const void* b){
    return (*(int*)a - *(int*)b);
};

void test_search_an_integer_element_from_given_5_elements(){
    int key = 300;
    int elements[5] = {100,300,500,700,900};
    int* result = binarySearch(&key, elements, 5, sizeof(int), compareInts);
    ASSERT(300==*result);
    ASSERT(&elements[1] == result);
};

void test_search_gives_null_if_element_is_absent_for_integer(){
    int elements[5] = {23,324,23,123,432};
    int key = 999;
    int* result = binarySearch(&key, elements, 5, sizeof(int), compareInts);
    ASSERT(NULL == result);
};

int compareDoubles(const void* a, const void* b){
    return (*(double*)a - *(double*)b);
};

void test_search_a_double_element_from_given_5_elements(){
    double elements[5] = {111.0,222.0,333.0,444.0,555.0};
    double key = 555.0;
    double* result = binarySearch(&key, elements, 5, sizeof(double), compareDoubles);
    ASSERT(555.0==*result);
    ASSERT(&elements[4] == result);
};

void test_search_gives_null_if_element_is_absent_for_double(){
    double elements[5] = {111.0,222.0,333.0,444.0,555.0};
    double key = 000.0;
    double* result = binarySearch(&key, elements, 5, sizeof(double), compareDoubles);
    ASSERT(NULL == result);
};

int compareFloats(const void* a, const void* b){
    return (*(float*)a - *(float*)b);
};

void test_search_a_float_element_from_given_5_elements(){
    float elements[5] = {111.0,222.0,333.0,444.0,555.0};
    float key = 555.0;
    float* result = binarySearch(&key, elements, 5, sizeof(float), compareFloats);
    ASSERT(555.0==*result);
    ASSERT(&elements[4] == result);
};

void test_search_gives_null_if_element_is_absent_for_float(){
    float elements[5] = {111.0,222.0,333.0,444.0,555.0};
    float key = 000.0;
    float* result = binarySearch(&key, elements, 5, sizeof(float), compareFloats);
    ASSERT(NULL == result);
}

int compareChars(const void* a, const void* b){
    return (*(char*)a - *(char*)b);
};

void test_search_an_character_from_given_5_elements(){
    char elements[5] = {'i','n','d','i','a'};
    char key = 'i';
    char* result = binarySearch(&key, elements, 5, sizeof(char), compareChars);
    ASSERT('i'==*result);
    ASSERT(&elements[3] == result);
};

void test_search_gives_null_if_element_is_absent_for_characters(){
    char elements[5] = {'h','a','a','l','o'};
    char key = 'z';
    char* result = binarySearch(&key, elements, 5, sizeof(char), compareChars);
    ASSERT(NULL == result);
};

int compareStrings(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
};

void test_search_element_from_5_elements_for_Strings(){
    String elements[5] = {"aaa","bbb","ccc","ddd","eee"};
    char* key = "bbb";
    char* result = binarySearch(key, elements, 5, sizeof(String), compareStrings);
    ASSERT(0 == strcmp("bbb", result));
};

void test_search_gives_null_if_element_absent_for_Strings(){
    String elements[5] = {"aaa","bbb","ccc","ddd","eee"};
    char* key = "zzz";
    char* result = binarySearch(key, elements, 5, sizeof(String), compareStrings);
    ASSERT(NULL == result);
};