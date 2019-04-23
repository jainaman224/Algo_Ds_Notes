#include<iostream>
#include<conio.h>
using namespace std;

struct node
{
    int info;
    node *next;
};

//creating a new node
node *create (int x) 
{
    node *p = new node;
    p->info = x;
    p->next = NULL;
    return p;
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
void rem (node * slow, node * head) 
{
    node *ptr;
    node *temp;
    ptr = head;
    while (1)
    {
        temp = slow;
        while (temp->next != slow && temp->next != ptr)
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

    node *slow = ptr;
    node *fast = ptr;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            //remove function called
            rem (slow, ptr); 
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
