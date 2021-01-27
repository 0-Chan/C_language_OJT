/* Goal : Programming queue CRUD in C
 * date : 2021. 01 . 28
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include "linkedList.h"

typedef struct
{
    Node* front;
    Node* tail;
    int size;
} queue;

void initQueue(queue* q);

int enQueue(queue* q, int* val);
int deQueue(queue* q, int* data);

int peek(queue* q);
int isEmpty(queue* q);

int main(void)
{
    int data = 0;
    int errorCode = 0;

    queue q;
    initQueue(&q);
}


void initQueue(queue* q)
{
    q->front = NULL;
    q->tail = NULL;
    q->size = 0;
}

int enQueue(queue* q, int* val)
{
    int errorCode = 0;
    int tail = (q->size);

    Node* n = createNode(val, NULL);
    if (n == 1)
    {
        errorCode = 1;
        return errorCode;
    }

    errorCode = insertNode(list, tail, val);
    // �μ�Ʈ��� �� �ڸ����ٰ�
    // tail ��ü
    return errorCode;
}
int deQueue(queue* q, int* data)
{
    int errorCode = 0;
    int front;

    // ����ִ� queue �ƴ���?? (isEmpty Ȱ��)
    // ����־��ٸ� return 6 (����ִ� ť)

    // *data = �� �� ��� read �ϰ�
    // �� ��� ����Ʈ
    // front ��ü
    return errorCode;
}

int peek(queue* q)
{
    int data = 0;

    return data;
}
int isEmpty(queue* q)
{
    if ((q->front == NULL) || (q->tail == NULL))
    {
        return 1;
    }
}