// C++ program to reverse alternate levels of a binary tree
#include<iostream>
#define MAX 100
using namespace std;

// A Binary Tree node
struct Node
{
	char data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(char item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to store nodes of alternate levels in an array
void storeAlternate(Node *root, char arr[], int *index, int l)
{
	// Base case
	if (root == NULL) return;

	// Store elements of left subtree
	storeAlternate(root->left, arr, index, l+1);

	// Store this node only if this is a odd level node
	if (l%2 != 0)
	{
		arr[*index] = root->data;
		(*index)++;
	}

	// Store elements of right subtree
	storeAlternate(root->right, arr, index, l+1);
}

// Function to modify Binary Tree (All odd level nodes are
// updated by taking elements from array in inorder fashion)
void modifyTree(Node *root, char arr[], int *index, int l)
{
	// Base case
	if (root == NULL) return;

	// Update nodes in left subtree
	modifyTree(root->left, arr, index, l+1);

	// Update this node only if this is an odd level node
	if (l%2 != 0)
	{
		root->data = arr[*index];
		(*index)++;
	}

	// Update nodes in right subtree
	modifyTree(root->right, arr, index, l+1);
}

// A utility function to reverse an array from index
// 0 to n-1
void reverse(char arr[], int n)
{
	int l = 0, r = n-1;
	while (l < r)
	{
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		l++; r--;
	}
}

// The main function to reverse alternate nodes of a binary tree
void reverseAlternate(struct Node *root)
{
	// Create an auxiliary array to store nodes of alternate levels
	char *arr = new char[MAX];
	int index = 0;

	// First store nodes of alternate levels
	storeAlternate(root, arr, &index, 0);

	// Reverse the array
	reverse(arr, index);

	// Update tree by taking elements from array
	index = 0;
	modifyTree(root, arr, &index, 0);
}

// A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
	if (root == NULL) return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

// Driver Program to test above functions
int main()
{
	struct Node *root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	root->left->right = newNode('e');
	root->right->left = newNode('f');
	root->right->right = newNode('g');
	root->left->left->left = newNode('h');
	root->left->left->right = newNode('i');
	root->left->right->left = newNode('j');
	root->left->right->right = newNode('k');
	root->right->left->left = newNode('l');
	root->right->left->right = newNode('m');
	root->right->right->left = newNode('n');
	root->right->right->right = newNode('o');

	cout << "Inorder Traversal of given tree\n";
	printInorder(root);

	reverseAlternate(root);

	cout << "\n\nInorder Traversal of modified tree\n";
	printInorder(root);

	return 0;
}

