/*
    The Bottom View of a Binary Tree depicts the nodes that are visible 
    when the tree is viewed from below. At every horizontal distance 
    there would be exactly one node that will appear in bottom view.
    The horizontal distance is measured with root serving as reference,
    then we measure the left and right deviations of the each node.
*/

#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair

// Node of Binary Tree storing data, horizontal distance
// from root, left and right child information
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

// Function to print Bottom View of Binary Tree
void BottomView(Node *root) 
{
    if (root == NULL)
        return;

    // initialising variables
    queue<Node *> q;
    q.push(root);
    root -> distance = 0;
    map<int, int> mp;
    // variable to store distance of nodes
    int distance;

    // asigning horizontal distance to each node of Binary Tree
    // and replacing nodes of same horizontal distance in a map with
    // key as distance so as to obtain the Bottom View
    while (!q.empty()) 
    {
        // extract the node at the front of queue
        Node *temp = q.front();
        distance = temp -> distance;

        // make key as distance and data as value for map
        mp[distance] = temp -> data;
        // remove the extract node from queue
        q.pop();

        // when left child exists, assign horizontal distance to it,
        // and push it to the queue
        if (temp -> left != NULL) 
        {
            temp -> left -> distance = distance - 1;
            q.push(temp -> left);
        }

        // when right child exists, assign horizontal distance to it,
        // and push it to the queue
        if (temp -> right != NULL) 
        {
            temp -> right -> distance = distance + 1;
            q.push(temp -> right);
        }
    }
    /* 
        Map mp contains:
        [-2] -> 4
        [-1] -> 8
        [0] -> 6
        [1] -> 9
        [2] -> 7
    */

    cout << "Bottom View of Binary Tree: " << endl;
    map<int, int> :: iterator it;
    // Iterate over the map keys i.e -2, -1, 0, 1, 2
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
            Input:
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
    
    // call to BottomView function
    BottomView(root);
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
    Bottom View of Binary Tree:
    4 8 6 9 7
*/
