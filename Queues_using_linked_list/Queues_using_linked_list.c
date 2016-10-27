#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
    int frontelement();
    void enqueue(int data);
    void dequeue();
    void empty();
    void display();
    void create();
    void queuesize();
 
int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf("\n1.Enqueue");
    printf("\n2.Dequeue");
    printf("\n3.Front element");
    printf("\n4.Empty");
    printf("\n5.Exit");
    printf("\n6.Display");
    printf("\n7.Queue size");
    create();
    
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:  
            printf("Enter data : ");
            scanf("%d", &no);
            enqueue(no);  break;
        case 2:
            dequeue();   break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n Queue empty, no front element");
            break;
        case 4:  empty();       break;
        case 5:  exit(0);
        case 6:  display();     break;
        case 7:  queuesize();     break;
        default:
            printf("Wrong choice, Enter choice again: ");
            break;
        }
    }
}
 

void create()
{
    front = rear = NULL;
}
 


void enqueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
    //printf("qwerty");
}
 

void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
    //printf("asdfgh");
}
 

void dequeue()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
        //printf("ghjkl");
}
 

int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
void queuesize()
{
    printf("\n Queue size : %d", count);
}


void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
