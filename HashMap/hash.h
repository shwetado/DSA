#include "include/arrayList.h"

typedef int (*keyComparator)(void* first,void* second);
typedef int (*hashCodeGenerator)(void* key);

typedef struct {
	keyComparator compare;
	hashCodeGenerator getHash;
	ArrayList bucket;
} HashMap;

HashMap createHash(hashCodeGenerator gethash, keyComparator compare);
int put(HashMap* hash, void* key, void* value);
void* getHashData(HashMap* hash, void* key);
int removeHashData(HashMap* hash, void* key);