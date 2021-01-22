#include <stdio.h>
#include <stdlib.h>

#define IS_EQUAL(a, b) (a == b)

void beforeExit(void);

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
void insertNode(LinkedList* list, int data, int size);
void deleteNode(LinkedList* list, int size);

int getSize(LinkedList* list);


int main(void)
{
	LinkedList list;
	initList(&list);

	insertNode(&list, 1, 1);
	insertNode(&list, 2, 2);
	insertNode(&list, 3, 3);
	insertNode(&list, 4, 2);


	deleteNode(&list, 1);

	printf("hehe");

}

// C ����
// R �б�(��)
// U ����
// D ����

void initList(LinkedList* list)
{
	list->head = NULL;
	list->size = 0;
	atexit(beforeExit);
}

Node* createNode(int item, Node* next)
{
	Node* n = malloc(sizeof(Node));
	if (n == NULL)
	{
		atexit(beforeExit);
	}

	n->data = item;
	n->next = next;

	return n;
}


void readList(Node* root, int size)
{
	while (root != NULL)			// NULL�� ���� �� ���� ??	
	{
		root = root->next;

	//	if(root-> == size)	// next�� �ּ�
	//	{
	//		printf("%i\n", root->data);
	//	}
	}
} // �̿�

void insertNode(LinkedList* list, int data, int size)
{
	if (size < 1 || size >(list->size) + 1)
	{
		printf("Insert�� �Ұ����� ��ġ�Դϴ�.");
		exit(1);
	}

	Node* n = createNode(data, NULL);

	if(size == 1)
	{
		n->next = list->head;

		list->head = n;
	}
	else
	{
		Node* tmp = list->head;		// �� ������ ����
		for(int i = 0; i < size - 2; i++)	// zero base�� ���ô�. 1 base ����.
		{
			tmp = tmp->next;
		}

		n->next = tmp->next;		// �հ� ����
		tmp->next = n;
	}
	(list->size)++;
}

void deleteNode(LinkedList* list, int size)
{
	if(size < 1 || size >(list->size) + 1)
	{
		printf("Delete�� �Ұ����� ��ġ�Դϴ�.");
		exit(1);
	}
	
	Node* tmp = list->head;

	if(size == 1)
	{
		list->head = tmp->next;

		free(tmp);
		(list->size)--;
	}
	else
	{
		for(int i = 0; i < size - 1; i++)
		{
			list->head->next;
			printf("%p\n", list->head->next);
		}
	}
}

// update , creat �Բ�
// delete�� read �Բ�

int getSize(LinkedList* list)
{
	//while ( != NULL)
	{
		
	}

	// list->next�� null�� ���� �� ����
	// �ݺ��Ͽ� size�� �ִ´�.
	// �װ� ����

	return 1;
} // �̿�


void beforeExit(void)
{
	printf("exit() is called\n");
}


/*
* 
	Node* n = malloc(sizeof(Node));
	if (n == NULL)
	{
		return 1;
	}

	n->data = item;
	n->next = next;

	
* 
* 
* 
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
