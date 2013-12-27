#include "hash.h"
#include "include/linkedList.h"
#include <stdlib.h>

typedef struct {
	List* keys;
} BucketList;

typedef struct {
	void* key;
	void* values;
} HashElement;

BucketList* createBucketList(){
	BucketList* newBucket = calloc(1,10);
	newBucket->keys = create();
	return newBucket;
};

HashMap createHash(hashCodeGenerator gethash, keyComparator compare){
	HashMap hash;
	int index;
	hash.bucket = createArrList(10);
	hash.getHash = gethash;
	hash.compare = compare;
	for(index = 0; index < 10; index++)
		hash.bucket.base[index] = createBucketList();
	return hash;
};

int getCode(HashMap* hash, int hashCode){
	return hashCode % hash->bucket.capacity;
};

HashElement* getHashElement(void* key,void* value){
	HashElement* element = calloc(1, sizeof(HashElement));
	element->key = key;
	element->values = value;
	return element;	
};

int put(HashMap* hash, void* key, void* value){
	int hashCode = hash->getHash(key);
	BucketList* bucketList;
	List* list;
	void* element = getHashElement(key, value);
	hashCode = getCode(hash, hashCode);
	bucketList = hash->bucket.base[hashCode];
	list = bucketList->keys;
	return insert(list, 0, element);
};

void* getHashData(HashMap* hash, void* key){
	HashElement* elementValue;
	int hashCode = hash->getHash(key);
	BucketList* bucketList;
	List* list;
	Iterator it;
	hashCode = getCode(hash, hashCode);
	bucketList = hash->bucket.base[hashCode];
	list = bucketList->keys;
	it = getIterator(list);
	while(it.hasNext(&it)){
		elementValue = it.next(&it);
		if(hash->compare(elementValue->key,key))
			return elementValue->values;
	}
	return NULL;
};

int removeHashData(HashMap* hash, void* key){
	int index = 0;
	HashElement* elementValue;
	int hashCode = hash->getHash(key);
	BucketList* bucketList;
	List* list;
	Iterator it;
	hashCode = getCode(hash, hashCode);
	bucketList = hash->bucket.base[hashCode];
	list = bucketList->keys;
	it = getIterator(list);
	while(it.hasNext(&it)){
		elementValue = it.next(&it);
		if(hash->compare(elementValue->key,key)){
			index ++;
			return deleteNode(list, index-1);
		}
	}
	return 0;
};