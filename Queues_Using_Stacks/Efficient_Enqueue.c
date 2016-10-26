#include <stdio.h>
#include <stdlib.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void ENQUEUE();
void DEQUEUE();
void Print_it();
void faormation();
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int counter = 0;
//printf("There you enter the main function");
void main()
{
    int ch;
    printf("\n1 - ENQUEUE");
    printf("\n2 - Dequeu");
    printf("\n3 - Print_it");
    printf("\n4 - Exit now");
    faormation();
    while (1)
    { printf("\nEnter your choice please");
        scanf("%d", &ch);
        switch (ch)
        //printf("There you enter the switch cases");
        {
        case 1:  ENQUEUE();  break;
        case 2:  DEQUEUE();  break;
        case 3:  Print_it(); break;
        case 4:  exit(0);
        default: printf("Oooopssss!!! Wrong choice");
        //printf("There you exit");
        }
    }
}
int pop1()
{
    //printf("There you enter the pop function");
    return(st1[top1--]);
}
void push1(int data)
{
    //printf("There you enter the pish1 function");
    st1[++top1] = data;
}
void faormation()
{
    //printf("There you enter the formation function");
    top1 = top2 = -1;
}


int pop2()
{
    //printf("There you enter the pop2 function");
    return(st2[top2--]);
}
void DEQUEUE()
{
    //printf("There you enter the dequeue function");
    int i;
    for (i = 0;i <= counter;i++)
    { push2(pop1());
    }
    pop2();
    counter--;
    for (i = 0;i <= counter;i++)
    { push1(pop2());
    }
}
void ENQUEUE()
{
    //printf("There you enter the enqueue function");
    int data, i;
    printf("Now you can enter data into queue");
    scanf("%d", &data);
    push1(data);  counter++;
}
void push2(int data)
{
    //printf("There you enter the push2 function");
    st2[++top2] = data;
} 

void Print_it()
{
    //printf("There you enter the print function");
    int i;
    for (i = 0;i <= top1;i++)
    {   printf(" %d ", st1[i]);
    }
}
