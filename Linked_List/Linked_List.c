#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;

int Is_List_Empty()
{
    if(head == NULL)
        return 1;

    return 0;
}

void Insert_At_Beginning(int value)
{
    node *temp =(node*)malloc(sizeof(node));
    temp -> data = value;
    temp -> next = head;
    head = temp;
}

void Insert_At_End(int value)
{
    node *temp = (node*)malloc(sizeof(node)), *current = head;
    temp -> data = value;
    temp -> next = NULL;

    if(Is_List_Empty())
    {
        head = temp;
        return ;
    }

    while(current -> next != NULL)
        current = current -> next;

    current -> next = temp;
}

void Insert_After_Value(int desired, int value)
{
    node *current = head;

    while(current != NULL && current -> data != desired)
        current = current -> next;

    if(current == NULL)
    	printf("Element %d is not in list\n",desired);
    else
    {
        node *temp = (node*)malloc(sizeof(node));
        temp -> data = value;
        temp -> next = current -> next;
        current -> next = temp;
    }
}

void Delete_At_Beginning()
{
    if(Is_List_Empty())
        printf("List is empty\n");
    else
    {
        node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
}

void Delete_At_End()
{
    if(Is_List_Empty())
    {
    	printf("List is empty\n");
        return ;
    }

    node *temp = head, *prev;

    if(head -> next == NULL)
    {
        head = NULL;
        free(temp);
        return ;
    }

    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }

    prev -> next = temp -> next;
    temp -> next = NULL;
    free(temp);
}

void Delete_With_Value(int desired)
{
    if(Is_List_Empty())
    {
    	printf("List is empty\n");
        return ;
    }

    node *temp = head, *prev;

    if(head -> data == desired)
    {
        head = head -> next;
        temp -> next = NULL;
    	free(temp);
        return ;
    }

    while(temp != NULL && temp -> data != desired)
    {
        prev = temp;
        temp = temp -> next;
    }

    if(temp == NULL)
    	printf("Element %d not in list\n",desired);
    else
    {
        prev -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
    }
}

void Search(int desired)
{
    node *temp = head;

    while(temp != NULL && temp -> data != desired)
        temp = temp -> next;

    if(temp == NULL)
    	printf("Element %d not in list\n",desired);
    else
        printf("Element %d present in list\n",desired);
}

void Print_Linked_List()
{
    if(Is_List_Empty())
    {
        printf("List is empty\n");
        return ;
    }

    node *current = head;

    while(current -> next != NULL)
    {
    	printf("%d -> ",current->data);
        current = current -> next;
    }

    printf("%d\n",current->data);
}

void Length_Iterative()
{
    int length = 0;

    if(!Is_List_Empty())
    {
        length++;
        node *current = head;

	while(current -> next != NULL)
        {
            length++;
            current = current -> next;
        }
    }
    printf("Length by iteration is : %d\n",length);
}

int Recursive_Count(node* current)
{
    if(current == NULL)
        return 0;
    else
        return (1 + Recursive_Count(current -> next));
}

void Length_Recursive()
{
    int length = Recursive_Count(head);

    printf("Length by iteration is : %d\n",length);
}

int main()
{
    int i;

    for(i = 0; i < 5; i++)
        Insert_At_Beginning(i);

    Print_Linked_List();

    for(i = 5; i < 10; i++)
        Insert_At_End(i);

    Print_Linked_List();

    Insert_After_Value(5, 9);
    Insert_After_Value(10, 9);

    Print_Linked_List();

    for(i = 0; i < 3; i++)
        Delete_At_End();

    Print_Linked_List();

    for(i = 0; i < 3; i++)
        Delete_At_Beginning();

    Print_Linked_List();

    Delete_With_Value(1);
    Delete_With_Value(5);

    Print_Linked_List();

    Search(6);
    Search(8);

    Length_Iterative();
    Length_Recursive();

    return 0;
}

/*  Output
    4 -> 3 -> 2 -> 1 -> 0
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 6 -> 7 -> 8 -> 9
    Element 10 is not in list
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6 -> 7 -> 8 -> 9
    4 -> 3 -> 2 -> 1 -> 0 -> 5 -> 9 -> 6
    1 -> 0 -> 5 -> 9 -> 6
    0 -> 9 -> 6
    Element 6 is present in list
    Element 8 not found
    Length is 3 (Iterative)
    Length is 3 (Recursive)
*/
