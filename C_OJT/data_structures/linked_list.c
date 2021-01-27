/* Goal : Implementing CRUD using linked list in C
 * date : 2021. 01 . 26
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

//int main(void)
//{
//	int data = 0;
//	int errorCode = 0;
//	LinkedList list;
//	initList(&list);
//	errorCode = insertNode(&list, 0, 1);
//	errorCheck(errorCode);
//	errorCode = insertNode(&list, 1, 2);
//	errorCheck(errorCode);
//	errorCode = insertNode(&list, 2, 3);
//	errorCheck(errorCode);
//	errorCode = insertNode(&list, 3, 4);
//	errorCheck(errorCode);
//	for (int i = 0; i < list.size; i++)
//	{
//		data = readList(&list, i);
//		printf("%i\n", data);
//	}
//	errorCode = updateNode(&list, 1, 1);
//	errorCheck(errorCode);
//	errorCode = deleteNode(&list, 2);
//	errorCheck(errorCode);
//
//	for (int i = 0, n = list.size; i < n; i++)
//		for (int i = 0; i < list.size; i++)
//		{
//			data = readList(&list, i);
//			printf("%i\n", data);
//		}
//}

void initList(LinkedList* list)
{
	list->head = NULL;
	list->size = 0;
}

Node* createNode(int item, Node* next)
{
	Node* n = malloc(sizeof(Node));
	if (n == NULL)
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

	while (tmp != NULL)
	{
		if (i == index)
		{
			data = tmp->data;
			return data;
		}

		tmp = tmp->next;
		i++;
	}
	return;
}

int insertNode(LinkedList* list, int index, int data)
{
	if (index < 0 || index > (list->size))
	{
		return 3;
	}
	int i = 0;
	Node* n = createNode(data, NULL);
	Node* tmp = list->head;

	if (index == 0)
	{
		n->next = list->head;
		list->head = n;
		(list->size)++;
		return 0;
	}
	else
	{
		while ((tmp != NULL) || (i == index))
		{
			if (tmp->next == NULL)
			{
				tmp->next = n;
				(list->size)++;
				return 0;
			}
			else if (i == index)
			{
				n->next = tmp->next;
				tmp->next = n;
				(list->size)++;
				return 0;
			}
			tmp = tmp->next;
			i++;
		}
	}
}

int updateNode(LinkedList* list, int index, int data)
{
	if (index < 0 || index > (list->size))
	{
		return 2;
	}

	int i = 0;
	Node* tmp = list->head;

	while (tmp != NULL)
	{
		if (i == index)
		{
			tmp->data = data;
			return 0;
		}

		tmp = tmp->next;
		i++;
	}
}

int deleteNode(LinkedList* list, int index)
{
	if (index < 0 || index > (list->size))
	{
		return 4;
	}

	int i = 0;
	Node* tmp = list->head;
	Node* n = NULL;

	if (index == 0)
	{
		list->head = tmp->next;

		free(tmp);
		(list->size)--;
		return 0;
	}
	else
	{
		while (tmp != NULL)
		{
			if (tmp->next == NULL)
			{
				n = tmp;

				tmp = tmp->next;

				free(tmp);
				(list->size)--;
				return 0;
			}
			else if (i == index)
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
	switch (errorCode)
	{
	case 0:
		break;
	case 1:
		printf("createNode 에러 : malloc에 실패하였습니다.");
		exit(1);
	case 2:
		printf("updateNode 에러 : 매개변수 index 값을 확인해 주십시오.");
		exit(1);
	case 3:
		printf("insertNode 에러 : 매개변수 index 값을 확인해 주십시오.");
		exit(1);
	case 4:
		printf("deleteNode 에러 : 매개변수 index 값을 확인해 주십시오.");
		exit(1);
	case 5:
		printf("Pop 에러 : Stack underflow 발생.");
		exit(1);
	default:
		printf("Undefined error code. Please check again.");
		break;
	}
}
