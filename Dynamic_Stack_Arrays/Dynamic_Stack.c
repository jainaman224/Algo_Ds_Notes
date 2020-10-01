
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
}Stack;
 
Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 

int Full(Stack* stack)
{   return stack->top == stack->capacity - 1; }

int Empty(Stack* stack)
{   return stack->top == -1;  }
void push(Stack* stack, int item)
{
    if (Full(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
int peek(Stack* stack)
{
    if (Empty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
int main()
{
    Stack* stack = createStack(100);
 
    push(stack, 14);
    push(stack, 25);
    push(stack, 38);
    push(stack, 48);
 
    printf("%d popped from stack\n", pop(stack));
 
    printf("Top item is %d\n", peek(stack));
 
    return 0;
}
//output
/*14 pushed to stack
25 pushed to stack
38 pushed to stack
48 pushed to stack
48 popped from stack
Top item is 38*/
