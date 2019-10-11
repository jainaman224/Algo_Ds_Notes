#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *left, *right;

    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
        if(root==NULL){
                return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
        if(flag==0){
                return;
        }
        if(temp==NULL&&root==NULL)
                return;
        if(root==NULL){
                flag=0;
                return;
        }
        if(temp==NULL){
                flag=0;
                return;
        }
        if(temp->data==root->data){
            c++;
        }
        inorder(temp->left,root->left);
        inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
        if(root==NULL)
                return;
        if(root->data==a1){
                switch(lr){
                                case 'L':root->left=NewNode(a2);
                                break;
                                case 'R':root->right=NewNode(a2);
                                break;
                        }
        }
        insert(root->left,a1,a2,lr);
        insert(root->right,a1,a2,lr);
}


void inorder(Node *root, Node* &f, Node* &m,Node* &l,stack <Node*> &st,int &flag) 
{
        if(root && flag<=1)
        {
                inorder(root->left,f,m,l,st,flag);
                if(root->data>st.top()->data)
                        st.push(root);
                else
                {
                        if(flag==0)
                        {
                                f=st.top();
                                st.pop();
                                m=root;
                                st.push(root);
                                flag++;
                        }
                        else if(flag==1)
                        {
                                l=root;
                                flag++;
                        }
                }
                inorder(root->right,f,m,l,st,flag);
        }
}
Node *correctBST(Node* root )
{
        if(root==NULL)
                return NULL;
        Node *f=NULL,*m=NULL,*l=NULL;
        stack<Node*> st;
        Node *temp=new Node(INT_MIN);
        st.push(temp);
        int flag=0;
        inorder(root,f,m,l,st,flag);
        if(l==NULL)
                swap(f->data,m->data);
        else
                swap(m->data,l->data);
        return root;
}



int main()
{
        //int t;
        //cin>>t;
        //while(t--){
        struct Node *root=NULL;
        struct Node *temp=NULL;
        int n=4;
        //cin>>n;
        int m=4;
        int a1[4]={10,10,5,5};
        int a2[4]={5,8,2,20};
        char lr[4]={'L','R','L','R'};
        int i=0;
        while(n--){
                //int a1,a2;
                //char lr;
                //cin>>a1>>a2>>lr;
                if(root==NULL){
                        temp=NewNode(a1[i]);
                        root=NewNode(a1[i]);
                        switch(lr[i]){
                                case 'L':root->left=NewNode(a2[i]);
                                        temp->left=NewNode(a2[i]);
                                break;
                                case 'R':root->right=NewNode(a2[i]);
                                        temp->right=NewNode(a2[i]);
                                break;
                        }
                }
                else{
                        insert(root,a1[i],a2[i],lr[i]);
                        insert(temp,a1[i],a2[i],lr[i]);
                }
                ++i;
        }
        flag=1;
        c=0;

        root=correctBST(root);

        inorder(temp,root);

        if(c+1==m){
            cout<<flag<<endl;
        }
        else{
            cout<<"0\n";
        }
        
    return 0;
}



/*
 *Given Example:
Input:
10 5 L 10 8 R  5 2 L 5 20 R

Output:
1
*/ 
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
fixingTwoNodesOfBST.cpp [unix] (05:29 01/01/1970)                                                                            0,0-1 All
"fixingTwoNodesOfBST.cpp" [New File]

