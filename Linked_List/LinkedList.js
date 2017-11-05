function Node(data) {
	this.data = data;
	this.next = null;
}
function Linked_List() {
	this.length = 0;
	this.head = null;
	/*
	* Adds Node at end of Linkedlist From given data
	**/
	this.add = function(data) {
		var node = new Node(data),
		current = this.head;
		if(!current) {
			this.head = node;
			this.length++;
			return node;
		}
		while(current.next) {
			current = current.next;
		}
		current.next = node;
		this.length++;
		return node;	
	}
	
}
/**
* Returns Node at given index
*/
Linked_List.prototype.get = function(index) {
	if(index > this.length)
		return "Node doesn't exist";
	var current = this.head,
	count = 0;
	while (count < index - 1) {
		current = current.next;
		count++;
	}
	return current;
}
// For Printing Linkedlist
Linked_List.prototype.toString = function () {
    var currentNode =  this.head
    let str = ""
    while (currentNode) {
        str += `👉 ${currentNode.data} `
        currentNode = currentNode.next
    }
    return str
}
var ll = new Linked_List();
ll.add(2);
ll.add(3);
ll.add(4);
ll.add(5);
ll.add(6);
ll.toString();
//👉 2 👉 3 👉 4 👉 5 👉 6
