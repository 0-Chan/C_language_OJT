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
void readList(Node* root, int size);
void updateNode(LinkedList* list, int size, int data);
void insertNode(LinkedList* list, int size, int data);
void deleteNode(LinkedList* list, int size);

int getSize(LinkedList* list);
void beforeExit(void);


int main(void)
{
	LinkedList list;
	initList(&list);

	insertNode(&list, 0, 1);
	insertNode(&list, 1, 2);
	insertNode(&list, 2, 3);
	insertNode(&list, 3, 4);

	readList(&list, 0);
	readList(&list, 1);
	readList(&list, 2);
	readList(&list, 3);

	printf("\n");

//	updateNode(&list, 2, 1);

	deleteNode(&list, 2);
	
	for(int i = 0, n = getSize(&list); i < n; i++)
	{
		readList(&list, i);
	}
}


void initList(LinkedList* list)
{
	list->head = NULL;
	list->size = 0;
	atexit(beforeExit);
}

Node* createNode(int item, Node* next)
{
	Node* n = malloc(sizeof(Node));
	if(n == NULL)
	{
		atexit(beforeExit);
	}

	n->data = item;
	n->next = next;

	return n;
}

void readList(LinkedList* list, int size)
{
	int i = 0;
	Node* tmp = list->head;

	while(tmp != NULL)
	{
		if(i == size)
		{
			printf("%i\n", tmp->data);
			return 0;
		}

		tmp = tmp->next;
		i++;
	}
}

void updateNode(LinkedList* list, int size, int data)
{
	if(size < 0 || size > (list->size) + 1)
	{
		printf("Update가 불가능한 위치입니다.");
		atexit(beforeExit);
	}

	int i = 0;
	Node* tmp = list->head;

	while(tmp != NULL)
	{
		if(i == size)
		{
			tmp->data = data;
			return 0;
		}

		tmp = tmp->next;
		i++;
	}
}

void insertNode(LinkedList* list, int size, int data)
{
	if(size < 0 || size > (list->size) + 1)
	{
		printf("Insert가 불가능한 위치입니다.");
		atexit(beforeExit);
	}

	Node* n = createNode(data, NULL);

	if(size == 0)
	{
		n->next = list->head;
		list->head = n;
	}
	else
	{
		Node* tmp = list->head;
		for(int i = 0; i < size - 1; i++)
		{
			tmp = tmp->next;
		}

		n->next = tmp->next;
		tmp->next = n;
	}
	(list->size)++;
}

void deleteNode(LinkedList* list, int size)
{
	if(size < 0 || size > (list->size) + 1)
	{
		printf("Delete이 불가능한 위치입니다.");
		atexit(beforeExit);
	}
	
	int i = 0;
	Node* tmp = list->head;
	Node* n = NULL;

	if(size == 0)
	{
		list->head = tmp->next;

		free(tmp);
		(list->size)--;
	}
	else
	{
		while(tmp != NULL)
		{
			if(i == size - 1)
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

int getSize(LinkedList* list)
{
	Node* tmp = list->head;
	int size = 0;

	while(tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}

	return size;
}

void beforeExit(void)
{
	printf("exit() is called\n");
}