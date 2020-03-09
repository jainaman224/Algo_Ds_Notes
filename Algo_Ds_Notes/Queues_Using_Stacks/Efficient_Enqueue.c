/* Program to implement a queue using two stacks */
// Courtesy: geeksforgeeks
#include <stdio.h>
#include <stdlib.h>

/* structure of a stack node */
struct sNode
{
    int data;
    struct sNode *next;
};

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data);

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);

/* structure of queue having two stacks */
struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};

/* Function to enqueue an item to queue */
void enQueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}

/* Function to dequeue an item from queue */
int deQueue(struct queue *q)
{
    int x;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }

/* Move elements from satck1 to stack 2 only if
stack2 is empty */
if(q->stack2 == NULL)
{
    while(q->stack1 != NULL)
    {
        x = pop(&q->stack1);
        push(&q->stack2, x);

    }
}

x = pop(&q->stack2);
return x;
}

int isEmpty(struct queue *q){
    return (q->stack1 == NULL && q-> stack2 == NULL);
}

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node =
        (struct sNode*) malloc(sizeof(struct sNode));
        if(new_node == NULL)
        {
            printf("Stack overflow \n");
            getchar();
            exit(0);

        }

/* put in the data */
new_node->data = new_data;

/* link the old list off the new node */
new_node->next = (*top_ref);

/* move the head to point to the new node */
(*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode *top;

    /*If stack is empty then error */
    if(*top_ref == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);

    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;

    }
}
/* Driver function to test anove functions */
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 80);
    enQueue(q, 100);
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    deQueue(q);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);
    enQueue(q, 60);

    /* Dequeue items */
    while(!isEmpty(q))
        printf("%d\n", deQueue(q));

    return 0;
}
/* Output: [The first two elements would be dequeued]
 * 10
 * 20
 * 30
 * 40
 * 50
 * 60
 */
