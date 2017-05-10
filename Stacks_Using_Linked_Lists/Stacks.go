package main

import "fmt"

type Node struct {
	data interface{}
	next *Node
}

//Stack...
type Stack struct {
	first *Node
}

//Add int x to top of stack
func (stack *Stack) push(x int) {
	if stack.first == nil {
		stack.first = &Node{data: x}
	} else {
		stack.first = &Node{data: x, next: stack.first}
	}
}

//Delete from top of stack
func (stack *Stack) pop() {
	if stack.first != nil {
		stack.first = stack.first.next
	}
}


func main() {
	var stack = Stack{}
}
