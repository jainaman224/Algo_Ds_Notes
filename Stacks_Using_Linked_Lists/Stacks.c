// C program to implement stack using linked list
#include<stdio.h>
struct stack
{
    int top;
    int data[100];
} Stack; 

int count = 0;

// Function to push element to stack
void push(struct stack *s, int value, int n)
{
    if (s -> top == n-1)
    {
        printf("\nStack is full");
    }
    else 
    {
        s -> top++;
        s -> data[s -> top] = value;
    }
    count++;	
}

// Function to pop element from stack 
void pop(struct stack *s)
{
    if (s -> top == -1)
        printf("\nThe stack is empty");
    else
    {
        int value;
        value = s -> data[s -> top];
        printf("\nThe poped value is %d", value);
        s -> top--;
    }
    count--;
}

// function to check if the stack is empty or not
int isEmpty(struct stack *s) 
{ 
    return s -> top == NULL; 
} 
  
// function to return top element in a stack 
int peek(struct stack *s) 
{ 
    //check for empty stack 
    if (!isEmpty(s -> top)) 
        return s -> data[s -> top]; 
    else
        exit(1); 
} 

// Function to print stack 
void printStack(struct stack *s)
{
    if (Stack.top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nThe current stack is\n");
        for (int i = 0; i <= Stack.top; i++)
        printf("%d\t", s -> data[i]);
    }
}

// Function to print size of stack
void size(struct stack *s)
{
    printf("\nSize of stack is %d", count);
}  

// Main function
void main()
{
    struct stack *s;
    s = &Stack;
    Stack.top = -1;
    int c, value, k, n;
    printf("\nEnter the number of elements");
    scanf("%d", &n);
    do
    {
        printf("\nWhich operation to perform \n 1.Push \n 2.Pop \n 3.Check empty or not");
        printf("\n 4.Print top element \n 5.Display stack \n 6.Size");	 // Menu Driven Programming
        printf("\nEnter choice");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("\nEnter value to push ");
            scanf("%d", &value);
            push(s, value, n);
        }
        else if (c == 2)
        {
            pop(s);
        }
        else if (c == 3)
        {
            if (!isEmpty(s))
                printf("\nStack is not empty");
            else
                printf("\nStack is empty");
        }
        else if (c == 4)
        {
            printf("\nThe topmost element is ");
            peek(s);
        }
        else if (c == 5)
        {
            printStack(s);
        }
        else if (c == 6)
        {
            size(s);
        }
        printf("\nDo u want to continue(1/0)");
        scanf("%d", &k);
    } while (k != 0);
    printf("\n");
}

/*
Sample output:

Enter the number of elements 4
Which operation to perform 
1.Push
2.Pop 
3.Check empty or not 
4.Print top element 
5.Display stack 
6.Size
Enter choice 1
Enter the value to push 3
Do u want to continue(1/0) 1
Which operation to perform 
1.Push
2.Pop
3.Check empty or not 
4.Print top element 
5.Display stack 
6.Size
Enter choice 2
The popped value is 3
Do u want to continue(1/0) 1
Which operation to perform 
1.Push
2.Pop
3.Check empty or not  
4.Print top element 
5.Display stack 
6.Size
Enter choice 5
Stack is empty

*/
