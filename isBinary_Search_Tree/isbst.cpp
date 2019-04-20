#include <bits/stdc++.h>
using namespace std; 

//structure of the tree node 
struct Node                                   
{ 
    int data; 
    struct Node* left;
    struct Node* right; 
}; 

//Function to create a new node to the tree   
struct Node* createNode(int data)          
{ 
    struct Node* node = new Node;  
    node->left = NULL;
    node->right = NULL; 
    node->data = data;
    return (node); 
} 

//function to check if tree with root node is bst or not
bool isbst(Node* root, int min, int max)  
{ 
    //empty tree is a bst
    if (root == NULL)                      
        return true; 
    if(root->data < min || root->data >max) 
        return false;
    //for allowing unique values     
    return isbst(root->left, min, root->data - 1) && isbst(root->right, root->data + 1, max );    
} 

//Driver Program               
int main() 
{                                   
    struct Node *root = createNode(4); 
    root->left        = createNode(2); 
    root->right       = createNode(1); 
    root->left->left  = createNode(5); 
    root->left->right = createNode(6);  
    if (isbst(root,INT8_MIN,INT8_MAX)) 
        cout << "This Tree is Binary Search Tree"; 
    else
        cout << "Not a Binary Search Tree"; 
    return 0; 
} 

/* 
This tree is not a binary search tree
                4
               / \
              2   1        
             / \     
            5   6  
*/ 
