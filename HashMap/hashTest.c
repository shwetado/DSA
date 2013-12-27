#include "testUtils.h"
#include "hash.h"
#include <stdlib.h>

// create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
	int id;
	char* name;
} Intern;

Intern dubeyji = {100,"Dubeyji"};
Intern samiksha = {555,"Samiksha"};

int getHash(void* key){
	return *(int*)key;
};

int compareInterns(void* element1, void* element2){
	return *(int*)element1 == *(int*)element2;
};

void test_inserts_element_to_hash_map(){
	int key = 100;
	HashMap hash = createHash(getHash, compareInterns);
	ASSERT(1 == put(&hash, &key, &dubeyji));
};

void test_inserts_2_elements_to_hash_map(){
	int key1 = 100 , key2 = 555;
	HashMap hash = createHash(getHash, compareInterns);
	ASSERT(1 == put(&hash, &key1, &dubeyji));
	ASSERT(1 == put(&hash, &key2, &samiksha));
};

void test_searches_element_from_hash_map_if_present(){
	int key = 100;
	HashMap hash = createHash(getHash, compareInterns);
	ASSERT(1 == put(&hash, &key, &dubeyji));
	ASSERT(&dubeyji == getHashData(&hash, &key));
};

void test_doesnt_search_element_from_hash_map(){
	int key = 100;
	HashMap hash = createHash(getHash, compareInterns);
	ASSERT(NULL == getHashData(&hash, &key));
};

