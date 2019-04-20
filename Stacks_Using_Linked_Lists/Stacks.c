/* C program to implement stack using linked list*/

#include<stdio.h>
struct stack
{
int top;
int data[100];
}Stack; 

/*Function to push element to stack */
void PUSH(struct stack *s,int value,int n)
{
    if(s->top==n-1)
    {
    printf("\nStack is full");
    }
    else 
    {s->top++;
     s->data[s->top]=value;
    }
}

/*Function to pop element from stack */
void POP(struct stack *s)
{
    if(s->top==-1)
    printf("\nThe stack is empty");
    else
    {
    int value;
    value=s->data[s->top];
    printf("\nThe poped value is %d",value);
    s->top--;
    }
}
/* Main function */
void main()
{
    struct stack *s;
    s=&Stack;
    Stack.top=-1;
    int c,value,k,n;
    printf("\nEnter the number of elements");
    scanf("%d",&n);
    do
    {
    printf("\nWhich operation to perform 1.PUSH 2.POP");	 /* Menu Driven Programming */
    printf("\nEnter choice");
    scanf("%d",&c);
    if(c==1)
    {
     printf("\nEnter value to push ");
     scanf("%d",&value);
     PUSH(s,value,n);
    }
    else if(c==2)
    {
 	POP(s);
    }
    else
    {break;
    }
    printf("\nDo u want to continue(1/0)");
    scanf("%d",&k);
    }while(k!=0);
	
    if(Stack.top==-1)
    {printf("\nStack is empty");
    }
    else
    {
    printf("\nThe current stack is ");
    for(int i=0;i<=Stack.top;i++)
    printf("%d\t",s->data[i]);
    }
printf("\n");
}

/*
Sample output:

Enter the number of elements 4
Which operation to perform 1.PUSH 2.POP
Enter choice 1
Enter the value to push 3
Do u want to continue(1/0) 1
Which operation to perform 1.PUSH 2.POP
Enter choice 2
The popped value is 3
Do u want to continue(1/0) 0
Stack is empty

*/
