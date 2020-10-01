/*
Technique used:

This method of detecting cycle is dependent upon Floyd's Cycle Detection Algorithm.
In Floyd's Cycle Detection Algorithm, we take two pointers : fast and slow.
The algorithm comes to an end when both of these pointers meet at a common point.
Then, we store the address of the common point in a pointer variable (temp here).
We start form the head of the linked list, and check each node if it is reachable
from temp. That particular node, if found, is the starting node of the linked list.
We assign a pointer to the previous one of this node.
*/

#include<iostream>
using namespace std;

struct node
{
    int info;
    node *next;
};

//creating a new node
node *create (int x) 
{
    node *ptr = new node;
    ptr->info = x;
    ptr->next = NULL;
    return ptr;
}

//printing the linked list
void print (node * ptr) 
{
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    }
    cout << "\n\n";
}

//removing the cycle from the linked list
void rem (node * slow_ptr, node * head) 
{
    node *ptr;
    node *temp;
    ptr = head;
    while (1)
    {
        temp = slow_ptr;
        while (temp->next != slow_ptr && temp->next != ptr)
            {
                temp = temp->next;
            }
            if (temp->next == ptr)
                break;
            ptr = ptr->next;
    }
    temp->next = NULL;
}

//detecting cycle in the linked list
int detect (node * ptr) 
{
    node *slow_ptr = ptr;
    node *fast_ptr = ptr;
    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
            //remove function called
            rem (slow_ptr, ptr); 
            return 1;
        }
    }
    return 0;
}

int main ()
{
    node *head = create (10);
    head->next = create (20);
    head->next->next = create (30);
    head->next->next->next = head;
    //detect function called
    if (detect (head) == 1) 
    {
        cout << "\nA cycle is present in the linked list\n";
        cout << "\n\nAfter removing the cycle, linked list is as follows:\n";
        //print function called
        print (head); 
    }
    else
        cout << "No cycle is present within the loop\n";
    return 0;
}

/* Sample input :HARDCORED VALUES:
    10->20->30->(attached to head)

     Sample output:
     A cycle is present in the linked list

     After removing the cycle, linked list is as follows:
     10 20 30
/*
