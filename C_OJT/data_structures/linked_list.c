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

// C 생성
// R 읽기(값)
// U 수정
// D 삭제

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
	while (root != NULL)			// NULL을 만날 때 까지 ??	
	{
		root = root->next;

		if(root-> == index)	// next는 주소
		{
			printf("%i\n", root->data);
		}
	}
}

void insertNode(LinkedList* list, int data, int index)
{
	if (index < 1 || index >(list->index) + 1)
	{
		printf("Insert가 불가능한 위치입니다.");
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

	// list->next가 null을 만날 때 까지
	// 반복하여 size에 넣는다.
	// 그걸 리턴

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
