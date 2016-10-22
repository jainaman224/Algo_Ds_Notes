#include<stdio.h>
#define SIZE 10

void enQueue(int);
void deQueue();
void display();
void QueueSize();
void empty();
void inital_queue(int);

int queue[SIZE], front = -1, rear = -1, count=0;

void main()
{
    int value, choice;
    inital_queue(1);
    inital_queue(2);
    inital_queue(3);
    inital_queue(4);
    printf("INITIAL STATUS OF QUEUE\n");
    display();
    while(1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Empty\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            value=9;
            enQueue(value);
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            case 4: empty();
            break;
            case 5: exit(0);
            default: printf("\nWrong selection!!! Try again!!!");
        }
    }
}

void inital_queue(int item)
{

  if(front == -1)
   front = 0;
 queue[++rear] = item;
 count++;
}

void enQueue(int value)
{
    if(rear == SIZE-1)
      printf("\nQueue is Full!!! Insertion is not possible!!!");
    else
    {
     queue[++rear] = value;
     printf("\nInsertion success!!!");
    }
    count++;
    display();
}

void deQueue()
{
    if(front == rear)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
    else
    {
      printf("\nDeleted : %d", queue[front]);
      front++;
      if(front == rear)
         front = rear = -1;
     count--;
    }
    display();
}

void QueueSize()
{
    printf("\n Queue size : %d", count);
}

void display()
{
    if(rear == -1)
      printf("\nQueue is Empty!!!");
    else
    {
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
         printf("%d ",queue[i]);
    }
}

void empty()
{
    if(count==0)
        printf("\nQueue is empty\n");
    else
        printf("\nQueue is not empty\n");
}


/*
INITIAL STATUS OF QUEUE :
1 2 3 4

if choice=1
output : 
Queue elements are:
1 2 3 4 9

if choice=2
output :
Queue elements are:
2 3 4

if choice=3
output :
Queue elements are:
1 2 3 4

if choice=4
output :
Queue is not empty

if choice=5
exit
*/

