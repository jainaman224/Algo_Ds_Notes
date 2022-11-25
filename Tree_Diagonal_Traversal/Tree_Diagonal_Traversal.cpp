/*
 * Diagonal Traversal of Binary tree
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Data Structure to store a Binary Tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Recursive function to perform preorder traversal on the tree and
// Fill the mao with diagonal elements
void printDiagonal(Node* node, int diagonal, unordered_map<int, vector<int> >& map)
{
    // Base case: empty tree
    if (node == NULL) {
        return;
    }

    // insert the current node into the current diagonal
    map[diagonal].push_back(node->data);

    // recur for the left subtree by increasing diagonal by 1
    printDiagonal(node->left, diagonal + 1, map);

    // Recur for the right subtree with the same diagonal
    printDiagonal(node->right, diagonal, map);
}


// Function to print the diagonal elemtns of a given binary tree
void printDiagonal(Node* root) {
    // create an empty map to store the diagonal element by every slope
    unordered_map<int, vector<int> > map;

    // perform preorder traversal on the tree and fill the map
    printDiagonal(root, 0, map);

    // traverse the map and print diagonal elements
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
/* construct the following tree
              1
            /   \
           /     \
          2        3
         /      /   \
        /      /     \
       4      5       6
            /   \
           /     \
          7       8
*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    printDiagonal(root);
    return 0;
}
                
