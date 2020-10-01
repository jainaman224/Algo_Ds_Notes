
#include <iostream> 
using namespace std; 
  
#define BOUND 4 
 
int top = -1; 
  
int length = 0; 
  
// function to create new stack 
int* create_new(int* a) 
{ 

    int* new_a = new int[length + BOUND]; 

    for (int i = 0; i < length; i++) 
        new_a[i] = a[i]; 
  
    length += BOUND; 
    return new_a; 
} 
  
// function to push new element 
int* push(int* a, int element) 
{ 
    // if stack is full, create new one 
    if (top == length - 1) 
        a = create_new(a); 
  
    a[++top] = element; 
    return a; 
} 
  
// function to pop an element 
void pop(int* a) 
{ 
    top--; 
} 
  
void display(int* a) 
{ 
    // if top is -1, that means stack is empty 
    if (top == -1) 
        cout << "Stack is Empty" << endl; 
    else { 
        cout << "Stack: "; 
        for (int i = 0; i <= top; i++) 
            cout << a[i] << " "; 
        cout << endl; 
    } 
} 
  
int main() 
{ 
    int *a = create_new(a); 

    a = push(a, 1); 
    a = push(a, 2); 
    a = push(a, 3); 
    a = push(a, 4); 
    display(a); 
 
    a = push(a, 5); 
    a = push(a, 6); 
    display(a); 
  
    a = push(a, 7); 
    a = push(a, 8); 
    display(a); 
  
    a = push(a, 9); 
    display(a); 
  
    return 0; 
} 

/* 
    Output :

    Stack: 1 2 3 4 
    Stack: 1 2 3 4 5 6
    Stack: 1 2 3 4 5 6 7 8
    Stack: 1 2 3 4 5 6 7 8 9

*/