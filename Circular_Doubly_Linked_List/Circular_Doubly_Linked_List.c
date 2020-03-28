//A Circular Doubly Linked List is a linked data structure that consists of a set of 
//sequentially linked records called nodes. Each node is connected to the next node 
//and previous node via two link fields which refences the next node in sequence and 
//previous node in sequence. Each node consists of a data/key.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
//To Make Short Name of struct node that is nd.
typedef struct node nd;

//Initially start pointer(struct pointer) is Null.  
nd *start = NULL; 

//Initially end pointer(struct pointer) is Null.
nd *end = NULL; 

//To calculate Number of nodes.
int total;  

//for repeating the function create.
char op;  

//switch case.
void option();  

//For creating a new link list.
void create(nd *); 

//for displaying the link list.
void display(nd *); 

//to insert a node at the beginning. 
void insert_beg(nd *);  

//to insert a node at the end position.
void insert_end(nd *); 

//to insert a node after a node. 
void insert_after(nd *);  

//to delete a node from beginning.
void delete_beg(nd *);  

//to delete a node from end.
void delete_end(nd *);  

//to delete a specified node.
void delete_node(nd *);   

//to delete a node after a node.
void delete_after(nd *);  

//to delete entire link list.
void delete_list(nd *);  

//for sorting the link list.
void sort(nd *);  

//Main function
int main()
{
	option();
	return 0;	
}

//option function
void option ()
{
	int option;
	printf("\n\n----CIRCULAR DOUBLY LINK LIST----\n\n");
	printf("\n**********MENU***********\n");
	printf("\n 1:  Create Link List as well as Node.");
	printf("\n 2:  Display List.");
	printf("\n 3:  Add a node at the beginning of the Circular Doubly Linked List.");
	printf("\n 4:  Add a node at the end of the Circular Doubly Linked List.");
	printf("\n 5:  Add a node after a given node of the Circular Doubly Linked List.");
	printf("\n 6:  Delete a node from beginning of the Circular Doubly Linked List.");
	printf("\n 7:  Delete a node from end of the Circular Doubly Linked List.");
	printf("\n 8:  Delete a given node of the Circular Doubly Linked List.");
	printf("\n 9: Delete entire list of the Circular Doubly Linked List.");
	printf("\n 10: Sort the list of the Circular Doubly Linked List.");
	printf("\n 11: EXIT from the Circular Doubly Linked List.");
	printf("\n\nEnter your option:\t");
	scanf("%d",&option);
	switch(option)
	{
		case 1: create(start);
		break;
		case 2: display(start);
		break;
		case 3: insert_beg(start);
		break;
		case 4: insert_end(start);
		break;
		case 5: insert_after(start);
		break;
		case 6: delete_beg(start);
		break;
		case 7: delete_end(start);
		break;
		case 8: delete_node(start);
		break;
		case 9: delete_list(start);
		break;
		case 10: sort(start);
		break;
		case 11: exit(0);
		break;
		default: printf("\n****Invalid Choice****\n");
	}
}

//create function
void create(nd *ptr)
{
	total = 0;
	ptr = (nd *)malloc(sizeof(nd));
	printf("\nEnter a value: ");
	scanf("%d", &ptr->data);
	start = ptr;
	end = ptr;
	total++;
	printf("\nLink List Is Created.\n");
	do
	{
		printf("\nDo you want to insert another one (y/n)->: ");
		op = getche();
		if(op == 'y')
		{
			ptr->next = (nd *)malloc(sizeof(nd));
			ptr->next->prev = ptr;
			ptr = ptr->next;
			end = ptr;
			printf("\nEnter a value: ");
			scanf("%d", &ptr->data);
			total++;
		}
	}while(op == 'y');
	ptr->next = start;
	start->prev = end;
	printf("\nTotal Number of nodes = %d\n\n", total);
	option();
}

//display function
void display(nd *ptr)
{
	if(start == NULL)
	{
		printf("\nLink is not created till now.\nPlease Creat a link list first.\n\n");
	}
	else
	{
		printf("\nLink List\'s elements are below,\n");
		do
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}while(ptr != start);
	}
	option();	
}

//insert_beg function
void insert_beg(nd *ptr)
{
	if(start == NULL)
	{
		total = 0;
		ptr = (nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d", &ptr->data);
		start = ptr;
		end = ptr;
		ptr->next = start;
		ptr->prev = end;
		printf("\nTotal number of node is %d\n\n", ++total);
		option();
	}
	else
	{
		nd *ptr1;
		ptr1 = (nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d", &ptr1->data);
		ptr1->next = start;
		ptr1->prev = end;
		start = ptr1;
		end->next = start;
		printf("\nTotal Number of nodes = %d\n\n", ++total);
		option();
	}
}

//insert_end function
void insert_end(nd *ptr)
{
	if(start == NULL)
	{
		total = 0;
		ptr = (nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d", &ptr->data);
		start = ptr;
		end = ptr;
		ptr->next = start;
		ptr->prev = end;
		printf("\nTotal number of node is %d\n\n", ++total);
		option();
	}
	else
	{
		nd *new1;
		new1 = (nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d", &new1->data);
		new1->next = start;
		new1->prev = end;
		end->next = new1;
		end = new1;
		printf("\nTotal Number of nodes = %d\n\n", ++total);
	}
	option();
}

//insert_after function
void insert_after(nd *ptr)
{
	int loca,i;
	if(start == NULL)
	{
		printf("\nThere is no link list.\nYou should create a link list first.\n");
	}
	else
	{
		nd *new1,*pre;
		new1 = (nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d", &new1->data);
		printf("\n****INSERT A NODE AFTER A EXISTING NODE.****\nTotal Number of nodes = %d\nEnter a node number: ", total);
		scanf("%d", &loca);
		if(loca == total)
		{
			end->next = new1;
			new1->next = start;
			new1->prev = end;
			end = new1;
			printf("\nTotal Number of nodes = %d\n\n", ++total);
		}
		else if(loca == 0){
			start->prev = new1;
			new1->next = start;
			new1->prev = end;
			start = new1;
			end->next = start;	
			printf("\nTotal Number of nodes = %d\n\n", ++total);
			option();
		}
		else
		{
			for(i=1; i <= loca ;i++)
			{
				pre = ptr;
				ptr = ptr->next;
			}
			new1->next = ptr;
			new1->prev = pre;
			pre->next = new1;
			ptr->prev = new1;
			printf("\nTotal Number of nodes = %d\n\n", ++total);
		}		
	}
	option();		
}

//delete_beg function
void delete_beg(nd *ptr)
{
	if(start == NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		if(total == 1)
		{
			start=NULL;
			printf("\nNode is deleted from end.\nValue %d is Deleted.\n", ptr->data);
			free(ptr);
		}
		else
		{
			int t;
			nd *ptr1;
			
			//swap the value of 1st node and 2nd node
			t = ptr->data;
			ptr->data = ptr->next->data;
			ptr->next->data = t;
			
			//reinitialize 1st node next address
			ptr1 = ptr->next;
			ptr->next = ptr->next->next;
			
			printf("\nNode is deleted from end.\nValue %d is Deleted.\n", ptr1->data);
			free(ptr1);
		}
		printf("\nTotal Number of nodes remaining = %d\n\n", --total);
		option();
	}
}

//delete_end function
void delete_end(nd *ptr)
{
	nd *pre;
	if(start == NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		do
		{
			pre = ptr;
			ptr = ptr->next;
		}while(ptr->next != start);
		pre->next = start;
		printf("\nNode is deleted from end.\nValue %d is Deleted.\n", ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes remaining = %d\n\n", --total);
		option();
	}
}

//delete_node function
void delete_node(nd *ptr)
{
	nd *pre;
	int loca,i;
	if(start == NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		printf("\n****DELETE A PERTICULAR NODE****\nThere is %d number of nodes present.\n", total);
		printf("\nEnter a Node Number: ");
		scanf("%d", &loca);
		if(loca == total)
		{
			for(i=1; i < loca ;i++)
			{
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = start;
			printf("\nSpecifaied Node as well as Value %d is deleted.", ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n", --total);
		}
		else
		{
			for(i=1; i < loca; i++)
			{
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = ptr->next;
			printf("\nSpecifaied Node as well as Value %d is deleted.", ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n", --total);
		}
	}
	option();
}

//delete_list function 
void delete_list(nd *ptr)
{
	int i;
	if(start == NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		printf("\n****DELETION OF ENTIRE LIST****");
		printf("\nTotal %d number of Node will be deleted.", total);
		for(i=1; i <= total; i++)
		{
			ptr = start;
			start = start->next;
			free(ptr);
		}
		start = NULL;
	}
	option();
}

//ascending sort funtion
void sort(nd *ptr)
{
	int i,temp;
	nd *ptr1;
	ptr = start;
	if(start == NULL)
	{
		printf("\nThere is no node.\n");
	}
	else if(total == 1)
	{
		printf("\n***************After Sorting*****************\n");
		display(start);
	}
	else
	{
		printf("\nTotal number of Nodes are %d.", total);
		while(ptr->next != start)
		{
			ptr1 = ptr->next;
			while(ptr1 != start)
			{
				if(ptr->data > ptr1->data)//for ascending order sorting.
				{
					temp = ptr->data;
					ptr->data = ptr1->data;
					ptr1->data = temp;
				}
				ptr1 = ptr1->next;
			}
			ptr = ptr->next;
		}
	}
	printf("\n***************After Sorting*****************\n");
	display(start);
	option();
}
