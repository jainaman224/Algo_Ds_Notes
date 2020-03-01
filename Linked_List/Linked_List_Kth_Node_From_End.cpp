// Simple C++ program to find k'th node from end 


#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n) 
{ 
	int len = 0, i; 
	struct Node* temp = head; 

	// count the number of nodes in Linked List 
	while (temp != NULL) { 
		temp = temp->next; 
		len++; 
	} 

	// check if value of n is not 
	// more than length of the linked list 
	if (len < n) 
		return; 

	temp = head; 

	// get the (len-n+1)th node from the beginning 
	for (i = 1; i < len - n + 1; i++) 
		temp = temp->next; 

	cout << temp->data; 

	return; 
} 

void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

 
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
    int n;
	cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++){ 
      int data;
      cin>>data;
      push(&head,data); 
    }
    cout<< Kth position from end : ";
    int k;
    cin>>k;
	printNthFromLast(head, k); 
	return 0; 
} 
