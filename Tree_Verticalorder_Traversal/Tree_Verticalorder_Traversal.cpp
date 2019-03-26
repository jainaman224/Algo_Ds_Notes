/* Vertical Order Traversal of Binary Tree is a traversal in which all nodes that fall in the same vertical line are visited together, starting from the leftmost vertical line and ending at the rightmost vertical line. The horizontal distance is measured with root serving as reference, then we measure the left and right deviations of the each node. */

#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair

// Node of Binary Tree storing data, horizontal distance from root, left and right child information
struct Node 
{
    int data;
    int distance;
    Node *left, *right;
    Node(int val) 
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to print Binary Tree in Vertical Order
void VerticalOrderTraversal(Node *root) 
{
    if (root == NULL)
        return;

    // initialising variables
    queue<Node *> q;
    q.push(root);
    root->distance = 0;
    map<int, vector<int>> mp;
    // variable to store distance of nodes
    int distance;

    // asigning horizontal distance to each node of Binary Tree and storing all nodes of same horizontal distance in a map with key as distance
    while (!q.empty()) 
    {
        // extract the node at the front of queue
        Node *temp = q.front();
        distance = temp->distance;
        // make key as distance and data as value for map
        mp[distance].push_back(temp->data);
        // remove the extract node from queue
        q.pop();
        // when left child exists, assign horizontal distance to it, and push it to the queue
        if (temp->left != NULL) 
        {
            temp->left->distance = distance - 1;
            q.push(temp->left);
        }
        // when right child exists, assign horizontal distance to it, and push it to the queue
        if (temp->right != NULL) 
        {
            temp->right->distance = distance + 1;
            q.push(temp->right);
        }
    }
    /* Map mp contains:
    [-2] -> 4
    [-1] -> 2, 8
    [0] -> 1, 5, 6
    [1] -> 3, 9
    [2] -> 7
    */

    cout<<"Vertical Order Traversal of Tree: "<<endl;
    map<int, vector<int>>::iterator it;
    vector<int> row; 
    // Iterate over the map keys i.e -2, -1, 0, 1, 2
    for (it = mp.begin(); it != mp.end(); it++) 
    {
        row = it->second;
        for (int i = 0; i < row.size(); i++)
            cout << row[i] << " ";
        cout << endl;
    }
}

// Driver Function
int main() 
{
    /* Contructing Binary Tree as:
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    // call to VerticalOrderTraversal function
    VerticalOrderTraversal(root);
    return 0;
}

/*  Output:
    Vertical Order Traversal of Tree: 
    4 
    2 8 
    1 5 6 
    3 9 
    7 
*/
