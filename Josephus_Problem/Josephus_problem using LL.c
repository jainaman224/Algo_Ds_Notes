#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL, *temp,*last, *temp1,*temp2,*temp3;
int n,i,g,t,k,h;
struct node* create_ll()
{


	printf("enter no. of elements");//totak no. of people
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=i;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			last=temp;
		}
		else
		{
			last->next=temp;
			last=temp;
		}
	}
	last->next=head;
	return head;
}

void print_ll( struct node *head)//displaying complete list
{
	temp=head;
	printf("%d==>",temp->data);
	temp=temp->next;
	while(temp!=head)
	{
		printf("%d==>",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int t,p;
	head=create_ll();
	print_ll(head);
	printf("enter no. of pos to skip");//taking no. of posn. to skip as input
	scanf("%d",&t);
	temp1=head;
	while(temp1->next!=temp1)//iterating till only one element is left
	{
		temp1=head;
		for(i=0;i<t;i++)
		{
		 	printf("%d",i);
			temp2=temp1;
		 	temp1=temp1->next;
		}
		printf("%d",temp1->data);
		temp2->next=temp1->next;
		temp1->next=NULL;
		free(temp1);//deleting the element not required
		head=temp1->next;
	}
	printf("%d",head->data);
}
