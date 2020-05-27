
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  

void push(struct Node** head_ref, int new_data); 
  
bool isPresent(struct Node *head, int data); 
  
struct Node *getUnion(struct Node *head1, struct Node *head2) 
{ 
    struct Node *result = NULL; 
    struct Node *t1 = head1, *t2 = head2; 
  
   
    while (t1 != NULL) 
    { 
        push(&result, t1->data); 
        t1 = t1->next; 
    } 
  
  
    while (t2 != NULL) 
    { 
        if (!isPresent(result, t2->data)) 
            push(&result, t2->data); 
        t2 = t2->next; 
    } 
  
    return result; 
} 
  
struct Node *getIntersection(struct Node *head1,  
                              struct Node *head2) 
{ 
    struct Node *result = NULL; 
    struct Node *t1 = head1; 
  

    while (t1 != NULL) 
    { 
        if (isPresent(head2, t1->data)) 
            push (&result, t1->data); 
        t1 = t1->next; 
    } 
  
    return result; 
} 
