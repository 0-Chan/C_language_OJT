/* Goal : Implementing CRUD using linked list in C
 * date : 2021. 01 . 25 
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

typedef struct
{
	Node *head;
	int size;
} LinkedList;

void initList(LinkedList *list);
Node* createNode(int item, Node* next);
int readList(LinkedList* list, int index);
int updateNode(LinkedList* list, int index, int data);
int insertNode(LinkedList* list, int index, int data);
int deleteNode(LinkedList* list, int index);

void errorCheck(int errorCode);

int main(void)
{
	int data = 0;
	int errorCode = 0;
	LinkedList list;
	initList(&list);

	insertNode(&list, 0, 1);
	insertNode(&list, 1, 2);
	insertNode(&list, 2, 3);
	insertNode(&list, 3, 4);

	for (int i = 0, n = list.size+1; i < n; i++)
	{
		data = readList(&list, i);
		printf("%i\n", data);
	}

	printf("\n");

	errorCode = updateNode(&list, 2, 1);
	errorCheck(errorCode);


	errorCode = deleteNode(&list, 2);
	errorCheck(errorCode);
	
	for(int i = 0, n = list.size+1; i < n; i++)
	{
		data = readList(&list, i);
		printf("%i\n", data);
	}
}


void initList(LinkedList* list)
{
	list->head = NULL;
	list->size = 0;
}

Node* createNode(int item, Node* next)
{
	Node* n = malloc(sizeof(Node));
	if(n == NULL)
	{
		return 1;
	}

	n->data = item;
	n->next = next;

	return n;
}

int readList(LinkedList* list, int index)
{
	int i = 0;
	int data = 0;
	Node* tmp = list->head;

	while(tmp != NULL)
	{
		if(i == index)
		{
			data = tmp->data;
			return data;
		}

		tmp = tmp->next;
		i++;
	}
}

int updateNode(LinkedList* list, int index, int data)
{
	if(index < 0 || index > (list->size) + 1)
	{
		return 2;
	}

	int i = 0;
	Node* tmp = list->head;

	while(tmp != NULL)
	{
		if(i == index)
		{
			tmp->data = data;
			return 0;
		}

		tmp = tmp->next;
		i++;
	}
}

int insertNode(LinkedList* list, int index, int data)
{
	if(index < 0 || index > (list->size) + 1)
	{
		return 3;
	}

	Node* n = createNode(data, NULL);

	if(index == 0)
	{
		n->next = list->head;
		list->head = n;

		return 0;
	}
	else
	{
		Node* tmp = list->head;
		for(int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}

		n->next = tmp->next;
		tmp->next = n;
	}
	(list->size)++;
}

int deleteNode(LinkedList* list, int index)
{
	if(index < 0 || index > (list->size) + 1)
	{
		return 4;
	}
	
	int i = 0;
	Node* tmp = list->head;
	Node* n = NULL;

	if(index == 0)
	{
		list->head = tmp->next;

		free(tmp);
		(list->size)--;
		return 0;
	}
	else
	{
		while(tmp != NULL)
		{
			if(i == index - 1)
			{
				n = tmp;
				tmp = tmp->next;

				n->next = tmp->next;

				free(tmp);
				(list->size)--;
				return 0;
			}
			tmp = tmp->next;
			i++;
		}
	}
}

void errorCheck(int errorCode)
{
	switch(errorCode)
	{
		case 0 :
			return;
		case 1 :
			printf("createNode 에러 : malloc에 실패하였습니다.");
			exit(1);
		case 2 :
			printf("updateNode 에러 : 매개변수 index 값을 확인해 주십시오.");
			exit(1);
		case 3 :
			printf("insertNode 에러 : 매개변수 index 값을 확인해 주십시오.");
			exit(1);
		case 4 :
			printf("deleteNode 에러 : 매개변수 index 값을 확인해 주십시오.");
			exit(1);
	}
}