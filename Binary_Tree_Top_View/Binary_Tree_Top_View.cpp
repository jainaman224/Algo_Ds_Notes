#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Structure of binary tree left, head, right
struct Node
{
    Node *left;
    Node *right;
    int head;
    int data;
};

// function to create a new node
Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

// function should print the topView of
// the binary tree
void topview(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    map<int, int> m;
    int head = 0;
    root->head = head;

    // push node and horizontal distance to queue
    q.push(root);

    cout << "The top view of the tree is : \n";

    while (q.size())
    {
        head = root->head;

        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to head, or returns zero otherwise.
        if (m.count(head) == 0)
            m[head] = root->data;
        if (root->left)
        {
            root->left->head = head - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->head = head + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}

// Driver Program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary Tree\n";
    topview(root);
    return 0;
}
