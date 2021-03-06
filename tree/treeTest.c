#include "testUtils.h"
#include "tree.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmpInt(void* first,void* second){
    return *(int*)first - *(int*)second;
};

void test_insert_first_node(){
    Tree tree = createTree(cmpInt);
    Iterator it;
    void *element;
    int element1 =10;
    ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
    it = getChildren(&tree,NULL);
    element = it.next(&it);
    ASSERT(*(int*)element == element1);
};

void test_insert_two_nodes_one_root_and_a_child(){
    Tree tree = createTree(cmpInt);
    Iterator it;
    int element1 = 10,element2 = 20;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    it = getChildren(&tree,&element1);
    ASSERT(element2 == *(int*)it.next(&it));
    ASSERT(NULL == it.next(&it));
};

void test_insert_three_nodes(){
    Tree tree = createTree(cmpInt);
    Iterator it;
    int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    insertTreeNode(&tree,&element1,&element3);
    insertTreeNode(&tree,&element1,&element4);
    it = getChildren(&tree,&element1);
    ASSERT(element4 == *(int*)it.next(&it));
    ASSERT(element3 == *(int*)it.next(&it));
    ASSERT(element2 == *(int*)it.next(&it));
};

void test_insert_node_at_depth_two(){
    Tree tree = createTree(cmpInt);
    void * element;
    Iterator it;
    int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    insertTreeNode(&tree,&element2,&element3);
    it = getChildren(&tree, &element2);
    insertTreeNode(&tree,&element2,&element4);
    it = getChildren(&tree,&element2);
    ASSERT(element4 == *(int*)it.next(&it));
    ASSERT(element3 == *(int*)it.next(&it));
};

void test_search_root_node(){
    Tree tree = createTree(cmpInt);
    int element1 =10;
    ASSERT(1 == insertTreeNode(&tree,NULL,&element1));
    ASSERT(1 == search(&tree,&element1));
};

void test_search_nodes_depth_one(){
    Tree tree = createTree(cmpInt);
    int element1 = 10,element2 = 20,element3 = 30;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    insertTreeNode(&tree,&element1,&element3);
    ASSERT(1 == search(&tree,&element2));
    ASSERT(1 == search(&tree,&element3));
};

void test_search_at_depth_two(){
    Tree tree = createTree(cmpInt);
    int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    insertTreeNode(&tree,&element2,&element3);
    insertTreeNode(&tree,&element2,&element4);
    ASSERT(1 == search(&tree,&element3));
    ASSERT(1 == search(&tree,&element4));
};

void test_delete_a_node_from_tree(){
    Tree tree = createTree(cmpInt);
    int element1 = 10,element2 = 20,element3 = 30,element4 = 40;
    insertTreeNode(&tree,NULL,&element1);
    insertTreeNode(&tree,&element1,&element2);
    insertTreeNode(&tree,&element2,&element3);
    insertTreeNode(&tree,&element2,&element4);
    ASSERT(1 == deleteTreeNode(&tree, &element4));
    ASSERT(0 == search(&tree,&element4));
};