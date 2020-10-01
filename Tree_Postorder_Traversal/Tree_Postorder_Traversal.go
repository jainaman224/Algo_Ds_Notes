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

func (n *node) PrintPostorder() {
	if n == nil {
		return
	}

	n.left.PrintPostorder()
	n.right.PrintPostorder()
	fmt.Printf("%d ", n.data)
}

func main() {
	root := newNode(1)
	root.left = newNode(2)
	root.right = newNode(3)
	root.left.left = newNode(4)
	root.left.right = newNode(5)
	root.PrintPostorder()
}
