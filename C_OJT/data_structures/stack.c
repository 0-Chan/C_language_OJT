/* Goal : Programming stack CRUD in C
 * date : 2021. 01 . 27
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"

int push(LinkedList* stack, int data);
int readTop(LinkedList* stack);
int pop(LinkedList* stack, int* errorCode);


int main(void)
{
    int element = 0;
    int errorCode = 0;

    LinkedList stack;
    initList(&stack);


    for (int i = 0; i < 3; i++)
    {
        errorCode = push(&stack, i);
        errorCheck(errorCode);

        element = readTop(&stack);
        printf("%d\n", element);
    }

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        element = pop(&stack, &errorCode);
        errorCheck(errorCode);

        printf("%d\n", element);
    }
}
    

int push(LinkedList* stack, int data)
{
    int errorCode = 0;
    errorCode = insertNode(stack, stack->size, data);
   
    return errorCode;
}

int readTop(LinkedList* stack)
{
    int val = 0;
    val = readList(stack, stack->size);
    return val;
}

int pop(LinkedList* stack, int* errorCode)
{
    int val = 0;

    if (stack->size == 0 )
    {
        *errorCode = 5;
    }
    else
    {
        val = readTop(stack);
        *errorCode = deleteNode(stack, stack->size);
    }
    
    return val;
}