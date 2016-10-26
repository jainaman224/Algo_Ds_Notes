#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
 
void main()
{
	
	int i;
	int num ;
	struct  node *first, *new, *pre, *new1, *count;
	clrscr();
	printf("\nNumber of node to create: ");
	scanf("%d", &num );
	first->next = NULL;
	new = first; 
	for (i = 0; i < num ; i++)
	{
		new->next = (struct node* ) malloc(sizeof(struct node));
		new = new->next;
		printf("\nEnter the node: %d: ", i+1);
		scanf("%d", &new->data);
		//printf("loll");
		new->next = NULL;
	}
	new1 = first;
	for( ; new1->next != NULL; new1 = new1->next)
	{
		for(count = new1->next; count != NULL; count = count->next)
		{
			if(new1->data > count->data)
			{
				int temp;
				temp = new1->data;
				new1->data = count->data;
				count->data = temp;
				//printf("qwerty");
			}
		}
	}
	new = first->next;
	printf("\nSorted linked list:\n");
	while (new)
	{
		printf("%d\t", new->data);
		new = new->next;
	}
	getch();
}
