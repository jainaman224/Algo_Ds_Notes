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

void PostOrder(node *root) {
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
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

    cout << "Post Order traversal of tree is ";
    PostOrder(root);

    return 0;
}

/* Output

Post Order traversal of tree is 4 5 2 6 7 3 1

*/
