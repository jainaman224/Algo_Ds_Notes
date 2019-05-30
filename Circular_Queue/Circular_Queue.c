/* 
Circular Queue is based on FIFO (First In First Out) principle and the last position 
is connected back to the first position to make a circle.
*/

#include<stdio.h>

int queue[5];
int front = -1, rear = -1, size = 5;

void insert (int value);
void deleteQueue();
void display();

int main()
{
    int choice, value;
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    
    do
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter the value: ");
                scanf("%d", &value);
                insert (value);
                break;
            case 2: 
                deleteQueue();
                break;
            case 3: 
                display();
                break;
            
        }
    } while(choice != 3);
    
    return 0;
}

/*
Insertion:
1) Check whether queue is Full by ((rear == SIZE-1 && front == 0) || (rear == front-1)).
2) If it is full then display Queue is full. If queue is not full then, check 
   if (rear == SIZE – 1 && front != 0) if it is true then set rear = 0 and insert element.
*/
// Inserting the value in the queue
void insert (int value)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) 
    { 
        printf("\nQueue is full\n"); 
        return; 
    }
    else if (front == -1) 
    { 
        front = rear = 0; 
        queue[rear] = value; 
    } 
    else if (rear == size - 1 && front != 0) 
    { 
        rear = 0; 
        queue[rear] = value; 
    }
    else
    { 
        rear++; 
        queue[rear] = value; 
    } 
}

/*   
Deletion:
1) Check whether queue is Empty means check (front==-1).
2) If it is empty then display Queue is empty. If queue is not empty then Check if (front==rear) 
   if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set 
   front=0 and return the element.
*/
// Deleting from queue
void deleteQueue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return ;
    }
    
    printf("Element deleted from queue is : %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    
    else
    {
        if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }
}

// Displaying the queue
void display()
{
    if (front == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    
    printf("\nCircular Queue elements are: ");
    
    if (front <= rear) 
    { 
        for (int i = front; i <= rear; i++) 
            printf("%d ", queue[i]); 
    }     
    else
    { 
        for (int i = front; i < size; i++) 
            printf("%d ", queue[i]); 

        for (int i = 0; i <= rear; i++) 
            printf("%d ", queue[i]); 
    } 
}

/*1.Insert
2.Delete
3.Display
Enter choice: 1
Enter the value: 1
Enter choice: 1
Enter the value: 2
Enter choice: 1
Enter the value: 3
Enter choice: 1
Enter the value: 4
Enter choice: 2
Element deleted from queue is : 1
Enter choice: 3
Circular Queue elements are: 2 3 4*/
