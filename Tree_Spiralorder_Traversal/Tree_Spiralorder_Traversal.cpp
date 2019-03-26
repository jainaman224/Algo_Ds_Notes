/* Spiral Order Traversal of a tree is level order traversal where levels are explored in zig-zag manner i.e. all nodes present at level 1 should be printed first from left to right, followed by nodes of level 2 right to left, followed by nodes of level 3 from left to right and so on.
*/

#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair

// Node of Binary Tree storing data, level, left and right child information
struct Node 
{
    int data;
    int level;
    Node *left, *right;
    Node(int val) 
    {
        data = val;
        level = 0;
        left = NULL;
        right = NULL;
    }
};

// Function to print Binary Tree in Spiral Order
void SpiralOrderTraversal(Node *root) 
{
    if (root == NULL)
        return;
    // initialising variables
    queue<Node *> q;
    q.push(root);
    root->level = 0;
    map<int, vector<int>> mp;

    // asigning levels to each node of Binary Tree and storing all nodes of same level in a map
    while (!q.empty()) 
    {
        // extract the front of queue
        Node *temp = q.front();
        // insert the extract node in the map with key as level value
        mp[temp->level].push_back(temp->data);
        // remove the extract node from queue
        q.pop();
        // when left child exists, assign level to it, and push it to the queue
        if (temp->left != NULL) 
        {
            temp->left->level = temp->level + 1;
            q.push(temp->left);
        }
        // when right child exists, assign level to it, and push it to the queue
        if (temp->right != NULL) 
        {
            temp->right->level = temp->level + 1;
            q.push(temp->right);
        }
    }
    /* Map mp contains:
    [0] -> 1
    [1] -> 2, 3
    [2] -> 4, 5, 6, 7
    [3] -> 8, 9
    */

    cout<<"Spiral Order Traversal of Tree: "<<endl;
    map<int, vector<int>>::iterator it;
    int level = 0;
    vector<int> row; 
    // Iterate over the map keys i.e 0, 1, 2, 3
    for (it = mp.begin(); it != mp.end(); it++) 
    {
        // when level is even, print elements of vector from left to right
        if (level % 2 == 0) 
        {
            row = it->second;
            for (int i = 0; i < row.size(); i++)
                cout << row[i] << " ";
            cout << endl;
        } 
        else 
        {
            // when level is odd, print elements of vector in from right to left
            row = it->second;
            for (int i = row.size() - 1; i >= 0; i--)
                cout << row[i] << " ";
            cout << endl;
        }
        // increment level value
        level++;
    }
}

// Driver Function
int main() 
{
    /* Contructing Binary Tree as:
          1
        /   \
      2      3
     / \    /  \
    4   5  6    7
       / \
      8   9
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
    // call to SpiralOrderTraversal function
    SpiralOrderTraversal(root);
    return 0;
}

/*  Output:
    Spiral Order Traversal of Tree: 
    1 
    3 2 
    4 5 6 7 
    9 8 
*/
