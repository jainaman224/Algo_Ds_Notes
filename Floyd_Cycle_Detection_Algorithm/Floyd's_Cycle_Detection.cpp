#include<bits/stdc++.h>
using namespace std;
 
// Structure of Linked List node
struct Node 
{ 
    int data; 
    Node* next; 
};
Node *head = NULL;

void insert(int value) 
{ 
    // Create a new node and adjusting links
    Node* temp = new Node;
    temp->data = value; 
    temp->next = head; 
    head = temp; 
} 

 // Function to detect cycle 
bool detectCycle() 
{ 
    Node *slow_ptr = head;
    Node *fast_ptr = head;   
    while (fast_ptr && fast_ptr->next) 
    { 
        slow_ptr = slow_ptr->next; 
        fast_ptr = fast_ptr->next->next; 
        if (slow_ptr == fast_ptr) 
           return true;
    } 
    return false; 
} 
  
// Main Method
int main() 
{ 
    int values[]={10,20,30,40};
    int n=sizeof(values)/sizeof(values[0]);
    for(int i= n-1; i>=0 ;i--)
        insert(values[i]);
  
    // Creating a loop
    head->next->next->next->next = head->next;
    if(detectCycle())
	cout<<"Cycle found"<<endl;
    else
	cout<<"No cycle found"<<endl;  
    return 0; 
} 
