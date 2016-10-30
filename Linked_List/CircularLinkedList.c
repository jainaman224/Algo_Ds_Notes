#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    struct node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL){
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else{
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}

void printList(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
    printf("\n");
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
    struct node *head = NULL;
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        push(&head,num);
    }
    printList(head);
}
    return 0;
}
// sample input : 
// 2
// 4
// 1 2 3 4
// 10
// 2234 674 344 422 896 4043 2304 1264 4572 3456 

// sample output :
// 4 3 2 1 
// 3456 4572 1264 2304 4043 896 422 344 674 2234 
