#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


typedef struct node
{
    int info;
    struct node *next;
}node;

// structure for queue
typedef struct queue
{
    struct node *front,*rear;
}queue;

// function for creating new node
node *new_node(int data)
{
    node *ptr=(node *)malloc(sizeof(node));
    ptr->info=data;
    ptr->next=NULL;
    return ptr;
}

// function to initialize queue 
queue* create_queue()
{
    queue* q =(queue *)malloc(sizeof(queue));
    q->front=q->rear=NULL;
    return q;
}

// structure for stack
typedef struct stack
{
    struct queue *queue1;
    struct queue *queue2;
}stack;


// function for initializing stack
stack* create_stack()
{
    stack *s=(stack *)malloc(sizeof(stack));
    s->queue1=create_queue();
    s->queue2=create_queue();
    return s;
}

// function for enqueue
void enqueue(queue *q,int data)
{
    node *temp=new_node(data);
	
    if(q->rear==NULL)
    {
        q->front=q->rear=temp;
        return;
    }
	
        q->rear->next=temp;
        q->rear=temp;
}

// function for dequeue
int dequeue(queue *q)
{
    if(q->front==NULL)
    return 0;
	
    node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL)
    q->rear=NULL;
    return temp->info;
	
}
// function for pushing elements
void push(stack *s,int x)
{
    enqueue(s->queue1,x);
}

// function to pop elements
int pop(stack *s)
{
    int x;
    if(s->queue1==NULL && s->queue2==NULL)
    return 0;
	
    while(s->queue1->front->next!=NULL)
    {
        x=dequeue(s->queue1);
        enqueue(s->queue2,x);
    }
    int m = s->queue1->front->info;
    queue* temp= s->queue1;
    s->queue1 = s->queue2;
    s->queue2 = temp;
    return m;
}

int main()
{
    stack *s=create_stack();
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,5);
    push(s,6);
    push(s,8);
    printf("\npopped element= %d",pop(s));
    push(s,9);
    push(s,10);
    printf("\npopped element= %d",pop(s));
    printf("\npopped element= %d",pop(s));
    getch();
    return 0;
}
