// reverse linked list  recursive method
#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
};
// add elements into linked list

void push(node**head ,int data)
{
	// creating newnode
	node*newnode = new node();
	// add data
	newnode->data = data;
	// link the old list off the new node
	newnode->next =(*head);
	//move head pointer to new node
	(*head) = newnode;
}

// print linked list
void printList(node*head)
{
	node*temp = head;
	while(temp!=NULL)
	{ cout<<temp->data<<" ";
	   temp=temp->next;
	}
	cout<<endl;
}

// reverse method
  void reverse(node**head)
  { 
  
     // divide the list into teo parts first and rest
  	 node*first,*rest;
  	 // empty list
  	 if(*head==NULL)
  	   return;
  	   first=*head;
  	   rest=first->next;
  	   if(rest==NULL)
  	   return;
  	   // reverse rest
  	   reverse(&rest);
  	   // link rest to first
  	   first->next->next = first;
  	   // now firs element is the last one so set its next to null
  	   first->next=NULL;
  	   // rest is the first element
  	   *head = rest;
  }

int main(){
	 node*head =NULL;
	   push(&head,1);
	   push(&head,2);
	   push(&head,3);
	   push(&head,4);
	   push(&head,5);
	   // printList
	   printList(head);
	   // reverse
	   reverse(&head);
	   //print after linking
	   printList(head);
	   
	   
}
