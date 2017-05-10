#include <stdio.h>
#include <stdlib.h>

//CLRS 
//Insertion and Deletion in a Red Black Tree
enum type {RED,BLACK};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    enum type color;
};

/*
    Using Queue for level order traversal.
    functions pfront, isempty, dequeue, enqueue are part of Queue implementation.

*/

struct Queue
{
    struct Node* data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

struct Node* pfront()
{
    struct Node* data ;
    data = front->data;
    return data;
}

int isempty()
{
    if(front==NULL)
        return 1;

    else
        return 0;
}

void dequeue()
{
    if(isempty())
        return ;

    struct Queue* temp = front;
    front = front->next;
    free(temp);
}


void enqueue(struct Node* data)
{
    struct Queue* temp  =(struct Queue*)malloc(sizeof(struct Queue));
    temp->data = data;
    temp->next = NULL;

    if(front==NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void levelorder(struct Node* root)
{
    if(root==NULL)
        return;

    enqueue(root);

    while(!isempty())
    {
        struct Node* current = pfront();
        printf("%d ",current->data);

        if(current->left!=NULL)
            enqueue(current->left);

        if(current->right!=NULL)
            enqueue(current->right);

        dequeue();
    }
}

void LeftRotate(struct Node** T,struct Node** x)
{

    /*
        A left rotation looks like this.

            x                               y
          /   \                           /   \ 
         t1    y                         x     z
              /  \   ----->>>          /  \   /  \
             t2   z                   t1  t2  t3  t4
                 / \
                t3  t4

    */


    struct Node* y = (*x)->right;
    (*x)->right = y->left;

    if(y->left!=NULL)
        y->left->parent = *x;

    y->parent = (*x)->parent;

    if((*x)->parent == NULL)
        *T = y;

    else if(*x == (*x)->parent->left)
        (*x)->parent->left = y;

    else
        (*x)->parent->right = y;

    y->left = *x;

    (*x)->parent = y;

}
void RightRotate(struct Node** T,struct Node** x)
{
    /*
        A right rotation looks like this.

            x                            y
           / \                         /   \ 
          y  t4                       z     x
         / \      ------>>>          / \   / \
        z  t3                       t1 t2 t3 t4
       / \
      t1  t2

    */

    struct Node* y = (*x)->left;
    (*x)->left = y->right;

    if(y->right!=NULL)
        y->right->parent = *x;

    y->parent = (*x)->parent;

    if((*x)->parent==NULL)
        *T = y;

    else if((*x)== (*x)->parent->left)
        (*x)->parent->left = y;

    else
        (*x)->parent->right = y;

    y->right = *x;
    (*x)->parent = y;

}

void RB_insert_fixup(struct Node** T, struct Node** z)
{
    // Parent and grandparent of deleted node.
    struct Node* grandparent = NULL;
    struct Node* parentpt = NULL;

    while(((*z)!=*T)&& ((*z)->color!= BLACK) && ((*z)->parent->color == RED))
    {
        /*
            In above while loop we check:
            1.if inserted node is root node.. Then we just have to color it black.
            2.we have to continue with while loop if property 2 is violated
            (ie red parent cannot have red child.)

        */
        parentpt = (*z)->parent;
        grandparent = (*z)->parent->parent;

        if(parentpt == grandparent->left)
        {
            // If Node is inserted at left sub tree of grandparent.
            struct Node* uncle = grandparent->right;

            if(uncle!=NULL && uncle->color == RED)
            {
                /*
                If uncle(other child node of parent node) is not NULL and is red.
                1.color of grandparent is changed to Red.
                2.color of grandparent is changed to Red.
                3.uncle->color = BLACK;
                */

                grandparent->color = RED;
                parentpt->color = BLACK;
                uncle->color = BLACK;
                *z = grandparent;
                // We backtrack from z to grandparent.
            }

            else
            {
                // If inserted node is right child of parent.
                if((*z) == parentpt->right)
                {
                    LeftRotate(T,&parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent;
                }

                RightRotate(T,&grandparent);
                parentpt->color = BLACK;
                grandparent->color = RED;
                (*z) = parentpt;
            }
        }

        else
        {
            // This is just opposite of If statement.
            // ie. when parentpt is right child of grand parent.
            struct Node* uncle = grandparent->left;

            if(uncle!=NULL && uncle->color == RED)
            {
                grandparent->color = RED;
                parentpt->color = BLACK;
                uncle->color = BLACK;
                (*z) = grandparent;
            }

            else
            {
                if((*z) == parentpt->left)
                {
                    RightRotate(T,&parentpt);
                    (*z) = parentpt;
                    parentpt = (*z)->parent;
                }

                LeftRotate(T,&grandparent);
                parentpt->color = BLACK;
                grandparent->color = RED;
                (*z) = parentpt;
            }
        }
    }
    (*T)->color = BLACK;
    // Root node is colored black.

}

struct Node* RB_insert(struct Node* T,int data)
{
    struct Node* z = (struct Node*)malloc(sizeof(struct Node));
    z->data = data;
    z->left = NULL;
    z->right = NULL;
    z->parent = NULL;
    z->color = RED;

    struct Node* y = NULL;
    struct Node* x = T;//root

    while(x!=NULL)
    {
        y = x;
        if(z->data < x->data)
            x = x->left;

        else
            x = x->right;
    }
    z->parent = y;

    if(y==NULL)
        T = z;

    else if(z->data < y->data)
        y->left = z;

    else
        y->right = z;

    // Normal Binary Search Tree Insertion till here.

    /*
    RB_insert_fixup is used to maintain Red Black Tree property.
    Properties
    1).Root must be black
    2).Red parent cannot have red children(a red parent have both its children Black)
    3).Every Node is either red or black
    4).Black height of every node is same 
        ie. No of Black nodes from every leaf node to Root Node must be same.

    */

    RB_insert_fixup(&T,&z);

    return T;
}

void preorder(struct Node* root)
{
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

struct Node* Tree_minimum(struct Node* node)
{
    //This function is used to find successor of node which we are trying to delete.
    while(node->left!=NULL)
        node = node->left;

    return node;
}

void RB_delete_fixup(struct Node** T, struct Node** x)
{
    while((*x)!=*T && (*x)->color == BLACK)
    {
        if((*x)==(*x)->parent->left)
        {
            struct Node* w = (*x)->parent->right;

            if(w->color==RED)
            {
                w->color = BLACK;
                (*x)->parent->color = BLACK;
                LeftRotate(T,&((*x)->parent));
                w = (*x)->parent->right;
            }

            if(w->left->color==BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                (*x) = (*x)->parent;
            }

            else
            {
                if(w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    RightRotate(T,&w);
                    w = (*x)->parent->right;
                }

                w->color = (*x)->parent->color;
                (*x)->parent->color = BLACK;
                w->right->color = BLACK;
                LeftRotate(T,&((*x)->parent));
                (*x) = *T;
            }
        }

        else
        {
            struct Node* w = (*x)->parent->left;

            if(w->color==RED)
            {
                w->color = BLACK;
                (*x)->parent->color = BLACK;
                RightRotate(T,&((*x)->parent));
                w = (*x)->parent->left;
            }

            if(w->right->color==BLACK && w->left->color == BLACK)
            {
                w->color = RED;
                (*x) = (*x)->parent;
            }

            else
            {
                if(w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    LeftRotate(T,&w);
                    w = (*x)->parent->left;
                }

                w->color = (*x)->parent->color;
                (*x)->parent->color = BLACK;
                w->left->color = BLACK;
                RightRotate(T,&((*x)->parent));
                (*x) = *T;
            }
        }
    }
    (*x)->color = BLACK;

}

void RB_transplat(struct Node** T, struct Node** u,struct Node** v)
{
    if((*u)->parent == NULL)
        *T = *v;

    else if((*u)==(*u)->parent->left)
        (*u)->parent->left = *v;
    else
        (*u)->parent->right = *v;

    if((*v)!=NULL) 
        (*v)->parent = (*u)->parent;
}

struct Node* RB_delete(struct Node *T,struct Node* z)
{
    /*
    visit http://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
    For the explanation.
    */
    struct Node *y = z;
    enum type yoc;
    yoc = z->color; // y's original color

    struct Node* x;

    if(z->left==NULL )
    {
        x = z->right;
        RB_transplat(&T,&z,&(z->right));
    }

    else if(z->right==NULL )
    {
        x = z->left;
        RB_transplat(&T,&z,&(z->left));
    }

    else
    {
        y = Tree_minimum(z->right);
        yoc = y->color;
        x = y->right;

        if(y->parent==z)
            x->parent = y;

        else
        {
            RB_transplat(&T,&y,&(y->right));
            y->right = z->right;
            y->right->parent = y;
        }

        RB_transplat(&T,&z,&y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if(yoc==BLACK)
        RB_delete_fixup(&T,&x);

    return T;
}

struct Node* BST_search(struct Node* root, int x)
{
    if(root==NULL || root->data == x)
        return root;

    if(root->data > x)
       return  BST_search(root->left,x);
    else
        return BST_search(root->right,x);
}

int main()
{
    struct Node* RBT = NULL;

    RBT = RB_insert(RBT,2);
    RBT = RB_insert(RBT,1);
    RBT = RB_insert(RBT,4);
    RBT = RB_insert(RBT,5);
    RBT = RB_insert(RBT,9);
    RBT = RB_insert(RBT,3);
    RBT = RB_insert(RBT,6);
    RBT = RB_insert(RBT,7);

    printf("\nPreorder - ");
    preorder(RBT);

    printf("\nLevel order - ");
    levelorder(RBT);

    struct Node* x = BST_search(RBT,5);

    RBT = RB_delete(RBT,x);

    printf("\nAfter deleting 5");

    printf("\nPreorder - ");
    preorder(RBT);

    front = NULL; rear = NULL; // Delete old Queue

    printf("\nLevel order - ");
    levelorder(RBT);

    return 0;
}


/*
                   2(b)
                  /   \
                 1(b)  5(r)
                       /    \
                     4(b)     7(b)
                       /    /  \
                      3(r) 6(r)  9(r)


                After deleting 5

                   2(b)
                  /   \
                 1(b)  6(r)
                      /   \
                     4(b) 7(1)
                     /     \
                    3(r)   9(r)

*/

/*

Output :

Preorder - 2 1 5 4 3 7 6 9 
Level order - 2 1 5 4 7 3 6 9 
After deleting 5
Preorder - 2 1 6 4 3 7 9 
Level order - 2 1 6 4 7 3 9


*/
