#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
     node *new_node = new node;
     new_node->data = data;
     new_node->left = NULL;
     new_node->right = NULL;

     return new_node;
}

void InOrder(node *root) {
    if(root != NULL){
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "In Order traversal of tree is ";
    InOrder(root);

    return 0;
}

/* Output

In Order traversal of tree is 4 2 5 1 6 3 7

*/
