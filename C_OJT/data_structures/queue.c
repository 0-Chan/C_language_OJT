/* Goal : Programming queue CRUD in C
 * date : 2021. 01 . 28
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include "linkedList.h"

int enQueue(LinkedList* queue, int val);
int deQueue(LinkedList* queue, int* data);

int peek(LinkedList* queue);

int main(void)
{
    int data = 0;
    int errorCode = 0;
    LinkedList queue;
    initList(&queue);

    for (int i = 0; i < 5; i++)
    {
        errorCode = enQueue(&queue, i);
        errorCheck(errorCode);

        data = peek(&queue);
        printf("%d\n", data);
    }
  
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        errorCode = deQueue(&queue, &data);
        errorCheck(errorCode);

        printf("%d\n", data);
    }
}


int enQueue(LinkedList* queue, int val)
{
    int errorCode = 0;
    int tail = (queue->size);

    errorCode = insertNode(queue, tail, val);  
  
    return errorCode;
}

int deQueue(LinkedList* queue, int* data)
{
    int errorCode = 0;
    int front = 0;
    if ((queue->size) == 0)
    {
        errorCode = 6;
        return errorCode;
    }

    *data = readList(queue, front);
    errorCode = deleteNode(queue, front);

    return errorCode;   
}

int peek(LinkedList* queue)  // ¿Ï
{
    int data = 0;
    Node* tmp = queue->head;
    
    data = tmp->data;

    return data;
}