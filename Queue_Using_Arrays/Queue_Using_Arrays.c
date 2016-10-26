#include <stdio.h>
 
    #define MAX 50
    int queue_array[MAX];
    int rear = - 1;
    int front = - 1;


insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("Insert in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
        //printf("sdfghj");
    }
} 
 
delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Underflow \n");          return ;
    }
    else
    {
        printf("Element deleted: %d\n", queue_array[front]);
        front = front + 1;
        //printf("zxcvb");
    }
} 


display()
{
    int i;
    if (front == - 1)
        printf("Empty queue \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
        //printf("qwerty");
    }
} 

main()
{
    int choice;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit \n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: insert();  break;
            case 2: delete();  break;
            case 3: display(); break;
            case 4: exit(1);
            default:
            printf("Invalid choice \n");
        } 
    }
} 
