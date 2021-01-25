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
void updateNode(LinkedList* list, int index, int data);
void insertNode(LinkedList* list, int index, int data);
void deleteNode(LinkedList* list, int index);


int main(void)
{
	int data = 0;
	LinkedList list;
	initList(&list);

	insertNode(&list, 0, 1);
	insertNode(&list, 1, 2);
	insertNode(&list, 2, 3);
	insertNode(&list, 3, 4);


	for (int i = 0, n = list.size; i < n; i++)
	{
		data = readList(&list, i);
		printf("%i\n", data);
	}

	printf("\n");

	updateNode(&list, 2, 1);

//	deleteNode(&list, 2);
	
	for(int i = 0, n = list.size; i < n; i++)
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
		exit(1);
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

void updateNode(LinkedList* list, int index, int data)
{
	if(index < 0 || index > (list->size) + 1)
	{
		printf("Update가 불가능한 위치입니다.");
		exit(1);
	}

	int i = 0;
	Node* tmp = list->head;

	while(tmp != NULL)
	{
		if(i == index)
		{
			tmp->data = data;
			return;
		}

		tmp = tmp->next;
		i++;
	}
}

void insertNode(LinkedList* list, int index, int data)
{
	if(index < 0 || index > (list->size) + 1)
	{
		printf("Insert가 불가능한 위치입니다.");
		exit(1);
	}

	Node* n = createNode(data, NULL);

	if(index == 0)
	{
		n->next = list->head;
		list->head = n;
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

void deleteNode(LinkedList* list, int index)
{
	if(index < 0 || index > (list->size) + 1)
	{
		printf("Delete이 불가능한 위치입니다.");
		exit(1);
	}
	
	int i = 0;
	Node* tmp = list->head;
	Node* n = NULL;

	if(index == 0)
	{
		list->head = tmp->next;

		free(tmp);
		(list->size)--;
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
				return;
			}
			tmp = tmp->next;
			i++;
		}
	}
}