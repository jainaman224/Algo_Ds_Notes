#include<iostream>
using namespace std;

struct tnode
{
    int data;
    tnode * L, * R;
    tnode()
    {
        L = R = NULL;
    }
};

class AVL
{
    private:
        tnode * root;
    public:
        AVL() { root = NULL; }
        tnode * LL(tnode *);
        tnode * RR(tnode *);
        tnode * LR(tnode *);
        tnode * RL(tnode *);
    
        int height(tnode *);
        int MAX(int, int);
    
        void create();
        tnode * insert(tnode *, int);
        void display();
        void inorder(tnode *);
        void preorder(tnode *);
};

tnode * AVL :: LL(tnode * parent)
{
    tnode * temp;
    temp = parent -> L;
    parent -> L = temp -> R;
    temp -> R = parent;
    return temp;
}

tnode * AVL :: RR(tnode * parent)
{
    tnode * temp;
    temp = parent -> R;
    parent -> R = temp -> L;
    temp -> L = parent;
    return temp;
}

tnode * AVL :: LR(tnode * parent)
{
    parent -> L = RR(parent -> L);
    parent = LL(parent);
    return parent;
}

tnode * AVL :: RL(tnode * parent)
{
    parent -> R = LL(parent -> R);
    parent = RR(parent);
    return parent;
}

int AVL :: MAX(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int AVL :: height(tnode * temp )
{
    if(temp == NULL)                                    //height of empty node(subtree)
        return -1;

    if(temp -> L == NULL and temp -> R == NULL)             //height of leaf node
        return 0;

    return (1 + MAX( height(temp -> L), height(temp -> R)));
}

void AVL :: create()
{
    int val;
    char ch;
    do
    {
        cout << "Enter Number : ";
        cin >> val;
        root = insert(root, val);
        cout << "Continue : ";
        cin >> ch;
    }while(ch == 'y');
}

tnode * AVL :: insert(tnode * temp, int val)
{
    if(temp == NULL)
    {
        temp = new tnode;
        temp -> data = val;
    }
    else
    {
        if(val < temp -> data)
        {
            temp -> L = insert(temp -> L, val);
            if( ( height(temp -> L) - height(temp -> R) == 2 ) )
            {
                if(val < temp -> L -> data)
                    temp = LL(temp);
                else
                    temp = LR(temp);
            }
	}
	else
	{
            temp -> R = insert(temp -> R, val);
            if( ( height(temp -> L) - height(temp -> R)== -2 ) )
            {
                if(val > temp -> R -> data)
                    temp = RR(temp);
                else
                    temp = RL(temp);
            }
	}
    }
    return temp;
}

void AVL :: inorder(tnode * temp)
{
    if(temp != NULL)
    {
        inorder(temp -> L);
        cout << "\n" << temp -> data;
        inorder(temp -> R);
    }
}

void AVL :: preorder(tnode * temp)
{
    if(temp != NULL)
    {
        cout << "\n"<<temp -> data;
        preorder(temp -> L);
        preorder(temp -> R);
    }
}

void AVL :: display()
{
    cout << "\n Data in Sorted way : ";
    inorder(root);
    cout << "\n Preorder : ";
    preorder(root);
}

int main()
{
    AVL t;
    t.create();
    t.display();
    cout << endl;
    return 0;
}

/*
 Initially putting data in increasing order to form right skewed tree
 
Enter Number : 5
Continue : y
Enter Number : 6
Continue : y
Enter Number : 7
Continue : y
Enter Number : 8
Continue : y
Enter Number : 9
Continue : y
Enter Number : 10
Continue : n
 
 Data in Sorted way : 
5
6
7
8
9
10
 Preorder : 
8
6
5
7
9
10 
 */
