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
    // 인섯트노드 끝 자리에다가
    // tail 교체
    return errorCode;
}
int deQueue(queue* q, int* data)
{
    int errorCode = 0;
    int front;

    // 비어있는 queue 아닌지?? (isEmpty 활용)
    // 비어있었다면 return 6 (비어있는 큐)

    // *data = 맨 앞 노드 read 하고
    // 그 노드 딜리트
    // front 교체
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