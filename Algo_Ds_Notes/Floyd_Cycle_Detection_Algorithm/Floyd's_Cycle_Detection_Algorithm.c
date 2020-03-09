// Floyd's Cycle Detection Algorithm

#include<stdio.h>
#include<stdlib.h>

// Declaration of Linked List node
typedef struct node
{
    int data;
    struct node* next;
}node;

node *head = NULL;

// Inserting a new node into the Linked List
node* inserting_a_new_node(int data)
{
    node* temp;
    temp = (node*) malloc (sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

// Detect if a cycle is found
int CycleDetection(node* head)
{
    node *pointer_fast = head, *pointer_slow = head;
    while (pointer_fast && pointer_fast->next && pointer_slow)
    {
        pointer_slow = pointer_slow->next;
        pointer_fast = pointer_fast->next->next;
        if (pointer_slow == pointer_fast)
           return 1;
    }
    return 0;
}

// Using the main method
int main()
{
    int n;
    printf("Enter the size of Linked list: \n");
    scanf("%d", &n);
    int linkedList[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &linkedList[i]);
        head = inserting_a_new_node(linkedList[i]);
    }

    // We are manually creating a loop
    head->next->next->next = head->next;
    if(CycleDetection(head))
	printf("Cycle is found!\n");
    else
	printf("Cycle is not found\n");
    return 0;
}

/* Input: 
   5
   20 30 40 50 60

  Output:
  Enter the size of Linked list: 
  Cycle is found!
*/
