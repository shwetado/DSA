#include <memory.h>
#include <stdlib.h>
#include "stack.h"
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_creates_a_stack_of_given_length (){
    Stack* stack = createStack();
    void* topElement = top(stack);
    ASSERT(0 == topElement);
    dispose(stack);
};

void test_pushes_the_element_at_top_of_the_stack_for_ints(){
    Stack* stack = createStack();
    int num = 40;
    push(stack, &num);
    ASSERT(num == *(int*)top(stack));
    dispose(stack);
};

void test_pushes_the_given_double_at_the_top_of_the_stack(){
    Stack* stack = createStack();
    double num = 40.0;
    push(stack, &num);
    ASSERT(num == *(double*)top(stack));
    dispose(stack);
};

void test_pushes_the_given_float_at_the_top_of_the_stack(){
    Stack* stack = createStack();
    float num = 40.0f;
    push(stack, &num);
    ASSERT(num == *(float*)top(stack));
    dispose(stack);
};

void test_pushes_the_given_characters_at_the_top_of_the_stack(){
    Stack* stack = createStack();
    char element = 'a';
    push(stack, &element);
    ASSERT(element == *(char*)top(stack));
    dispose(stack);
};

void test_pushes_the_given_Strings_at_the_top_of_the_stack(){
    Stack* stack = createStack();
    String element = "India";
    push(stack, &element);
    ASSERT(0 == strcmp(element,*(String*)top(stack)));
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_integers(){
    Stack* stack = createStack();
    int num1 = 40 , num2 = 50;
    push(stack, &num1);
    push(stack, &num2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(0 == pop(stack));
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_doubles(){
    Stack* stack = createStack();
    double num1 = 40.0 , num2 = 50.0;
    push(stack, &num1);
    push(stack, &num2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(0 == pop(stack));
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_floats(){
    Stack* stack = createStack();
    float num1 = 40.0 , num2 = 50.0;
    push(stack, &num1);
    push(stack, &num2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(0 == pop(stack));
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_characters(){
    Stack* stack = createStack();
    char char1 = 'a' , char2 = 'b';
    push(stack, &char1);
    push(stack, &char2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(0 == pop(stack));
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_Strings(){
    Stack* stack = createStack();
    String element1 = "abc" , element2 = "xyz";
    push(stack, &element1);
    push(stack, &element2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(0 == pop(stack));
    dispose(stack);
};

void test_deletes_the_top_most_element_and_pushes_one_more_element_at_top(){
    Stack* stack = createStack();
    String element1 = "abc" , element2 = "xyz";
    push(stack, &element1);
    push(stack, &element2);
    ASSERT(1 == pop(stack));
    ASSERT(1 == pop(stack));
    ASSERT(1 == push(stack, &element2));
    ASSERT(0 == strcmp(element2 , *(String*)top(stack)));
    dispose(stack);
};

void test_prevents_to_delete_the_element_if_top_is_zero(){
    Stack* stack = createStack();
    int result = pop(stack);
    ASSERT(0 == result);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_integers(){
    Stack* stack = createStack();
    int element = 40;
    push(stack, &element);
    ASSERT(element == *(int*)top(stack));
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_doubles(){
    Stack* stack = createStack();
    double element = 40.0;
    push(stack, &element);
    ASSERT(element == *(double*)top(stack));
    dispose(stack);
};

void test_the_top_most_element_from_the_stack_floats(){
    Stack* stack = createStack();
    float element = 40.0f;
    push(stack, &element);
    ASSERT(element == *(float*)top(stack));
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_chars(){
    Stack* stack = createStack();
    char element = 'a';
    push(stack, &element);
    ASSERT(element == *(char*)top(stack));
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_Strings(){
    Stack* stack = createStack();
    String element = "India";
    push(stack, &element);
    ASSERT(0 == strcmp(element , *(String*)top(stack)));
    dispose(stack);
};

void test_gives_1_when_the_stack_is_empty_integers(){
    Stack* stack = createStack();
    int result = isEmpty(stack);
    ASSERT(1 == result);
    dispose(stack);
};

void test_gives_null_if_no_element_in_stack(){
    Stack* stack = createStack();
    void* result = top(stack);
    ASSERT(NULL == result);
    dispose(stack);
};