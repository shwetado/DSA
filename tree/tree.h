#include "iterator.h"
typedef int (*compareFunc)(void* first,void* second);
typedef struct {
    void* root;
    compareFunc compare;
} Tree;
Tree createTree(compareFunc compare);
int insertTreeNode(Tree* tree,void* parent,void* data);
Iterator getChildren(Tree *tree,void* parent);        
int search(void* tree,void* parent);
int deleteTreeNode(Tree* tree, void* data);