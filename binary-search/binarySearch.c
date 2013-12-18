#include "binarySearch.h"

void* binarySearch(const void* key, const void* base, size_t elements, size_t typeSize, compareFunc *compare){
    int first = 0 , result , mid;
    int last = elements - 1;
    while(first <= last){
        mid = (first + last)/2;
        result = compare(key, base + mid*typeSize);
        if(!result)
            return (void*)(base + mid*typeSize);
        if(result < 0)
            last = mid-1;
        else
            first = mid + 1;
    }
    return NULL;
};