#include<stdio.h>
#include<stdlib.h>
 
/* structure for a node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to insert a node at the begining of a linked lsit */
void insertAtTheBegin(struct node **start_ref, int data);
 
/* Function to bubble sort the given linked lsit */
void bubbleSort(struct node *start);
 
/* Function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b);
 
/* Function to print nodes in a given linked list */
void printList(struct node *start);
 
int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;
 
    /* start with empty linked list */
    struct node *start = NULL;
 
    /* Create linked list from the array arr[].
      Created linked list will be 1->11->2->56->12 */
    for (i = 0; i< 6; i++)
        insertAtTheBegin(&start, arr[i]);
 
    /* print list before sorting */
    printf("\n Linked list before sorting ");
    printList(start);
 
    /* sort the linked list */
    bubbleSort(start);
 
    /* print list after sorting */
    printf("\n Linked list after sorting ");
    printList(start);
 
    getchar();
    return 0;
}
 
 
/* Function to insert a node at the begining of a linked lsit */
void insertAtTheBegin(struct node **start_ref, int data)
{
    struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *start)
{
    struct node *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
 
/* Bubble sort the given linked lsit */
void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = start;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
