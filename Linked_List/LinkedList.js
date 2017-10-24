function Node(data) {
	this.data = data;
	this.next = null;
}
function Linked_List() {
	this.length = 0;
	this.head = null;
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
Linked_List.prototype.get = function(num) {
	if(num > this.length)
		return "Node doesn't exist";
	var current = this.head,
	count = 0;
	while(count < num-1) {
		current = current.next;
		count++;
	}
	return current;
}
Linked_List.prototype.remove = function(pos) {
	var current = this.head,
	length = this.length,
	count = 0,
	prev = null;
	if(pos > length) {
		return "node doesn't exist!";
	}
	if(pos === 0) {
		this.head = current.head;
		this.length--;
		return this.head;
	}
	while(count < pos-1) {
		prev = current;
		current = current.next;
		count++;
	}
	prev.next = current.next;
	current = null;
	this.length--;
	return this.head;

}
var ll = new Linked_List();
ll.add(2);
ll.add(3);
ll.add(4);
ll.add(5);
ll.add(6);
//2->3->4->5->6
ll.remove(2);
//2->4->5->6
