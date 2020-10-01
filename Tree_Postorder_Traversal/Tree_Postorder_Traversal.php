<?php

class Node {
	public $left;
	public $right;
	public $value;

	public function __construct($key){
		$this->left = null;
		$this->right = null;
		$this->value = $key;
	}
}

function postOrder($root){
	if (!empty($root)){
		postOrder($root->left);
		postOrder($root->right);
		echo $root->value . " ";
	}
}

$root = new Node(1);
$root->left = new Node(2);
$root->right = new Node(3);
$root->left->left = new Node(4);
$root->left->right = new Node(5);
$root->right->left = new Node(6);
$root->right->right = new Node(7);

echo "postOrder traversal of tree is ";
postOrder($root);
echo "\n";

/** Output
*
* Post Order traversal of tree is 4 5 2 6 7 3 1
*
*/
