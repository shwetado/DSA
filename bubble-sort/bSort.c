#include "bSort.h"
#include <stdlib.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
void bSort(void* elements, int noOfElements, int typeSize,compareFunc cmp) {
	int i, j;
	void* temp = calloc(1, typeSize);
	void* current;
	void* nextElement;
	for (i = 1; i < noOfElements; i++)
		for (j = 0; j < noOfElements - i; j++) {
		    current = elements + j * typeSize;
		    nextElement = elements + (j+1) * typeSize;
		    if (0 < cmp(current,nextElement)){
		        memcpy(temp, current, typeSize);
		        memcpy(current, nextElement,  typeSize);
		        memcpy(nextElement, temp, typeSize);
		    }
		}
	free(temp);
};