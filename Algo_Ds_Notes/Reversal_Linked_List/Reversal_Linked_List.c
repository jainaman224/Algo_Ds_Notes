#include<stdio.h>
#include<malloc.h>

/* Link list node */
typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;

/* Function to reverse the linked list */
static void reverse()
{
    node* prev   = NULL;
    node* current = head;
    node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head= prev;
}

/* Function to push a node */
void push(int data)
{
    node *temp,*newn;
    newn=(node*)malloc(sizeof(node));
	newn->data=data;
	newn->next=NULL;
	if(head==NULL)
	{
		head=newn;
	}
	else
	{
		temp=head;
		while(temp->next !=NULL)
			temp=temp->next;
		temp->next=newn;
	}

}

/* Function to print linked list */
void printList()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

     push(1);
     push(2);
     push(3);
     push(4);
     printList();
     reverse();
     printf("\n Reversed Linked list \n");
     printList();
     getchar();
}
