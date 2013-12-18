#include <stddef.h>

typedef int compareFunc (const void* ,const void*);

typedef char String[256];

void* binarySearch (const void* key, const void* base,
               size_t totalElements, size_t elementSize,
               compareFunc* compare);