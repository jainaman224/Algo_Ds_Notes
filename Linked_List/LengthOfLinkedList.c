#include<stdio.h>
#include<stdlib.h>

/*
This code is written for Char to store in LinkedList, if you want to store numericals or any other datatype,
just replace relevent data type in place of char in class Node.
*/

struct Node {
	char data;
	struct Node* next;
};


void pushing_data_to_LL(struct Node** headPointer, char newData) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = newData;
	newNode->next = (*headPointer);
	(*headPointer) = newNode;
}

int gettingLength(struct Node* head) {
	int count = 0;
	struct Node* current = head;
	while(current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

int main() {
	struct Node* head = NULL;
	
	pushing_data_to_LL(&head, 'G');
	pushing_data_to_LL(&head, 'S');
	pushing_data_to_LL(&head, 'S');
	pushing_data_to_LL(&head, 'O');
	pushing_data_to_LL(&head, 'C');
	pushing_data_to_LL(&head, '2');
	pushing_data_to_LL(&head, '0');
	pushing_data_to_LL(&head, '2');
	pushing_data_to_LL(&head, '0');
	
	printf("The Length of Linkedlist is: %d", gettingLength(head));
	return 0;
} 

