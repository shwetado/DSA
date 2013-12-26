#include "testUtils.h"
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
    int acc_no;
    int balance;
}Account;

int areEqual(List* actual,List* expected){
	int resHead,resPrev,resNext;
	resHead = memcmp(actual->head->data,expected->head->data,sizeof(List));
	resPrev = memcmp(actual->head->prev,expected->head->prev,sizeof(List));
	resNext = memcmp(actual->head->next,expected->head->next,sizeof(List));
	return 0 == resHead && resPrev && resNext;
};

int areAccountsEqual(Account expected,Account actual){
    return expected.acc_no == actual.acc_no && expected.balance == actual.balance;
};

void test_creates_a_list_containing_head_and_length(){
	List* list = create();
	ASSERT(list->head == NULL);
	ASSERT(list->length == 0);
};

void test_creates_a_node(){
    Node expected = {NULL,NULL,NULL};
    Node *actual = createNode(NULL,NULL);
    ASSERT(expected.next == actual->next);
    ASSERT(expected.prev == actual->prev);
};

//-------------------------insert--------------------------------------------

void test_inserts_first_element_in_linkedlist_for_integer(){
    int* num = malloc(sizeof(int));
    List *list = create();
    int result;	*num = 1;
    result = insert(list,0, num);
    ASSERT(result == 1);
    ASSERT(NULL == list->head->prev);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == *(int*)list->head->data);
    ASSERT(1 == list->length);
}

void test_inserts_elements_at_end_of_the_linkList_for_integer(){
    int* nums = malloc(sizeof(int)*3);
    Node *result1,*result2;
    List *list = create();
    nums[0] = 1;nums[1] = 12;nums[2] = 14;
    insert(list,0, &nums[0]);	insert(list,1, &nums[1]);
    insert(list,2, &nums[2]);
    result1 = list->head->next;
    result2 = result1->next;
    ASSERT(3 == list->length);
    ASSERT(result1 == result2->prev);
    ASSERT(NULL == result2->next);
    ASSERT(14 == *(int*)result2->data);
};

void test_inserts_elements_at_end_of_the_linkList_for_float(){
    float* nums = malloc(sizeof(float)*3);
    Node *result1,*result2;
    List *list = create();
    nums[0] = 1.0f;nums[1] = 1.2f;nums[2] = 1.4f;
    insert(list,0, &nums[0]);	insert(list,1, &nums[1]);
    insert(list,2, &nums[2]);
    result1 = list->head->next;
    result2 = result1->next;
    ASSERT(3 == list->length);
    ASSERT(result1 == result2->prev);
    ASSERT(NULL == result2->next);
    ASSERT(1.4f == *(float*)result2->data);
};

void test_inserts_elements_at_end_of_the_linkList_for_double(){
    double* nums = malloc(sizeof(double)*3);
    Node *result1,*result2;
    List *list = create();
    nums[0] = 1.1;nums[1] = 1.2;nums[2] = 1.4;
    insert(list,0, &nums[0]);	insert(list,1, &nums[1]);
    insert(list,2, &nums[2]);
    result1 = list->head->next;
    result2 = result1->next;
    ASSERT(3 == list->length);
    ASSERT(result1 == result2->prev);
    ASSERT(NULL == result2->next);
    ASSERT(1.4 == *(double*)result2->data);
};

void test_inserts_element_in_between_linkList_integer(){
    Node *_2node,*_3node,*_4node;
    int* nums = malloc(sizeof(int)*3);
    List * list = create();
    nums[0] = 12;nums[1] = 14;nums[2] = 15;nums[3] = 20;
    insert(list, 0, nums+0); insert(list,1, nums+2);
    insert(list,2, nums+3);	insert(list,1, nums+1);
    _2node = list->head->next;
    _3node = _2node->next;	_4node = _3node->next;
    ASSERT(12 == *(int*)list->head->data);
    ASSERT(14 == *(int*)_2node->data);
    ASSERT(15 == *(int*)_3node->data);
    ASSERT(20 == *(int*)_4node->data);
};

void test_inserts_3_elements_in_linklist_for_integer(){
    int* nums = malloc(sizeof(int)*3);
    List *list = create();
    nums[0] = 1;nums[1] = 15;nums[2] = 35;
    insert(list,0, nums);	insert(list,0, nums+1);
    insert(list,0, nums+2);
    ASSERT(35 == *(int*)list->head->data);
    ASSERT(3 == list->length);
};

void test_inserts_the_doubles_in_the_linklist(){
    double* nums = malloc(sizeof(double)*3);
    List *list = create();
    nums[0] = 1.0;nums[1] = 2.0; nums[2] = 3.0;
    insert(list,0, &nums[0]);    insert(list,1, &nums[1]);
    insert(list,1, &nums[2]);
    ASSERT(3.0 == *(double*)list->head->next->data);
    ASSERT(3 == list->length);
};

void test_inserts_the_floats_in_the_linklist(){
    float* nums = malloc(sizeof(float)*3);
    List *list = create();
    nums[0] = 1.0;nums[1] = 2.0; nums[2] = 3.0;
    insert(list,0, &nums[0]);
    insert(list,1, &nums[1]);
    insert(list,1, &nums[2]);
    ASSERT(3.0 == *(float*)list->head->next->data);
    ASSERT(3 == list->length);
};

void test_inserts_the_characters_in_the_linklist(){
    char* data = malloc(sizeof(char)*3);
    List *list = create();
    data[0] = 'a';data[1] = 'b'; data[2] = 'c';
    insert(list,0, &data[0]);	insert(list,1, &data[1]);
    insert(list,1, &data[2]);
    ASSERT('c' == *(char*)list->head->next->data);
    ASSERT(3 == list->length);
};

void test_inserts_the_strings_in_the_linklist(){
    String* names = malloc(sizeof(String)*3);
    List *list = create();
    strcpy(names[0], "haalloo"); strcpy(names[1], "world");
    strcpy(names[2], "newww");
    insert(list,0, &names[0]);	insert(list,1, &names[1]);
    insert(list,1, &names[2]);
    ASSERT(0 == strcmp("newww",(char*)list->head->next->data));
    ASSERT(3 == list->length);
};

void test_inserts_the_structure_in_the_linklist(){
    Account* accounts = malloc(sizeof(Account)*3);
    List *list = create();
    accounts[0].acc_no = 45; accounts[0].balance = 450;
    accounts[1].acc_no = 11; accounts[1].balance = 2000;
    accounts[2].acc_no = 12; accounts[2].balance = 4000;
    insert(list,0, &accounts[0]);    insert(list,1, &accounts[1]);
    insert(list,1, &accounts[2]);
    ASSERT(areAccountsEqual(accounts[2], *(Account*)list->head->next->data));
    ASSERT(3 == list->length);
};

//-------------------------delete--------------------------------------------

void test_deletes_first_element_from_linked_list_with_1_element(){
    List* list;
    int* nums = malloc(sizeof(int));
    *nums = 5;
    list = create();
    insert(list,0, nums);
    ASSERT(deleteNode(list, 0));
    ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
}

void test_deletes_first_element_in_linked_list_from_3_elements(){
    List* list;
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 45;nums[1] = 15;nums[2] = 35;
    insert(list,0,&nums[0]);    insert(list,1,&nums[1]);
    insert(list,2,&nums[2]);
    ASSERT(deleteNode(list, 0));
    ASSERT(2 == list->length);
    ASSERT(15 == *(int*)list->head->data);
}
void test_deletes_element_in_between_of_linked_list(){
    List* list;
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 45;nums[1] = 15;nums[2] = 35;
    insert(list,0,&nums[0]);    insert(list,1,&nums[1]);
    insert(list,2,&nums[2]);
    ASSERT(deleteNode(list, 1));
    ASSERT(2 == list->length);
    ASSERT(35 == *(int*)list->head->next->data);
}

void test_deletes_last_element_from_the_linkList(){
    List* list;
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 45;nums[1] = 15;nums[2] = 35;
    insert(list,0,&nums[0]);    insert(list,1,&nums[1]);
    insert(list,2,&nums[2]);
    ASSERT(deleteNode(list, 2));
    ASSERT(2 == list->length);
    ASSERT(NULL == list->head->next->next);
}


void test_iterator(){
    List* list = create();
    Iterator it;
    int res;
    int data1 = 100,data2 = 200;
    void *element;
    res = insert(list,0,&data1);
    res = insert(list,1,&data2);
    it = getIterator(list);
    ASSERT(it.hasNext(&it));
    element = it.next(&it);
    ASSERT(100 == *(int*)element);
    element = it.next(&it);
    ASSERT(200 == *(int*)element);
    element = it.next(&it);
    ASSERT(NULL == element);
};