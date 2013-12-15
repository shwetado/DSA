#include <memory.h>
#include <stdlib.h>
#include "stack.h"
#include "testUtils.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Stack a, Stack b){
    int result = a.length == b.length && a.top == b.top;
    if(!result) return result;
    return 0 == memcmp(a.elements,b.elements,a.length*sizeof(void*));
};

void dispose(Stack* stack){
    free(stack->elements);
    free(stack);
};

void test_creates_a_stack_for_with_given_length (){
    Stack* stack = create(3);
    void* array[3] = {NULL,NULL,NULL};
    Stack expected = {array,0,3};
    ASSERT(areEqual(expected, *stack));
    dispose(stack);
};

void test_pushes_the_element_at_the_top_of_the_stack_for_integers(){
    int* num = malloc(sizeof(int));
    Stack* stack = create(1);
    *num = 400;
    push(stack, num);
    ASSERT(400 == **(int**)stack->elements);
    ASSERT(1 == stack->top && 1 == stack->length);
    dispose(stack);
};

void test_pushes_the_given_doubles_at_the_top_of_the_stack(){
    double *nums = malloc(sizeof(double)*2);
    Stack* stack = create(2);
    nums[0] = 400.0;nums[1] = 100.0;
    push(stack, &nums[0]);
    push(stack, &nums[1]);
    ASSERT(400.0 == **(double**)getElement(stack, 0));
    ASSERT(100.0 == **(double**)getElement(stack, 1));
    ASSERT(2 == stack->top && 2 == stack->length);
    dispose(stack);
};

void test_pushes_the_given_characters_at_the_top_of_the_stack(){
    Stack* stack = create(3);
    char* characters = malloc(sizeof(char)*2);
    characters[0] = 'a';
    characters[1] = 'b';
    push(stack, &characters[0]);
    push(stack, &characters[1]);
    ASSERT('a' == **(char**)getElement(stack, 0));
    ASSERT('b' == **(char**)getElement(stack, 1));
    ASSERT(2 == stack->top && 3 == stack->length);
    dispose(stack);
};

void test_pushes_the_given_Strings_at_the_top_of_the_stack(){
    String* names = malloc(sizeof(String)*2);
    Stack* stack = create(2);
    strcpy(names[0], "hello");
    strcpy(names[1], "world");
    push(stack, &names[0]);
    push(stack, &names[1]);
    ASSERT(0 == strcmp(names[0], *(char**)getElement(stack, 0)));
    ASSERT(0 == strcmp(names[1], *(char**)getElement(stack, 1)));
    dispose(stack);
}

typedef struct {
    int accNo;
    int balance;
} Account;

int areAccountsEqual(Account expected,Account actual){
    return expected.accNo == actual.accNo && expected.balance == actual.balance;
};

void test_pushes_the_structures__into_stack(){
    Account* account = malloc(sizeof(Account));
    Stack* stack = create(3);
    account->accNo = 213;account->balance = 2130;
    push(stack, account);
    ASSERT(areAccountsEqual(*account, **(Account**)getElement(stack, 0)));
    ASSERT(1 == stack->top && 3 == stack->length);
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_integers(){
    Stack* stack = create(3);
    int *nums = malloc(sizeof(int)*4);
    int* result;
    nums[0] = 100;nums[1] = 400;nums[2] = 150;nums[3] = 200;
    push(stack, &nums[0]);  push(stack, &nums[2]);
    push(stack, &nums[1]);  push(stack, &nums[3]);
    result = pop(stack);
    ASSERT(200 == *result);
    ASSERT(3 == stack->top);
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_doubles(){
    Stack* stack = create(3);
    double* nums = malloc(sizeof(double)*4);
    double* result;
    nums[0] = 100.0;nums[1] = 400.0;nums[2] = 150.0;nums[3] = 200.0;
    push(stack, &nums[0]);
    push(stack, &nums[2]);
    push(stack, &nums[1]);
    push(stack, &nums[3]);
    result = pop(stack);
    ASSERT(200.0 == *result);
    ASSERT(3 == stack->top);
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_characters(){
    Stack* stack = create(3);
    char* characters = malloc(sizeof(char)*4);
    char* result;
    characters[0] = 'a';characters[1] = 'b';characters[2] = 'c';characters[3] = 'd';
    push(stack, &characters[0]);    push(stack, &characters[2]);
    push(stack, &characters[1]);    push(stack, &characters[3]);
    result = pop(stack);
    ASSERT('d' == *result);
    ASSERT(3 == stack->top);
    dispose(stack);
};

void test_deletes_the_top_most_element_from_the_stack_Strings(){
    String* nums = malloc(sizeof(String)*2);
    char* result;
    Stack* stack = create(2);
    strcpy(nums[0], "hello");
    strcpy(nums[1], "world");
    push(stack, &nums[0]);  push(stack, &nums[1]);
    result = pop(stack);
    ASSERT(0 == strcmp("world", result));
    ASSERT(1 == stack->top);
    dispose(stack);
};

void test_deletes_structures_on_the_top_of_stacks(){
    Account* account = malloc(sizeof(Account));
    Stack* stack = create(3);
    Account* result;
    account->accNo = 213;account->balance = 2130;
    push(stack, account);
    ASSERT(areAccountsEqual(*account, **(Account**)getElement(stack, 0)));
    result = pop(stack);
    ASSERT(areAccountsEqual(*result, *account));
    ASSERT(0 == stack->top && 3 == stack->length);
    dispose(stack);
}

void test_deletes_the_top_most_element_and_pushes_one_more_element_at_top(){
    int *nums = malloc(sizeof(int)*4);
    int* result;
    Stack* stack = create(4);
    nums[0] = 100;  nums[1] = 400;  nums[2] = 150;  nums[3] = 200;
    push(stack, &nums[0]);    push(stack, &nums[2]);
    push(stack, &nums[1]);    push(stack, &nums[3]);
    ASSERT(200 == **(int**)getElement(stack, 3));
    result = (int*)(pop(stack));
    ASSERT(200 == *result);
    push(stack, &nums[1]);
    ASSERT(4 == stack->top);
    ASSERT(400 == **(int**)getElement(stack, 3));
    dispose(stack);
};

void test_prevents_to_delete_the_element_if_top_is_zero(){
    void* result;
    Stack* stack = create(5);
    result = pop(stack);
    ASSERT(NULL == result);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_integers(){
    int *nums = malloc(sizeof(int)*4);
    Stack* stack = create(3);
    int* result;
    nums[0] = 100;nums[1] = 400;nums[2] = 150;nums[3] = 200;
    push(stack, &nums[0]);    push(stack, &nums[2]);
    push(stack, &nums[1]);    push(stack, &nums[3]);
    result = top(stack);
    ASSERT(200 == *result);
    ASSERT(4 == stack->top);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_doubles(){
    double* nums = malloc(sizeof(double)*4);
    Stack* stack = create(3);
    double* result;
    nums[0] = 100.0;nums[1] = 400.0;nums[2] = 150.0;nums[3] = 200.0;
    push(stack, &nums[0]);    push(stack, &nums[2]);
    push(stack, &nums[1]);    push(stack, &nums[3]);
    result = top(stack);
    ASSERT(200.0 == *result);
    ASSERT(4 == stack->top);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_characters(){
    char* characters = malloc(sizeof(char)*4);
    Stack* stack = create(3);
    char* result;
    characters[0] = 'a';characters[1] = 'b';characters[2] = 'c';characters[3] = 'd';
    push(stack, &characters[0]);    push(stack, &characters[2]);
    push(stack, &characters[1]);    push(stack, &characters[3]);
    result = top(stack);
    ASSERT('d' == *result);
    ASSERT(4 == stack->top);
    dispose(stack);
};

void test_gives_1_when_the_stack_is_empty_integers(){
    int result;
    Stack* stack = create(5);
    result = isEmpty(stack);
    ASSERT(1==result);
    dispose(stack);
};

void test_gives_0_when_the_stack_is_not_empty(){
    int result;
    Stack* stack = create(5);
    *(int*)stack->elements = 150;
    stack->top = 1;
    result = isEmpty(stack);
    ASSERT(0==result);
    dispose(stack);
};

void test_gives_1_when_the_stack_is_full_integers(){
    int* num = malloc(sizeof(int));
    int result;
    Stack* stack = create(1);
    *num = 150;
    push(stack, num);
    result = isFull(stack);
    ASSERT(1==result);
    dispose(stack);
};

void test_gives_0_when_the_stack_is_not_full(){
    int result;
    Stack* stack = create(4);
    result = isFull(stack);
    ASSERT(0==result);
    dispose(stack);
};

void test_gives_the_top_most_element_from_the_stack_Strings(){
    String* nums = malloc(sizeof(String)*2);
    Stack* stack = create(2);
    char* result;
    strcpy(nums[0], "hello");
    strcpy(nums[1], "world");
    push(stack, &nums[0]);    push(stack, &nums[1]);
    result = top(stack);
    ASSERT(0 == strcmp("world", result));
    ASSERT(2 == stack->top);
    dispose(stack);
};

void test_gives_null_if_no_element_in_stack(){
    void* result;
    Stack* stack = create(5);
    result = top(stack);
    ASSERT(NULL == result);
    dispose(stack);
};

void test_pushes_the_given_ints_at_the_top_of_the_stack(){
    int *nums = malloc(sizeof(int)*2);
    Stack* stack = create(2);
    nums[0] = 400;nums[1] = 100;
    push(stack, &nums[0]);
    push(stack, &nums[1]);
    ASSERT(400 == **(int**)getElement(stack, 0));
    ASSERT(100 == **(int**)getElement(stack, 1));
    ASSERT(2 == stack->top && 2 == stack->length);
    dispose(stack);
};
