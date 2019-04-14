package main

import (
	"fmt"
)

type node struct {
	data  int
	left  *node
	right *node
}

func newNode(i int) *node {
	return &node{
		data: i,
	}
}

func (n *node) printInorder() {
	if n == nil {
		return
	}

	n.left.printInorder()
	fmt.Printf("%d ", n.data)
	n.right.printInorder()
}

func main() {
	root := newNode(5)
	root.left = newNode(2)
	root.right = newNode(3)
	root.left.left = newNode(4)
	root.left.right = newNode(5)
	root.printInorder()
}
