/*Implement single threaded binary tree and do inorder travrsal on it.
    Single Threaded Binary Tree : each node is threaded towards either the in-order 
    predecessor or successor (left or right) means all right null pointers will 
    point to inorder successor OR all left null pointers will point to inorder predecessor.
NOTE:  
    The right link of rightmost node from right subtree is always NULL.
*/
#include <iostream>
using namespace std;
class Node
{    
    Node *left;
    int data;
    int rtflag;      //rtflag=0 -> right link is thread
    Node *right;	 //rtflag=1 -> right link is null
public:
    Node()
    {	
     left = right = NULL;
     data = 0;
     rtflag = 0;
    }
friend class Tree;
};
class Tree
{
    public:
        int flag,key,level,top,d;
	char ch;
	Node *root,*q,*n;
	Node* s[10];
	Tree()
	{
            flag = key = level = d = 0;
            top = -1;
	    root = n = q = NULL;
	    ch = 'n';
	}
	
	void addNode()
	{
	 do
	 {
	     flag = 0;
             cout<<"\n Enter data : ";
             cin>>d;
	     if(root == NULL)  //creation of a new root node
	     {
	         n = new Node();
		 n->data = d;
          	 n->left = NULL;
		 n->right = NULL;
		 n->rtflag = 0;
		 root = n;
	     }
	     else
	     {
	         q = root;
		 n = new Node();     //n is newly created node
		 n->data = d;		  
		 n->left = NULL;
		 n->right = NULL;
		 do
		 {
		     if(d < q->data)    //if data < q->data move to the left
		     {
		         if(q->left == NULL)
			 {
			     q->left = n;
			     n->right = q;     //right link of new node point to its inorder successor
			     flag = 1;
			     n->rtflag = 1;    //set the rtflag to 1 to specify it is a thread   
			 }
			 else
		         {
			     q = q->left;
		         }
		     }
		     if(d > q->data)    //if data > q->data move to the right
		     {
		         if(q->right == NULL)
			 {
			     q->right = n;
			     flag = 1;
			     q->rtflag = 0;
			 }
			 else if(q->rtflag == 1)   //right link of q is a thread
			 { 
			     n->right = q->right;   
			     q->right = n;	
			     flag = 1;
			     n->rtflag = 1;        //set the rtflag of n to 1
			     q->rtflag = 0;        //set the rtflag of q to 0
			 }
			 else
			 {
		             q = q->right;
			 }
	             }

		}while(flag != 1);
	    }
            cout<<"\n Do you want to continue : ";
	    cin>>ch;
	 }while(ch != 'n');
	}

	void inorder(Node* q)
	{
	cout<<"\n Inorder Traversal ";
	do
	{
	    while(q->left != NULL)   //traverse to left until it become null.
	    {
	        q = q->left;
	    }
	    cout<<"    "<<q->data;  //print leftmost child
            while(q->rtflag == 1)   
	    {
	        q = q->right;
		cout<<"    "<<q->data;
	     }
	    q = q->right;
	}while(q != NULL);
	}
};
int main() 
{
    Tree t;
    int ch;
    t.addNode();
    t.inorder(t.root);
    return 0;
}
/*
Input:
Enter data:100
Do you want to continue : y
Enter data:20
Do you want to continue : y
Enter data:45
Do you want to continue : y
Enter data:38
Do you want to continue : y
Enter data:25
Do you want to continue : n

Output:
Inorder Traversal : 20    25    38    45    100
*/
