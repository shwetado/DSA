#include <string.h>
#include "brackets.h"
#include "../stack_memcpy/Stack.h"

int doesBracketMatch(char firstChar,char secondChar){
	if(firstChar == '(' && secondChar == ')')
		return 1;
	else if(firstChar == '{' && secondChar == '}')
		return 1;
	else if(firstChar == '[' && secondChar == ']')
		return 1;
	else
		return 0;
};

int isOpeningBracket(char input){
	if(input == '{' || input == '(' || input == '[')
		return 1;
	return 0;
};

int isClosingBracket(char input){
	if(input == '}' || input == ')' || input == ']')
		return 1;
	return 0;
};

int doBracketsMatch(char expr[]){
	int i;
	Stack* stack = create(sizeof(char), 256);
	for(i = 0; i <= strlen(expr); i++ ) {
		if(isOpeningBracket(expr[i]))
			push(stack, &expr[i]);
		else if(isClosingBracket(expr[i])){
			if(1 == isEmpty(stack))	return 0; 
	        else if ( !doesBracketMatch(*(char*)pop(stack), expr[i]) )
	           return 0;
	    }
	}
   	if(1 == isEmpty(stack))	return 1;
    return 0;
};