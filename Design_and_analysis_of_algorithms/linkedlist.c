#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
struct node *curr=NULL,*root=NULL;
void print()
{
	printf("\nlinked list is:\t");
	for(curr=root;curr!=NULL;curr=curr->next)
	{
		printf("%d\t",curr->value);
	}
	printf("\n");
}

void insert_begin()
{
	int data;
	struct node *addr;
	printf("enter the value:\t");
	scanf("%d",&data);
	addr=(struct node*)malloc(sizeof(struct node));
	addr->value=data;
	addr->next=root;
	root=addr;
	print();
}

void insert_end()
{
	int data;
	struct node *addr;
	printf("enter the value:\t");
	scanf("%d",&data);
	addr=(struct node*)malloc(sizeof(struct node));
	addr->value=data;
	if(root == NULL)
	{
		root = addr;
		root->next = NULL;
	}
	for(curr=root;curr->next!=NULL;curr=curr->next);
	curr->next=addr;
	curr=curr->next;
	curr->next=NULL;
	print();
	
	
	
}

void insert_between()
{
	int data,k,i;
	struct node *addr,*temp;
	printf("enter the value and index(0 based):\t");
	scanf("%d %d",&data,&k);
	if(k ==0)
	{
		printf("please use insert in begining to insert at first position");
		return;
	}
	addr=(struct node*)malloc(sizeof(struct node));
	addr->value=data;
	
	for(curr=root,i=1;i<=(k-1);curr=curr->next,i++);
	temp=curr->next;
	curr->next= addr;
	curr=curr->next;
	curr->next=temp;
	print();
	
	
	
}

void delete()
{
	int k,i;
	struct node* temp;
	printf("index(0 based):\t");
	scanf("%d",&k);
	if(k == 0)
	{
		temp = root;
		root=root->next;
		free(root);
		print();
		return;
	}
	for(curr=root,i=1;i<=k-1;curr=curr->next,i++);
	if(root->next == NULL)
	{
		free(root);
		root=NULL;
	}
	
	temp=curr->next;
	curr->next=temp->next;
	free(temp);
	//printf("\nerror\n");
	print();
}
 void reverse(struct node* prev)
{
	
	struct node* curr = prev->next;
	if(curr == NULL && prev == NULL)
	{
		return;
	}
	prev->next=NULL;
	if(curr->next == NULL)
	{
		root=curr;
		root->next=prev;
		return;
	}
	else
		reverse(curr);
	curr->next=prev;
	//prev->next=NULL;
	
	
}


int main()
{
	int choice;
	while(1)
	{
		printf("Menu\n");
		printf("Enter your choices[1-6]:\n");
		printf("1. insert in begining\n");
		printf("2. insert in end\n");
		printf("3. insert in kth position\n");
		printf("4. delete\n");
		printf("5. reverse\n");
		printf("6. exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_begin();break;
			case 2: insert_end();break;
			case 3: insert_between();break;
			case 4: delete();break;
			case 5: reverse(root);print();break;
			case 6: exit(1);break;
		}
	}
		
}
