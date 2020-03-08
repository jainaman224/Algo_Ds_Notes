/*
	Implement single threaded binary tree and do inorder travrsal on it.
	
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
		left=right=NULL;
		data=0;
		rtflag=0;
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
		flag=key=level=d=0;
		top=-1;
		root=n=q=NULL;
		ch='n';
	}



	void addNode()
	{
	 do
	 {
		 flag=0;
		 cout<<"\n Enter data : ";
		 cin>>d;


		if(root==NULL)  //If tree is initially empty if become true and new node will be created
		{
			n=new Node();
			n->data=d;
			n->left=NULL;
			n->right=NULL;
			n->rtflag=0;
			root=n;
		}
		else
		{
			q=root;
			n=new Node();     //n is newly created node
			n->data=d;		  // q is root node passed to function from main()
			n->left=NULL;
			n->right=NULL;
			do
			{

				if(d<q->data)
				{

					if(q->left==NULL)
					{
						q->left=n;
						n->right=q;     //right link of new node point to its inorder successor
						flag=1;
						n->rtflag=1;    //set the rtflag to 1 to specify it is a thread   
					}
					else
					{
						q=q->left;
					}
				}
				if(d>q->data)
				{

					if(q->right==NULL)
					{
						q->right=n;
						flag=1;
						q->rtflag=0;
					}
					else if(q->rtflag==1)   //right link of q is a thread
					{ 
						n->right=q->right;   //make right link of new node point to thraed i.e.right link og q
						q->right=n;			 //make right link of q pointmto new node n.
						flag=1;
						n->rtflag=1;        //set the rtflag of n to 1
						q->rtflag=0;        //set the rtflag of q to 0
					}
					else
					{
						q=q->right;
					}

				}

			}while(flag!=1);


	   }
		cout<<"\n Do you want to continue : ";
		cin>>ch;
		
	 }while(ch!='n');
	}

	void inorder(Node* q)
	{
		cout<<"\n Inorder Traversal ";
		do
		{
			while(q->left!=NULL)   //traverse to left until it become null.
			{
				
				q=q->left;
			}
			cout<<"\t"<<q->data;  //print leftmost child

			while(q->rtflag==1)   //if thread move to right and print data until rtflag=1.
			{

				q=q->right;
				
				cout<<"\t"<<q->data;
			}
			

			q=q->right;

		}while(q!=NULL);
	}


};
int main() 
{

	Tree t;
	int ch;
	
	cout<<"\n MENU ";
	do
	{
		cout<<" \n 1.Create Threaded Binary Tree \n 2.Inorder \n 3.Exit";
		cout<<"\n Enter your choice : ";

		cin>>ch;
		switch(ch)
		{
			case 1:t.addNode();
				break;
				
			case 2:t.inorder(t.root);
				break;
				
			case 3:exit(0);
			
		}
		
		
			
	}while(ch!=3);
	
	return 0;
}
