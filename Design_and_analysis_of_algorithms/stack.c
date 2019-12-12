#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};

struct node *top=NULL,*root=NULL,*curr=NULL;
void print()
{
	printf("Linked list is:\n");
	
	for(curr=root;curr!=NULL;curr=curr->next)
	{
		printf("%d\t",curr->value);
	}
	printf("\n");
}
void push()
{
	struct node* addr;
	int data;
	addr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the integer:\t");
	scanf("%d",&data);
	
	if(root == NULL)
	{
		root=addr;
		top=root;
		root->value=data;
		root->next=NULL;
		
	}
	else
	{
		top->next=addr;
		top=addr;
		top->value=data;
		top->next=NULL;
		
	}
	
	
}
void pop()
{
	if(root == NULL)
	{
		printf("Ups! List is empty");
		return;
	}
	if(root == top)
	{
		free(top);
		root=NULL;
		top=NULL;
		return;
	}
	for(curr=root;curr->next!=top;curr=curr->next);
	curr->next=NULL;
	free(top);
	top=curr;
	
}
void tops()
{
	if(top == NULL)
	{
		printf("top value is NULL\n");
		return;
	}
	printf(" top value is %d\n",top->value);
	
}
void isEmpty()
{
	if(root == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List is not empty\n");
	}
}

int main()
{
	int choice;
	while(1)
	{
		printf("Menu\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Top\n");
		printf("4. IsEmpty\n");
		printf("5. print stack\n");
		printf("6. Exit\n");
		printf("Enter choices [1-5]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();break;
			case 2: pop();break;
			case 3: tops();break;
			case 4: isEmpty();break;
			case 5: print();break;
			case 6: exit(1);
		}
	}
}
