#include "../linked-list/linkedList.h"
typedef struct treeNode {
    void* data;
    struct treeNode* parent;
    List* list;
} TreeNode;