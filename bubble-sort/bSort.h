typedef int (*compareFunc) (void* element1, void* element2);

void bSort(void* elements, int noOfElements, int typeSize, compareFunc cmp);