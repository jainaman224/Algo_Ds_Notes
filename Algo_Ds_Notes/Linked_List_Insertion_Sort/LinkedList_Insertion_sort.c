/*  author :  Akanksha Bhardwaj
    Last Updated: 27/10/2016
   C implementation of Insertion sort on  Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next ;
    struct node *prev;
};

void insert_beg(struct node **head , int val) {
    struct node *nn =(struct node *)malloc(sizeof(struct node));
    nn->val = val;
    nn->prev = NULL;
    nn->next = *head;
    if(*head == NULL) {
        *head = nn;
        return;
    }
    (*head)->prev = nn;
    *head = nn;
}

void insert_last(struct node **head , int val) {
    struct node *nn =(struct node *)malloc(sizeof(struct node ));
    nn->val = val;
    nn->next = NULL;
    struct node *trav = *head;
    while(trav->next != NULL) {
        trav = trav->next;
    }
    trav->next = nn;
    nn->prev = trav;

}

void print(struct node *head) {
    struct node *trav = head;
    while(trav->next != NULL) {
        printf("%d->",trav->val);
        trav = trav->next;
    }
     printf("%d\n",trav->val);
}

int size(struct node *head) {
    struct node *trav = head;
    int c = 0;
    while(trav != NULL) {
        c++;
        trav = trav->next;
    }
    return c;
}

void insertion_sort(struct node **head) {
    struct node * i = *head ;
    struct node *trav = *head;
    struct node *j ;
    int n;
    if(*head != NULL && (*head)->next != NULL) {
        while(trav->next != NULL) {
            trav = trav->next;
        }
        for(i = *head ; i != trav ; i = i->next) {
            n = i->next->val;
            for(j = i; j != *head ; j = j->prev) {
                    if(j->val > n) {
                        j->next->val = j->val;
                    }
                    else {
                        j->next->val = n;
                        break;
                    }
            }
            if(j == *head ) {
                if(j->val < n) {
                    j->next->val = n;
                }
                else {
                    j->next->val = j->val;
                    (*head)->val = n;
                }
            }
        }
    }
}

int main()
{
    struct node *head = NULL;
    int n, v;
    scanf("%d", &n);
    while(n--) {
        scanf("%d",&v);
        if(head == NULL) {
            insert_beg(&head,v);
        }
        else insert_last(&head,v);
    }
    insertion_sort(&head);
    print(head);

    return 0;
}
