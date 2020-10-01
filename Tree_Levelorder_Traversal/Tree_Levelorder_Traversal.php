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

function levelOrder($root){
	static $a = 0;
	if (!empty($root)){
		$queue = [];
		$queue[] = $root;

		while (count($queue) > 0){
			if ($queue[0]->left){
				$queue[] = $queue[0]->left;
			}
			if ($queue[0]->right){
				$queue[] = $queue[0]->right;
			}
			echo $queue[0]->value . " ";
			$queue = array_slice($queue, 1);
		}
	}
}

$root = new Node(1);
$root->left = new Node(2);
$root->right = new Node(3);
$root->left->left = new Node(4);
$root->left->right = new Node(5);
$root->right->left = new Node(6);
$root->right->right = new Node(7);

echo "levelOrder traversal of tree is ";
levelOrder($root);
echo "\n";

/** Output
*
* Level Order traversal of tree is 1 2 3 4 5 6 7
*
*/
