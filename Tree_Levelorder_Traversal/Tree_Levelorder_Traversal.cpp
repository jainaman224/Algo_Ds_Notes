#include <iostream>
#include <queue>

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

void LevelOrder(node * root)
{
    queue <node *> que;
    que.push(root);
    while(!que.empty()){
        if(que.front()->left!=NULL)
            que.push(que.front()->left);
        if(que.front()->right!=NULL)
            que.push(que.front()->right);
        cout << que.front()->data << " ";
        que.pop();
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

    cout << "Level Order traversal of tree is ";
    LevelOrder(root);

    return 0;
}

/* Output

Level Order traversal of tree is 1 2 3 4 5 6 7

*/
