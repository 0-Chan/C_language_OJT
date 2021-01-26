/* Goal : Programming stack CRUD in C
 * date : 2021. 01 . 26
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

void push(LinkedList* stack, int data);
int readTop(LinkedList* stack);
int pop(LinkedList* stack);


int main(void)
{
    int element = 0;

    LinkedList stack;
    initList(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    element = readTop(&stack);
    printf("%d\n", element);
}
    

void push(LinkedList* stack, int data)
{
    int errorCode = 0;
    errorCode = insertNode(stack, stack->size, data);
}

int readTop(LinkedList* stack)
{
    int val = 0;
    Node* tmp = stack->head;
    
    for (int i = 1; i < stack->size; i++)
    {
        tmp = tmp->next;

    }
    
    val = tmp->data;    
    return val;
}

int pop(LinkedList* stack)
{
    int val = 0;



    return val;
}