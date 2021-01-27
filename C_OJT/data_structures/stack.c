/* Goal : Programming stack CRUD in C
 * date : 2021. 01 . 27
 * author : Young Chan Kim (CogaPlex)
 */

#include <stdio.h>
#include <stdbool.h>
#include "linkedList.h"

int push(LinkedList* stack, int data);
int pop(LinkedList* stack, int* val);
int readTop(LinkedList* stack);


int main(void)
{
    int val = 0;
    int errorCode = 0;

    LinkedList stack;
    initList(&stack);

    for (int i = 0; i < 1; i++)
    {
        errorCode = push(&stack, i);
        errorCheck(errorCode);

        val = readTop(&stack);
        printf("%d\n", val);
    }

    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        errorCode = pop(&stack, &val);
        errorCheck(errorCode);

        printf("%d\n", val);
    }
}
    

int push(LinkedList* stack, int data)
{
    int errorCode = 0;
    int top = (stack->size);

    errorCode = insertNode(stack, top, data);
   
    return errorCode;
}

int pop(LinkedList* stack, int* val)
{
    int errorCode = 0;
    int top = (stack->size) - 1;

    if (stack->size == 0)
    {
        return 5;
    }
    else
    {
        *val = readTop(stack);
        errorCode = deleteNode(stack, top);
    }

    return errorCode;
}

int readTop(LinkedList* stack)
{
    int val = 0;
    int top = (stack->size) - 1;
    val = readList(stack, top);
 
   return val;
}