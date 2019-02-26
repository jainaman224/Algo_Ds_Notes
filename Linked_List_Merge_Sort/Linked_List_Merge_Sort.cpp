/*
Author: Nirmal Kumar Joshi

Sorting a Linked List using Merge Sort in C++.

Example:

Unsorted data ->0-> 3-> 7-> 2->4-> 8-> 1-> 9-> 5-> 6-> NULL

Sorted Data ->0->1->2->3->4->5->6->7->8->9->NULL

*/


#include<iostream>
 
using namespace std;

struct node
{
	int data;
	node *next;
};
 

node* NewNode(int d)
{
	struct node *temp = new node;
	temp->data = d;
	temp->next = NULL;
	
	return temp;
}
 

node* AddToList(node *tail, int data)
{
	struct node *newnode;
	newnode = NewNode(data);
 
	if(tail == NULL)
	{
		tail = newnode;
	}
	
	else
	{
		tail->next = newnode;
		
		tail = tail->next;
	}
 
	return tail;
}
 
node* Merge(node* h1, node* h2)
{
	node *t1 = new node;
	node *t2 = new node;
	node *temp = new node;
 
	
	if(h1 == NULL)
		return h2;
 
		if(h2 == NULL)
		return h1;
 
	t1 = h1;
 
	
	while (h2 != NULL)
	{
		
		t2 = h2;
 
		
		h2 = h2->next;
		t2->next = NULL;
 
		
		if(h1->data > t2->data)
		{
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
 
		
		flag:
		if(t1->next == NULL)
		{
			t1->next = t2;
			t1 = t1->next;
		}
		
		else if((t1->next)->data <= t2->data)
		{
			t1 = t1->next;
			goto flag;
		}
		else
		{
			
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}
 
	
	return h1;
}
 
 
// A function implementing Merge Sort on linked list using reference.
void MergeSort(node **head)
{
	node *first = new node;
	node *second = new node;
	node *temp = new node;
	first = *head;
	temp = *head;
 
	
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}
 
	
	MergeSort(&first);
	MergeSort(&second);
 
	      
	*head = Merge(first, second);
}
 
int main()
{
	int n, i, num;
	struct node *head = new node;
	struct node *tail = new node;
	head = NULL;
	tail = NULL;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
 
	// Create linked list.
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>num;
 
		tail = AddToList(tail, num);
		if(head == NULL)
			head = tail;
	}
 
	// Send reference of head into MergeSort().
	MergeSort(&head);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
 
	while(head != NULL) 
	{
		cout<<".."<<head->data;
		head=head->next;
	}
	return 0;	
}


/*
Output:

Enter the number of data element to be sorted: 10
Enter element 1: 3
Enter element 2: 8
Enter element 3: 9
Enter element 4: 4
Enter element 5: 5
Enter element 6: 7
Enter element 7: 6
Enter element 8: 2
Enter element 9: 0
Enter element 10: 1
 
Sorted Data ->0->1->2->3->4->5->6->7->8->9

*/