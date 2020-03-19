// Length of Linked List
#include <stdio.h>
#include <stdlib.h>

/*
This code is written for Char to store in LinkedList, if you want to store numericals or any other datatype,
just replace relevent data type in place of char in class Node.
*/

struct Node 
{	
    char data;
    struct Node* next;
};

void pushing_data_to_LL(struct Node** headPointer, char newData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = newData;
    newNode -> next = (*headPointer);
    (*headPointer) = newNode;
}

int gettingLength(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
    while(current != NULL)
    {
    	count++;
    	current = current -> next;
    }
    return count;
}

int main()
{
    struct Node* head = NULL;
    printf("Currently Length of Linkedlist is: %d", gettingLength(head));

    pushing_data_to_LL(&head, 'G');
    pushing_data_to_LL(&head, 'S');
    pushing_data_to_LL(&head, 'S');
    pushing_data_to_LL(&head, 'O');
    pushing_data_to_LL(&head, 'C');
	    
    //Intermediate Checking
    printf("\n Currently Length of Linkedlist is: %d", gettingLength(head));
	    
    pushing_data_to_LL(&head, '-');
    printf("\n Currently Length of Linkedlist is: %d", gettingLength(head));
    
    pushing_data_to_LL(&head, '2');
    pushing_data_to_LL(&head, '0');
    pushing_data_to_LL(&head, '2');
    pushing_data_to_LL(&head, '0');

    printf("\n Currently Length of Linkedlist is: %d", gettingLength(head));
    
    return 0;
}

/*
TestCase-1:
Sample Input: G S S O C 2 0 2 0 
Sample Output: 9 //9 letters

TestCase-2:
Sample Input: O p e n - S o u r c e
Sample Output: 11 //11 letters
*/
