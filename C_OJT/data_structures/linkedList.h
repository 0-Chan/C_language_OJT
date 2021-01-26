#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

typedef struct
{
	Node* head;
	int size;
} LinkedList;

void initList(LinkedList* list);
Node* createNode(int item, Node* next);
int readList(LinkedList* list, int index);
int insertNode(LinkedList* list, int index, int data);
int updateNode(LinkedList* list, int index, int data);
int deleteNode(LinkedList* list, int index);

void errorCheck(int errorCode);

#endif