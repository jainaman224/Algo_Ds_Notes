#include <bits/stdc++.h> 
#include <inttypes.h>  
using namespace std; 
  
// Node structure of a memory  
// efficient doubly linked list  
class Node  
{  
    public: 
    int data;  
    Node* npx; /* XOR of next and previous node */
};  
  
/* returns XORed value of the node addresses */
Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
  
/* Insert a node at the beginning of the  
XORed linked list and makes the newly  
inserted node as head */
void insert(Node **head_ref, int data)  
{  
    // Allocate memory for new node  
    Node *new_node = new Node();  
    new_node->data = data;  
  
    /* Since new node is being inserted at the  
    beginning, npx of new node will always be  
    XOR of current head and NULL */
    new_node->npx = XOR(*head_ref, NULL);  
  
    /* If linked list is not empty, then npx of  
    current head node will be XOR of new node  
    and node next to current head */
    if (*head_ref != NULL)  
    {  
        // *(head_ref)->npx is XOR of NULL and next.  
        // So if we do XOR of it with NULL, we get next  
        Node* next = XOR((*head_ref)->npx, NULL);  
        (*head_ref)->npx = XOR(new_node, next);  
    }  
  
    // Change head  
    *head_ref = new_node;  
}  
  
// prints contents of doubly linked  
// list in forward direction  
void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
  
    cout << "Following are the nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {  
        // print current node  
        cout<<curr->data<<" ";  
  
        // get address of next node: curr->npx is  
        // next^prev, so curr->npx^prev will be  
        // next^prev^prev which is next  
        next = XOR (prev, curr->npx);  
  
        // update prev and curr for next iteration  
        prev = curr;  
        curr = next;  
    }  
    cout<<endl;
}  
  
// Driver code  
int main ()  
{  
    /* Create following Doubly Linked List  
    head-->40<-->30<-->20<-->10 */
    Node *head = NULL;  
    insert(&head, 10);  
    insert(&head, 20);  
    insert(&head, 30);  
    insert(&head, 40);  
  
    // print the created list  
    printList (head);  
  
    return (0);  
}  