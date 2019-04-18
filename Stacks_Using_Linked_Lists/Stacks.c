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
	 {int value;
	  value=s->data[s->top];
	  printf("\nThe poped value is %d",value);
	  s->top--;
	 }
}


