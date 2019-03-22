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

func (n *node) PrintPreorder() {
	if n == nil {
		return
	}

	fmt.Printf("%d ", n.data)
	n.left.PrintPreorder()
	n.right.PrintPreorder()

}

func main() {
	root := newNode(1)
	root.left = newNode(2)
	root.right = newNode(3)
	root.left.left = newNode(4)
	root.left.right = newNode(5)
	root.PrintPreorder()
}
