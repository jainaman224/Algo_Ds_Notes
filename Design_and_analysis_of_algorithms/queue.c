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
void enqueue()
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
void dequeue()
{
	struct node* temp;
	temp=root;
	if(root == NULL)
	{
		printf("Ups!List is empty");
	}
	if(top == root)
	{
		top=root=NULL;
		
	}
	else	
	{
		root=root->next;
	}
	free(temp);
	
	
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
		printf("1. EnQueue\n");
		printf("2. DeQueue\n");
		printf("3. IsEmpty\n");
		printf("4. print queue\n");
		printf("5. Exit\n");
		printf("Enter choices [1-5]:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();break;
			case 2: dequeue();break;
			case 3: isEmpty();break;
			case 4: print();break;
			case 5: exit(1);
		}
	}
}


























