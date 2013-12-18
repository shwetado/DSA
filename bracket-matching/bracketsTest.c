#include "testUtils.h"
#include "brackets.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_given_expression_must_return_1_as_brackets_matches(){
	char expr[100] = "[]";
	ASSERT(1 == doBracketsMatch(expr));
};

void test_given_expression_must_return_0_as_brackets_doesnt_match(){
	char expr[100] = "{()}[";
	ASSERT(0 == doBracketsMatch(expr));
};

void test_given_string_must_return_1_as_serially_brackets_are_present(){
	char expr[100] = "{(abc[d{e}f]ghi)}";
	ASSERT(1 == doBracketsMatch(expr));
};

void test_given_for_loop_must_return_1_as_brackets_matches(){
	char expr[100] = "for(int i=0;i<length;i++);";
	ASSERT(1 == doBracketsMatch(expr));
};

void test_given_string_must_return_1_as_brackets_are_absent(){
	char expr[100] = "abcdefghi";
	ASSERT(1 == doBracketsMatch(expr));
};