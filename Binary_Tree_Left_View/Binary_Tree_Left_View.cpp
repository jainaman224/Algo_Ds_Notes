/*
    The Left View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from the left side of it. At every level 
    there would be exactly one node that will appear in left view which
    would be the first node of that level.
*/

#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair

// Node of Binary Tree storing data, level,
// left and right child information
struct Node 
{
    int data;
    int level;
    Node *left, *right;
    Node(int val) 
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to print Left View of Binary Tree
void leftView(Node *root) 
{
    if (root == NULL)
        return;

    // initialising variables
    queue<Node *> q;
    q.push(root);
    root -> level = 0;
    map<int, int> mp;

    // variable to store level of nodes
    int level;

    // asigning level to each node of Binary Tree
    // and replacing nodes of same level in a map with
    // key as level so as to obtain the Left View
    while (!q.empty()) 
    {
        // extract the node at the front of queue
        Node *temp = q.front();
        level = temp -> level;

        // make key as level and data as value for map
        if(mp.find(level) == mp.end())
            mp[level] = temp -> data;

        // remove the extract node from queue
        q.pop();

        // when left child exists, assign level to it,
        // and push it to the queue
        if (temp -> left != NULL) 
        {
            temp -> left -> level = level + 1;
            q.push(temp -> left);
        }

        // when right child exists, assign level to it,
        // and push it to the queue
        if (temp -> right != NULL) 
        {
            temp -> right -> level = level + 1;
            q.push(temp -> right);
        }
    }
    /* 
        Map mp contains:
        [0] : {1}
        [1] : {2}
        [2] : {4}
        [3] : {8}   
    */

    cout << "Left View of Binary Tree: " << endl;
    map<int, int> :: iterator it;
    // Iterate over the map keys i.e 0, 1, 2, 3
    for (it = mp.begin(); it != mp.end(); it++)
        cout << it -> second << " ";
}

// Driver Function
int main() 
{
    map<int, Node *> m;
    // Input number of edges
    int n;
    cin >> n;
    Node *root = NULL;

    /*
        Input Format:
        3
        1 2 L
        1 3 R
        2 4 L
        This means there are 3 edges
        2 is the left child of 1,
        3 is the right child of 1,
        4 is the left child of 2.
    */
    for (int i = 0; i < n; i++) 
    {
        int node1, node2;
        char direction;
        cin >> node1 >> node2 >> direction;
        Node *parent, *child;
        if (m.find(node1) == m.end())
        {
            parent = new Node(node1);
            m[node1] = parent;
            if (root == NULL)
                root = parent;
        }
        else
            parent = m[node1];
        child = new Node(node2);
        if (direction == 'L')
            parent -> left = child;
        else
            parent -> right = child;
        m[node2] = child;
    }

    // call to leftView function
    leftView(root);
    return 0;
}

/*
    Input:
    8
    1 2 L
    1 3 R
    2 4 L
    2 5 R
    3 6 L
    3 7 R
    5 8 L
    6 9 R
    
            1
         /     \
        2       3
      /   \   /   \
    4      5 6     7
         /   \
        /      \
       8        9

    Output:
    Left View of Binary Tree:
    1 2 4 8
*/
