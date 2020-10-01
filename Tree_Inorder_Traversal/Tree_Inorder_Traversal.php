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

function inOrder($root){
	if (!empty($root)){
		inOrder($root->left);
		echo $root->value . " ";
		inOrder($root->right);
	}
}

$root = new Node(1);
$root->left = new Node(2);
$root->right = new Node(3);
$root->left->left = new Node(4);
$root->left->right = new Node(5);
$root->right->left = new Node(6);
$root->right->right = new Node(7);

echo "inOrder traversal of tree is ";
inOrder($root);
echo "\n";

/** Output
*
* Pre Order traversal of tree is 4 2 5 1 6 3 7
*
*/
