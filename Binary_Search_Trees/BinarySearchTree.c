#include <stdio.h>
#include <stdlib.h>

typedef struct node_s node_t;

typedef struct node_s
{
	int data;
	node_t* left;
	node_t* right;
} node_t;

void Free( node_t* root )
{
	if ( root == NULL )
		return;

	Free( root->left );
	Free( root->right );
	free( root );
}

int Left_Of( const int value, const node_t* root )
{
	return value < root->data;
}

int Right_Of( const int value, const node_t* root )
{
	return value > root->data;
}

node_t* Insert( node_t* root, const int value )
{
	if ( root == NULL )
	{
		node_t* node = malloc( sizeof( node_t ) );
		node->left = NULL;
		node->right = NULL;
		node->data = value;
		return node;
	}
	if ( Left_Of( value, root ) )
		root->left = Insert( root->left, value );
	else if ( Right_Of( value, root ) )
		root->right = Insert( root->right, value );
	return root;
}

int Search( const node_t* root, int value )
{
	if ( root == NULL )
		return 0;
	if ( Left_Of( value, root ) )
		return Search( root->left, value );
	if( Right_Of( value, root ) )
		return Search( root->right, value );
	return 1;
}

int Leftmost_Value( const node_t* root )
{
	while ( root->left != NULL )
		root = root->left;
	return root->data;
}

node_t* Delete( node_t* root, int value )
{
	if ( root == NULL )
		return root;
	if ( Left_Of( value, root ) )
		root->left = Delete( root->left, value );
	else if ( Right_Of( value, root ) )
		root->right = Delete( root->right, value );
	else
	{
		// root->data == value, delete this node
		if ( root->left == NULL )
		{
			node_t* newRoot = root->right;
			free( root );
			return newRoot;
		}
		if ( root->right == NULL )
		{
			node_t* newRoot = root->left;
			free( root );
			return newRoot;
		}
		root->data = Leftmost_Value( root->right );
		root->right = Delete( root->right, root->data );
	}
	return root;
}

int main()
{
	node_t* root = NULL;
	root = Insert( root, 5 );
	root = Insert( root, 7 );
	root = Insert( root, 9 );
	root = Insert( root, 8 );
	root = Insert( root, 6 );
	root = Insert( root, 4 );

	printf( "Contains 9: %d\n", Search( root, 9 ) );
	printf( "Contains 2: %d\n", Search( root, 2 ) );

	root = Delete( root, 7 );
	root = Delete( root, 5 );
	root = Delete( root, 4 );

	printf( "Contains 9: %d\n", Search( root, 9 ) );
	printf( "Contains 2: %d\n", Search( root, 2 ) );
	printf( "Contains 5: %d\n", Search( root, 5 ) );
	printf( "Contains 6: %d\n", Search( root, 6 ) );

	Free( root );
	root = NULL;
	return 0;
}

/* Output

Contains 9: 1
Contains 2: 0
Contains 9: 1
Contains 2: 0
Contains 5: 0
Contains 6: 1

*/
