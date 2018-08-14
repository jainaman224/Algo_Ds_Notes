package main

import (
	"fmt"
)

// Queue represents the queue
type Queue struct {
	front *QueueNode
	rear  *QueueNode
	size  int
}

// QueueNode struct represents the nodes present in the Queue
type QueueNode struct {
	Node BinaryTreeNode
	next *QueueNode
}

// BinaryTreeNode represents the nodes of the tree
type BinaryTreeNode struct {
	data  int
	left  *BinaryTreeNode
	right *BinaryTreeNode
}

func (q *Queue) enqueue(n *BinaryTreeNode) {
	newNode := QueueNode{
		Node: *n,
		next: nil,
	}

	if q.size == 0 {
		q.front = &newNode
		q.rear = &newNode
	} else {
		q.rear.next = &newNode
		q.rear = q.rear.next
	}
	q.size++
}

func (q *Queue) dequeue() *BinaryTreeNode {
	if q.size == 0 {
		return nil
	}

	n := q.front.Node
	q.size--

	if q.size > 0 {
		q.front = q.front.next
	} else {
		q.front = nil
		q.rear = nil
	}

	return &n

}

func (q *Queue) isEmpty() bool {
	if q.size == 0 {
		return true
	}
	return false
}

func newNode(i int) *BinaryTreeNode {
	return &BinaryTreeNode{
		data: i,
	}
}

// PrintLevelorder prints the Level Order Traversal of the tree
func (nptr *BinaryTreeNode) PrintLevelorder() {
	if nptr == nil {
		return
	}

	q := Queue{}
	q.enqueue(nptr)
	for q.size > 0 {
		currentptr := q.dequeue()
		if currentptr.left != nil {
			q.enqueue(currentptr.left)
		}
		if currentptr.right != nil {
			q.enqueue(currentptr.right)
		}
		fmt.Print(currentptr.data, " ")
	}
}

func main() {
	root := newNode(1)
	root.left = newNode(2)
	root.right = newNode(3)
	root.left.left = newNode(4)
	root.left.right = newNode(5)
	root.right.right = newNode(6)
	root.PrintLevelorder()
}
