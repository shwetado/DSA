#include <memory.h>
#include <stdlib.h>
#include "customHeader.h"
#include "stack.h"
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_creates_a_stack_of_given_length (){
    Stack* pStack = create(3);
    void* topElement = top(pStack);
    ASSERT(0 == topElement);
    dispose(pStack);
};

void test_pushes_the_element_at_top_of_the_stack_for_ints(){
    Stack* pStack = create(1);
    int num = 40;
    push(pStack, &num);
    ASSERT(num == *(int*)top(pStack));
    dispose(pStack);
};

void test_pushes_the_given_double_at_the_top_of_the_stack(){
    Stack* pStack = create(1);
    double num = 40.0;
    push(pStack, &num);
    ASSERT(num == *(double*)top(pStack));
    dispose(pStack);
};

void test_pushes_the_given_float_at_the_top_of_the_stack(){
    Stack* pStack = create(1);
    float num = 40.0f;
    push(pStack, &num);
    ASSERT(num == *(float*)top(pStack));
    dispose(pStack);
};

void test_pushes_the_given_characters_at_the_top_of_the_stack(){
    Stack* pStack = create(1);
    char element = 'a';
    push(pStack, &element);
    ASSERT(element == *(char*)top(pStack));
    dispose(pStack);
};

void test_pushes_the_given_Strings_at_the_top_of_the_stack(){
    Stack* pStack = create(1);
    String element = "India";
    push(pStack, &element);
    ASSERT(0 == strcmp(element,*(String*)top(pStack)));
    dispose(pStack);
};

void test_deletes_the_top_most_element_from_the_stack_integers(){
    Stack* pStack = create(2);
    int num1 = 40 , num2 = 50;
    push(pStack, &num1);
    push(pStack, &num2);
    ASSERT(num2 == *(int*)pop(pStack));
    ASSERT(num1 == *(int*)pop(pStack));
    dispose(pStack);
};

void test_deletes_the_top_most_element_from_the_stack_doubles(){
    Stack* pStack = create(2);
    double num1 = 40.0 , num2 = 50.0;
    push(pStack, &num1);
    push(pStack, &num2);
    ASSERT(num2 == *(double*)pop(pStack));
    ASSERT(num1 == *(double*)pop(pStack));
    dispose(pStack);
};

void test_deletes_the_top_most_element_from_the_stack_floats(){
    Stack* pStack = create(2);
    float num1 = 40.0 , num2 = 50.0;
    push(pStack, &num1);
    push(pStack, &num2);
    ASSERT(num2 == *(float*)pop(pStack));
    ASSERT(num1 == *(float*)pop(pStack));
    dispose(pStack);
};

void test_deletes_the_top_most_element_from_the_stack_characters(){
    Stack* pStack = create(2);
    char char1 = 'a' , char2 = 'b';
    push(pStack, &char1);
    push(pStack, &char2);
    ASSERT(char2 == *(char*)pop(pStack));
    ASSERT(char1 == *(char*)pop(pStack));
    dispose(pStack);
};

void test_deletes_the_top_most_element_from_the_stack_Strings(){
    Stack* pStack = create(2);
    String element1 = "abc" , element2 = "xyz";
    push(pStack, &element1);
    push(pStack, &element2);
    ASSERT(0 == strcmp(element2 , *(String*)pop(pStack)));
    ASSERT(0 == strcmp(element1 , *(String*)pop(pStack)));
    dispose(pStack);
};

void test_deletes_the_top_most_element_and_pushes_one_more_element_at_top(){
    Stack* pStack = create(2);
    String element1 = "abc" , element2 = "xyz";
    push(pStack, &element1);
    push(pStack, &element2);
    ASSERT(0 == strcmp(element2 , *(String*)pop(pStack)));
    ASSERT(0 == strcmp(element1 , *(String*)pop(pStack)));
    ASSERT(1 == push(pStack, &element2));
    ASSERT(0 == strcmp(element2 , *(String*)top(pStack)));
    dispose(pStack);
};

void test_prevents_to_delete_the_element_if_top_is_zero(){
    Stack* stack = create(5);
    void* result = pop(stack);
    ASSERT(NULL == result);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_integers(){
    Stack* pStack = create(1);
    int element = 40;
    push(pStack, &element);
    ASSERT(element == *(int*)top(pStack));
    dispose(pStack);
};

void test_gives_the_top_most_element_from_the_stack_doubles(){
    Stack* pStack = create(1);
    double element = 40.0;
    push(pStack, &element);
    ASSERT(element == *(double*)top(pStack));
    dispose(pStack);
};

void test_gives_the_top_most_element_from_the_stack_floats(){
    Stack* pStack = create(1);
    float element = 40.0f;
    push(pStack, &element);
    ASSERT(element == *(float*)top(pStack));
    dispose(pStack);
};

void test_gives_the_top_most_element_from_the_stack_chars(){
    Stack* pStack = create(1);
    char element = 'a';
    push(pStack, &element);
    ASSERT(element == *(char*)top(pStack));
    dispose(pStack);
};

void test_gives_the_top_most_element_from_the_stack_Strings(){
    Stack* pStack = create(1);
    String element = "India";
    push(pStack, &element);
    ASSERT(0 == strcmp(element , *(String*)top(pStack)));
    dispose(pStack);
};

void test_gives_1_when_the_stack_is_empty_integers(){
    Stack* pStack = create(5);
    int result = isEmpty(pStack);
    ASSERT(1 == result);
    dispose(pStack);
};

void test_gives_0_when_the_stack_is_not_empty(){
    Stack* pStack = create(5);
    int result;
    *(int*)pStack->elements = 150;
    pStack->top = 1;
    result = isEmpty(pStack);
    ASSERT(0==result);
    dispose(pStack);
};

void test_gives_null_if_no_element_in_stack(){
    Stack* pStack = create(5);
    void* result = top(pStack);
    ASSERT(NULL == result);
    dispose(pStack);
};