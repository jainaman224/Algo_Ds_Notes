package main

import (
	"fmt"
)

type Node struct {
	data interface{}
	next *Node
}

type LinkedList struct {
	first *Node
}

//Sorts at insertion time
func (l *LinkedList) insert(data interface{}) {
	if l.first == nil {
		l.first = &Node{data: data}
	} else if l.first.data.(int) > data.(int) {
		l.first = &Node{data: data, next: l.first}
	} else {
		current := l.first
		for current.next != nil && current.next.data.(int) < data.(int) {
			current = current.next
		}
		current.next = &Node{data: data, next: current.next}
	}
}

//Displays all nodes in a list format
func (l *LinkedList) display() {
	var current = l.first
	fmt.Print("[")
	for current != nil {
		fmt.Printf("%v", current.data)
		current = current.next
		if current != nil {
			fmt.Print(", ")
		}
	}
	fmt.Println("]")
}

func main() {
	var list = LinkedList{}
	var N = 0
	fmt.Scanf("%d", &N)
	for ; N > 0; N-- {
		var intToAdd int
		fmt.Scanf("%d", &intToAdd)
		list.insert(intToAdd)
	}
	list.display()
}
