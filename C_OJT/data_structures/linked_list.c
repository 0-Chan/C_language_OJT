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

// C 생성
// R 읽기(값)
// U 수정
// D 삭제

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
	while (root != NULL)			// NULL을 만날 때 까지 ??	
	{
		root = root->next;

	//	if(root-> == size)	// next는 주소
	//	{
	//		printf("%i\n", root->data);
	//	}
	}
} // 미완

void insertNode(LinkedList* list, int data, int size)
{
	if (size < 1 || size >(list->size) + 1)
	{
		printf("Insert가 불가능한 위치입니다.");
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
		Node* tmp = list->head;		// 한 바퀴를 더감
		for(int i = 0; i < size - 2; i++)	// zero base로 갑시다. 1 base 말고.
		{
			tmp = tmp->next;
		}

		n->next = tmp->next;		// 먼가 꼬임
		tmp->next = n;
	}
	(list->size)++;
}

void deleteNode(LinkedList* list, int size)
{
	if(size < 1 || size >(list->size) + 1)
	{
		printf("Delete이 불가능한 위치입니다.");
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

// update , creat 함께
// delete와 read 함께

int getSize(LinkedList* list)
{
	//while ( != NULL)
	{
		
	}

	// list->next가 null을 만날 때 까지
	// 반복하여 size에 넣는다.
	// 그걸 리턴

	return 1;
} // 미완


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
