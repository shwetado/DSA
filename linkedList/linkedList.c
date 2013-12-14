#include "linkedList.h"
#include <stdlib.h>

List* create(){
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;
	return list;
};

Node* createNode(Node *prev, Node *next){
  	Node *newNode = malloc(sizeof(Node));
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
};

int insertFirst(List *list, Node *newNode, Node *head,void *data){
	newNode = createNode(NULL, NULL);
    if(NULL != head){
        newNode->next = head;
        head->prev = newNode;
    }
    list->head = newNode;
    newNode->data = data;
    list->length++;
    return 1;
};

int insertLast(List *list, Node *newNode, Node *head,void *data){
	newNode = createNode(head, NULL);
    head->next = newNode;
    newNode->data = data;
    list->length++;
    return 1;
};

int insertInBetween(List *list, Node *newNode, Node *head,void *data){
	newNode = createNode(head->prev, head);
    head->prev->next = newNode;
    newNode->data = data;
    list->length++;
    return 1;
};

int insert(List *list, int index, void *data){
    Node *head,*newNode;
    int i;
    if(index <= -1 || index > list->length)
        return 0;
    head = list->head;
    for (i = 0; i < index ; ++i){
        if(head->next != NULL)
            head = head->next;
    }

    if(index == 0)
    	return insertFirst(list,newNode,head,data);
    return (index == list->length)?
        insertLast(list,newNode,head,data):
	    insertInBetween(list,newNode,head,data);
};

int deleteLast(Node* head, List* list){
    head->prev->next = NULL;
    list->length--;
    return 1;
};

int deleteFirst(Node* head, List* list){
    list->head = list->head->next;
    list->length--;
    return 1;
}
int deleteNode(List* list,int index){
    int i;
    Node *head, *deletedNode;
    if(index <= -1 || index >= list->length)
        return 0;
    head = list->head;
    for(i = 0; i < index ;i++)
        head = head->next;
    if(i == 0)
        deleteFirst(head, list);
    else if(i == list->length-1)
        deleteLast(head, list);
    else{
        head->prev->next = head->next;
        head->next->prev = head->prev;
        list->length--;
    }
    free(head);
    return 1;
};