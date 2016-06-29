#include <iostream>

using namespace std;

// A node of the doubly linked list
struct node
{
    int data;
    node *next;
    node *prev;
};

node *head; // Global

node *Getnewnode(int x)  // Function to make a new node
{
    node *newnode = new node;        // Allocating memory for new node
    newnode -> data = x;
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}

void insert_at_head(int x)
{
    node *newnode = Getnewnode(x);
    
    if(head == NULL)
    {
        head = newnode;
        return;
    }

    head -> prev = newnode;
    newnode -> next = head;
    head = newnode;
}

void print_forward()
{
    node *temp = head;
    
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    
    cout << endl;
}

void print_reverse()
{
    node *temp = head;
    
    if(temp == NULL)
        return;
        
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    
    cout << endl;
}

void delete_a_node(node *del)
{
    if(head == NULL || del == NULL) 
        return;
        
    if(head == del)
        head = del -> next;

    if(del -> prev != NULL)              // If del is not first node
        del -> prev -> next = del -> next;
           
    if(del -> next != NULL)             // If del is not last node
        del -> next -> prev = del -> prev;

    delete del; // Memory is freed
    return;
}

int main()
{
    head = NULL; // Doubly linked list is empty now
    insert_at_head(9);   // 9
    insert_at_head(7);   // 7 9
    insert_at_head(5);   // 5 7 9
    insert_at_head(1);	 // 1 5 7 9
    insert_at_head(2);   // 2 1 5 7 9
    insert_at_head(0);   // 0 2 1 5 7 9
    delete_a_node(head -> next);
    print_forward();              // 0 1 5 7 9
    print_reverse();              // 9 7 5 1 0
    return 0;
}
