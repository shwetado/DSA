#include "testUtils.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack a, Stack b){
    int result = a.top == b.top &&
    			 a.maxElements == b.maxElements &&
    			 a.sizeOfElement == b.sizeOfElement;
    if(!result) 
    	return result;
    return 0 == memcmp(a.base,b.base,a.maxElements*a.sizeOfElement);
};

void test_createelement_stack_having_2_int_elements(){
    int array[] = {0,0};
    Stack b = {array,-1,4,2};
    Stack* stack = create(sizeof(int),2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_create_stack_ofelement2_floats(){
    float array[] = {0,0};
    Stack b = {array,-1,sizeof(float),2};
    Stack* stack = create(sizeof(float),2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_create_stack_ofelement2_doubles(){
    double array[] = {0,0};
    Stack b = {array,-1,sizeof(double),2};
    Stack* stack = create(sizeof(double),2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_create_stack_of_2elementrrays(){
    char array[] = {'\0','\0'};
    Stack b = {array,-1,sizeof(char),2};
    Stack* stack = create(sizeof(char),2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_create_stack_ofelement2_Strings(){
    String array[] = {"\0","\0"};
    Stack b = {array,-1,sizeof(String),2};
    Stack* stack = create(sizeof(String),2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_pushingelementn_integer_element_in_stack(){
    int expected[] = {1,0};
    int element = 1;
    Stack b = {expected,0,sizeof(int),2};
    Stack* stack = create(sizeof(int),2);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_overflow_of_stack_when_pushed(){
    int expected[] = {1,1};
    int element = 1;
    int result;
    Stack b = {expected,1,sizeof(int),2};
    Stack* stack = create(sizeof(int),2);
    push(stack,&element);
    push(stack,&element);
    result = push(stack,&element);
    ASSERT(result == 0 && areEqual(*stack,b));
    free(stack);
};

void test_pushingelementn_float_element_in_stack(){
    float expected[] = {1.1,0.0,0.0,0.0};
    float element = 1.1;
    Stack b = {expected,0,sizeof(float),4};
    Stack* stack = create(sizeof(float),4);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_pushing_float_element_in_stack_two_times(){
    float expected[] = {1.1,1.1,0.0,0.0};
    float element = 1.1;
    Stack b = {expected,1,sizeof(float),4};
    Stack* stack = create(sizeof(float),4);
    push(stack,&element);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_pushing_double_element_in_stack(){
    double expected[] = {1.1,0.0,0.0,0.0};
    double element = 1.1;
    Stack b = {expected,0,sizeof(double),4};
    Stack* stack = create(sizeof(double),4);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_pushing_char_element_in_stack(){
    char expected[] = {'a','\0'};
    char element = 'a';
    Stack b = {expected,0,sizeof(char),2};
    Stack* stack = create(sizeof(char),2);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_pushing_String_in_element_stack(){
    String expected[] = {"hello","\0"};
    String element = "hello";
    Stack b = {expected,0,sizeof(String),2};
    Stack* stack = create(sizeof(String),2);
    push(stack,&element);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_poppingelementn_integer_from_stack(){
    int expected[] = {2,0};
    int element1 = 1;
    int element2 = 2;
    Stack b = {expected,0,sizeof(int),2};
    Stack* stack = create(sizeof(int),2);
    push(stack,&element1);
    pop(stack);
    push(stack,&element2);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_is_empty_while_pop_operation(){
    Stack* stack = create(sizeof(int),2);
    ASSERT(pop(stack) == NULL);
    free(stack);
};

void test_popping_float_element_from_stack(){
    float expected[] = {1.0,0.0};
    float element1 = 1.0;
    Stack b = {expected,-1,sizeof(float),2};
    Stack* stack = create(sizeof(float),2);
    push(stack,&element1);
    pop(stack);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_popping_double_element_from_stack(){
    double expected[] = {1.0,0.0};
    double element1 = 1.0;
    Stack b = {expected,-1,sizeof(double),2};
    Stack* stack = create(sizeof(double),2);
    push(stack,&element1);
    pop(stack);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_popping_char_element_from_stack(){
    char expected[] = {'a','\0'};
    char element = 'a';
    Stack b = {expected,-1,sizeof(char),2};
    Stack* stack = create(sizeof(char),2);
    push(stack,&element);
    pop(stack);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_popping_String_from_element_stack(){
    String expected[] = {"hello","\0"};
    String _name = "hello";
    Stack b = {expected,-1,sizeof(String),2};
    Stack* stack = create(sizeof(String),2);
    push(stack,&_name);
    pop(stack);
    ASSERT(areEqual(*stack,b));
    free(stack);
};

void test_top_of_integer_stack(){
    int element1 = 1 , element2 = 2;
    int result;
    Stack* stack = create(sizeof(int),2);
    push(stack,&element1);
    push(stack,&element2);
    result = *(int*)top(stack);
    ASSERT(result == 2);
    free(stack);
};

void test_top_of_float_element_stack(){
    float element1 = 1.0;
    float result;
    Stack* stack = create(sizeof(float),4);
    push(stack,&element1);
    result = *(float*)top(stack);
    ASSERT(result == 1);
    free(stack);
};

void test_top_of_double_element_stack(){
    double element1 = 1.0;
    double result;
    Stack* stack = create(sizeof(double),4);
    push(stack,&element1);
    result = *(double*)top(stack);
    ASSERT(result == 1);
    free(stack);
};

void test_top_of_char_element_stack(){
    char element = 'a';
    char result;
    Stack* stack = create(sizeof(char),4);
    push(stack,&element);
    result = *(char*)top(stack);
    ASSERT(result == 'a');
    free(stack);
};

void test_top_of_String_element_stack(){
    String name = "hello";
    Stack* stack = create(sizeof(String),4);
    push(stack,name);
    ASSERT(strcmp("hello",*(String*)top(stack))==0);
    free(stack);
};