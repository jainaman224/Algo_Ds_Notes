package main

import (
	"fmt"
)

// BinarySearchTree is the struct implementation of BST
type BinarySearchTree struct {
	Root *BinarySearchTreeNode
}

// BinarySearchTreeNode represents the node of binary search tree
type BinarySearchTreeNode struct {
	Data  int
	Left  *BinarySearchTreeNode
	Right *BinarySearchTreeNode
}

// Insert inserts the data in the  BinarySearchTree
func (t *BinarySearchTree) Insert(data int) {

	if t.Root == nil {
		t.Root = &BinarySearchTreeNode{Data: data}
		return
	}
	insert(t.Root, data)
}

// Delete deletes the node with value equal to data from the BST
func (t *BinarySearchTree) Delete(data int) {
	delete(t.Root, data)
}

// Search searches the BST for given data
func (t *BinarySearchTree) Search(data int) bool {
	return search(t.Root, data)
}

// MinValue returns the minimum value in the BST
func (t *BinarySearchTree) MinValue() int {
	return minValue(t.Root)
}

// MaxValue returns the minimum value in the BST
func (t *BinarySearchTree) MaxValue() int {
	return maxValue(t.Root)
}

// Inorder prints the BST in Inorder traversal
func (t *BinarySearchTree) Inorder() {
	inorder(t.Root)
}

func insert(n *BinarySearchTreeNode, data int) {

	if n.Data > data {
		if n.Left == nil {
			n.Left = &BinarySearchTreeNode{
				Data:  data,
				Left:  nil,
				Right: nil,
			}
			return
		}
		insert(n.Left, data)
	} else {
		if n.Right == nil {
			n.Right = &BinarySearchTreeNode{
				Data:  data,
				Left:  nil,
				Right: nil,
			}
			return
		}
		insert(n.Right, data)
	}
}

func delete(n *BinarySearchTreeNode, data int) *BinarySearchTreeNode {

	if n == nil {
		return nil
	}

	if n.Data == data {
		if n.Left == nil && n.Right == nil {
			return nil
		}
		if n.Left == nil {
			return n.Right
		} else if n.Right == nil {
			return n.Left
		}
		min := minValue(n.Right)
		n.Data = min
		n.Right = delete(n.Right, min)
		return n
	}

	if data < n.Data {
		n.Left = delete(n.Left, data)
	} else {
		n.Right = delete(n.Right, data)
	}
	return n
}

func search(n *BinarySearchTreeNode, data int) bool {

	if n == nil {
		return false
	}
	if n.Data == data {
		return true
	} else if n.Data > data {
		return search(n.Left, data)
	} else {
		return search(n.Right, data)
	}
}

func minValue(root *BinarySearchTreeNode) int {
	if root.Left == nil {
		return root.Data
	}
	return minValue(root.Left)
}

func maxValue(root *BinarySearchTreeNode) int {
	if root.Right == nil {
		return root.Data
	}
	return maxValue(root.Right)
}

func inorder(root *BinarySearchTreeNode) {
	if root == nil {
		return
	}
	inorder(root.Left)
	fmt.Printf("%d ", root.Data)
	inorder(root.Right)
}

func main() {
	// Create a Binary Search Tree
	var tree *BinarySearchTree = &BinarySearchTree{}
	// Insert elements in BST
	tree.Insert(5)
	tree.Insert(4)
	tree.Insert(6)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(2)
	tree.Insert(8)
	tree.Insert(1)
	tree.Insert(9)
	// Inorder Traversal
	fmt.Print("Inorder traversal of BST is: ")
	tree.Inorder()
	// Search if 4 is present (should print true)
	fmt.Println("\nIs 4 present in BST? ", tree.Search(4))
	// Delete 4 from BST and Search if 4 is present (should print false)
	tree.Delete(4)
	fmt.Println("Is 4 present in BST? ", tree.Search(4))
	// Inorder Traversal after deleting 4
	fmt.Print("Inorder traversal of BST is: ")
	tree.Inorder()
	// Print min value in BST
	fmt.Printf("\nMinimum value in BST is: %d\n", tree.MinValue())
	// Print max value in BST
	fmt.Printf("Maximum value in BST is: %d\n", tree.MaxValue())
}

/*
	Output:
	Inorder traversal of BST is: 1 2 3 4 5 6 7 8 9
	Is 4 present in BST?  true
	Is 4 present in BST?  false
	Inorder traversal of BST is: 1 2 3 5 6 7 8 9
	Minimum value in BST is: 1
	Maximum value in BST is: 9
*/
