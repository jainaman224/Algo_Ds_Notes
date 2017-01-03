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

function preOrder($root){
	if (!empty($root)){
		echo $root->value . " ";
		preOrder($root->left);
		preOrder($root->right);
	}
}

$root = new Node(1);
$root->left = new Node(2);
$root->right = new Node(3);
$root->left->left = new Node(4);
$root->left->right = new Node(5);
$root->right->left = new Node(6);
$root->right->right = new Node(7);

echo "preOrder traversal of tree is ";
preOrder($root);
echo "\n";

/** Output
*
* Pre Order traversal of tree is 1 2 4 5 3 6 7
*
*/
