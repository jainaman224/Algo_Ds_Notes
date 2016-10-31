/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>
 
#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
int size=0;
main()
{
    int choice;
    insert(1);
    display();
    
    insert(2);
    display();
    
    insert(3);
    display();
    
    delete();
    display();
    /*
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        }
    }
    */
}
insert(int add_item)
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
        size++;
    }
} /*End of insert()*/

int isEmpty(){
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return 1;
    }
    return 0;
}
 
delete()
{
    if( !isEmpty() )
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
        size--;
    }
} /*End of delete() */
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /*End of display() */
