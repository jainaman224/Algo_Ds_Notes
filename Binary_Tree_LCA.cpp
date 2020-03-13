/*
    LCA or Lowest Common Ancestor of a binary tree means finding the closest of ancestor
    of a 2 elements. Some exceptions which can arise in the tree input is when only one
    element is present in the tree. In that case return the element which you found in the
    tree. If none of the 2 input element is present in the binary tree, return -1 signifying
    NULL.
    Case 1: if both elements are present-> return LCA
    Case 2: if one the elment is present-> return the element present
    Case 3: if none of the element is present-> return -1

*/

#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


// defining the class for Binary Tree where the data is of Data type 'T'
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    // the destructor deletes all the nodes of the tree
    ~BinaryTreeNode() {
        // the size of all the nodes deallocated by the use of recursion  
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};



int Binary_Tree_LCA(BinaryTreeNode <int>* root , int val1, int val2){

    // base case    
    if (root == NULL){
        return -1;
    }
    
    // if the element is of any of the 2 input, return element
    if (root-> data == val1 || root-> data == val2){
        return root-> data;
    }
    
    int num1 = Binary_Tree_LCA(root-> left, val1, val2);
    int num2 = Binary_Tree_LCA(root-> right, val1, val2);
    
    // when element found from both left and right subtree
    if (num1 != -1 && num2 != -1){
        return root-> data;
    }
    // when element is found from the left subtree
    else if (num1 != -1){
        return num1;
    }
    // when element is found from the right subtree
    else if (num2 != -1){
        return num2;
    }
    // when element not found from either of the subtrees
    else {
        return -1;
    }
}


// driver function
int main() 
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    // entering -1 from the user means there is no element present at that position of the tree
    if(rootData == -1) 
    {
        return -1;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
	    q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }

    int val1, val2;   

    // val1 and val2 are the the elemnts for which LCA has to be calculated
    cout << "enter the 2 values: ";
    cin >> val1 >> val2;
    cout << Binary_Tree_LCA(root, val1, val2);
    delete root;
}


/*
	Input1:
Enter root data : 1
Enter left child of 1 : 2
Enter right child of 1 : 3
Enter left child of 2 : 4
Enter right child of 2 : 5
Enter left child of 3 : -1
Enter right child of 3 : -1
Enter left child of 4 : -1
Enter right child of 4 : -1
Enter left child of 5 : -1
Enter right child of 5 : -1
enter the 2 values: 4 3
	Output: 2
	* 
	* 
	* 
	Input2:
enter the 2 values: 4 5
	Output: 2
	* 
	* 
	* 
	Input3:
enter the 2 values: 2 10
	Output: 2

 */ 

