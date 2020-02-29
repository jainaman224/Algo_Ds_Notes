/*This code is for sorting the linked list using Divide and conquer technique*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/*Merging the contents*/
Node *merge(Node *l1, Node *l2)
{
    struct Node *head=NULL;
    if(!l1)
        return l2;
    
    if(!l2)
        return l1;
    

    if(l1->data<l2->data)
    {
        head=l1;
        l1->next = merge(l1->next,l2);
    }
    else
    {
        head=l2;
        l2->next = merge(l2->next, l1);
    }
    
    return head;
}

/*Dividing the linked list*/
Node* mergeSort(Node* head) {
    
    if(head==NULL || head->next==NULL)
        return head;
        
    /*Dividing the linked list into two equal parts as done in merge sort*/
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    
    while(ptr2 && ptr2->next)
    {
        ptr1=ptr1->next;
        if(ptr2->next)
            ptr2=ptr2->next->next;
    }
    
    ptr2=ptr1->next;
    ptr1->next=NULL;
    
    return merge(mergeSort(head),mergeSort(ptr2));
}


void printList(Node* node) {
    while (node != NULL) {
        printf("%d-->", node->data);
        node = node->next;
    }
    printf("NULL");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = (node*)malloc(sizeof(node));

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/*Sample Input
1 - Test cases
5 - Total number of elements to be inserted in linked list
23 2 34 5 1 - Adding the contents of the linked list
*/


int main() {
    long test;
    scanf("%d", &test)
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}