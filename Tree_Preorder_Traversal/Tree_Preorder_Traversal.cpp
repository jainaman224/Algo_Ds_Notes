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

void PreOrder(node *root) {
    if(root != NULL){
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
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

    cout << "Pre Order traversal of tree is ";
    PreOrder(root);

    return 0;
}

/* Output

Pre Order traversal of tree is 1 2 4 5 3 6 7

*/
