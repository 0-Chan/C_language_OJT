#include <stdio.h>
#include <stdlib.h>

#define IS_EQUAL(a, b) (a == b)

void beforeExit();

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

typedef struct
{
	Node *head;
	int index;
} LinkedList;

Node* createList(void);
void readList(Node* root, int index);
void insertNode(LinkedList* list, int data, int index);
void deleteNode(Node** root, int index);

int getSize(LinkedList* list);


int main(void)
{

}

// C ����
// R �б�(��)
// U ����
// D ����

Node* createList(int item, Node* next)
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

void readList(Node* root, int index)
{
	while (root != NULL)			// NULL�� ���� �� ���� ??	
	{
		root = root->next;

		if(root-> == index)	// next�� �ּ�
		{
			printf("%i\n", root->data);
		}
	}
}

void insertNode(LinkedList* list, int data, int index)
{
	if (index < 1 || index >(list->index) + 1)
	{
		printf("Insert�� �Ұ����� ��ġ�Դϴ�.");
		return 1;
	}

	Node* n = createList(data, NULL);

	if (index == 1)
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
	(list->index)++;
}

void deleteNode(Node** root, int index)
{

}


int getSize(LinkedList* list);
{
	while ( != NULL)
	{
		
	}

	// list->next�� null�� ���� �� ����
	// �ݺ��Ͽ� size�� �ִ´�.
	// �װ� ����

	return;
}


void beforeExit()
{
	printf("exit() is called\n");
}


/*
Node * convertToList(int* arr, int arrLength)
{
	Node* root = NULL;
	for (int i = arrLength - 1; i >= 0; i--)
	{
		insertNode(&root, arr[i]);
	}
	return root;
}

void display(Node* root)
{
	while (root != NULL)
	{
		printf("%i\n", root->data);
		root = root->next;
	}
}
*/
