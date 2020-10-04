#include <bits/stdc++.h> 
using namespace std; 

// An AVL tree node 
class node 
{ 
	public: 
	int key; 
	node *left, *right; 
}; 

/* Helper function that allocates 
a new node with the given key and 
	NULL left and right pointers. */
node* newNode(int key) 
{ 
	node* Node = new node(); 
	Node->key = key; 
	Node->left = Node->right = NULL; 
	return (Node); 
} 

// A utility function to right 
// rotate subtree rooted with y 
// See the diagram given above. 
node *rightRotate(node *x) 
{ 
	node *y = x->left; 
	x->left = y->right; 
	y->right = x; 
	return y; 
} 

// A utility function to left 
// rotate subtree rooted with x 
// See the diagram given above. 
node *leftRotate(node *x) 
{ 
	node *y = x->right; 
	x->right = y->left; 
	y->left = x; 
	return y; 
} 

// This function brings the key at 
// root if key is present in tree. 
// If key is not present, then it 
// brings the last accessed item at 
// root. This function modifies the 
// tree and returns the new root 
node *splay(node *root, int key) 
{ 
	// Base cases: root is NULL or 
	// key is present at root 
	if (root == NULL || root->key == key) 
		return root; 

	// Key lies in left subtree 
	if (root->key > key) 
	{ 
		// Key is not in tree, we are done 
		if (root->left == NULL) return root; 

		// Zig-Zig (Left Left) 
		if (root->left->key > key) 
		{ 
			// First recursively bring the 
			// key as root of left-left 
			root->left->left = splay(root->left->left, key); 

			// Do first rotation for root, 
			// second rotation is done after else 
			root = rightRotate(root); 
		} 
		else if (root->left->key < key) // Zig-Zag (Left Right) 
		{ 
			// First recursively bring 
			// the key as root of left-right 
			root->left->right = splay(root->left->right, key); 

			// Do first rotation for root->left 
			if (root->left->right != NULL) 
				root->left = leftRotate(root->left); 
		} 

		// Do second rotation for root 
		return (root->left == NULL)? root: rightRotate(root); 
	} 
	else // Key lies in right subtree 
	{ 
		// Key is not in tree, we are done 
		if (root->right == NULL) return root; 

		// Zag-Zig (Right Left) 
		if (root->right->key > key) 
		{ 
			// Bring the key as root of right-left 
			root->right->left = splay(root->right->left, key); 

			// Do first rotation for root->right 
			if (root->right->left != NULL) 
				root->right = rightRotate(root->right); 
		} 
		else if (root->right->key < key)// Zag-Zag (Right Right) 
		{ 
			// Bring the key as root of 
			// right-right and do first rotation 
			root->right->right = splay(root->right->right, key); 
			root = leftRotate(root); 
		} 

		// Do second rotation for root 
		return (root->right == NULL)? root: leftRotate(root); 
	} 
} 

// The search function for Splay tree. 
// Note that this function returns the 
// new root of Splay Tree. If key is 
// present in tree then, it is moved to root. 
node *search(node *root, int key) 
{ 
	return splay(root, key); 
} 

// A utility function to print 
// preorder traversal of the tree. 
// The function also prints height of every node 
void preOrder(node *root) 
{ 
	if (root != NULL) 
	{ 
		cout<<root->key<<" "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

/* Driver code*/
int main() 
{ 
	node *root = newNode(100); 
	root->left = newNode(50); 
	root->right = newNode(200); 
	root->left->left = newNode(40); 
	root->left->left->left = newNode(30); 
	root->left->left->left->left = newNode(20); 

	root = search(root, 20); 
	cout << "Preorder traversal of the modified Splay tree is \n"; 
	preOrder(root); 
	return 0; 
} 

// This code is contributed by Prithvi007

