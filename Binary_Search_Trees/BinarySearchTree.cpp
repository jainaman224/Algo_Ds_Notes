#include <iostream>
#include <ios>
#include <memory>
#include <cassert>

using namespace std;

// A set implemented using a binary search tree.
// A binary search tree is a binary tree where the children on one side of a node are smaller and on the other side are larger. This makes searching in the tree efficient since only one of the two subtrees must be traversed for any visited node. However when sorted values are inserted, the tree degenerates into a linked list.
class int_set
{
  public:
	void insert( const int value )
	{
		_root = insert( move( _root ), value );
	}

	bool contains( const int value ) const
	{
		return contains( _root, value );
	}

	void remove( const int value )
	{
		_root = remove( move( _root ), value );
	}

	void print() const
	{
		print( 0, _root );
	}
  private:
	struct node;
	using node_ptr = unique_ptr<node>;
	struct node
	{
		int data = 0;
		node_ptr left;
		node_ptr right;
	};

	static node_ptr insert( node_ptr root, const int value );
	static bool contains( const node_ptr& root, const int value );

	static bool left_of( const node_ptr& root, const int value )
	{
		return value < root->data;
	}

	static bool right_of( const node_ptr& root, const int value )
	{
		return value > root->data;
	}

	static int leftmost( const node_ptr& root );
	static node_ptr remove( node_ptr root, const int value );
	static void print( const int indentation, const node_ptr& root );

	node_ptr _root;
};



int_set::node_ptr int_set::insert( int_set::node_ptr root, const int value )
{
	if ( root == nullptr )
	{
		auto newNode = make_unique<node>();
		newNode->data = value;
		return newNode;
	}
	if ( left_of( root, value ) )
		root->left = insert( move( root->left ), value );
	else if ( right_of( root, value ) )
		root->right = insert( move( root->right ), value );
	return root;
}

bool int_set::contains( const int_set::node_ptr& root, const int value )
{
	if ( root == nullptr )
		return false;
	if ( left_of(root, value ) )
		return contains( root->left, value );
	if ( right_of( root, value ) )
		return contains( root->right, value );
	return true;
}


int int_set::leftmost( const int_set::node_ptr& root )
{
	assert( root != nullptr );
	if ( root->left != nullptr )
		return leftmost( root->left );
	return root->data;
}

int_set::node_ptr int_set::remove( int_set::node_ptr root, const int value )
{
	if ( root == nullptr )
		return root;

	if ( left_of( root, value ) )
		root->left = remove( move( root->left ), value );
	else if ( right_of( root, value ) )
		root->right = remove( move( root->right ), value );
	else
	{
		// must remove this node. Easy if left or right are empty...
		if ( root->left == nullptr )
			return move( root->right );
		if( root->right == nullptr )
			return move( root->left );
		// otherwise store the leftmost value from the right subtree here.
		root->data = leftmost( root->right );
		root->right = remove( move( root->right ), root->data );
	}
	return root;
}

void int_set::print( const int indentation, const int_set::node_ptr& root )
{
	for ( int i = 0; i < indentation; ++i )
		cout << ' ';

	if ( root == nullptr )
	{
		cout << '*' << endl;
		return;
	}

	cout << root->data << endl;
	print( indentation + 1, root->left );
	print( indentation + 1, root->right );
}

int main()
{
	int_set s;
	s.insert( 5 );
	s.insert( 7 );
	s.insert( 9 );
	s.insert( 8 );
	s.insert( 6 );
	s.insert( 4 );

	s.print();

	cout << boolalpha; // print bools as true/false instead of 0/1
	cout << "Contains 9: " << s.contains( 9 ) << endl;
	cout << "Contains 2: " << s.contains( 2 ) << endl;

	s.remove( 7 );
	s.remove( 5 );
	s.remove( 4 );

	cout << "Contains 9: " << s.contains( 9 ) << endl;
	cout << "Contains 2: " << s.contains( 2 ) << endl;
	cout << "Contains 5: " << s.contains( 5 ) << endl;
	cout << "Contains 6: " << s.contains( 6 ) << endl;

	s.print();
	return 0;
}

/* Output

5
 4
  *
  *
 7
  6
   *
   *
  9
   8
    *
    *
   *
Contains 9: true
Contains 2: false
Contains 9: true
Contains 2: false
Contains 5: false
Contains 6: true
6
 *
 8
  *
  9
   *
   *
*/
