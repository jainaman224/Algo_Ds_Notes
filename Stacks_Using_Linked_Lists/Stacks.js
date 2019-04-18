/* program to implement stack using linked list in js*/


// Namespace
var SA = {};

/*
 * Linked List node with item object and next pointer to another node
 */
SA.StackNode = function(){
	this.item = null;
	this.next = null;
}

SA.LinkedStack = function(){
	var head = null;
	var size = null;
	
	/*
	 Push function
	 */
	this.pushToStack = function(item){
		var node = new SA.StackNode();
		node.item = item;
		node.next = null;
		if(size < 1 && head === null){
			head = node;
			head.next = null;
			size = 1;
		}else{
			var current = head;
			while(current.next !== null){
				current = current.next;
			}
			current.next = node;
			size += 1;
		}
	}
	
	/*
	 Pop Function
	*/
	this.popFromStack = function(){
		var current = head;
		if(size === 0){
			return;
		}
		if(size === 1){
			head = null;
			size = 0;
			return current;
		}
		var prev = current;  // 543
		while(current.next !== null){
				prev = current;
				current = current.next;
		}
		prev.next = null;
		size -= 1;
		return current;
	}
	
	// Function to check if stack is empty
	this.isStackEmpty = function(){
		return (size < 1) ? true : false;
	}
	
	// Function to get top item of the stack
	this.stackTop = function(){
		var current = head;
		if(size > 0 && head !== null){
			while(current.next !== null){
				current = current.next;
			}
			return current.item;
		}else{
			console.log("There is no item in the stack");
			return null;
		}
	}
	
	this.printStack = function(){
		var current = head;
		while(current.next !== null){
			console.log("Item "+current.item + " is on the stack.");
			current = current.next;
		}
		console.log("Item "+current.item + " is on the stack.");
	}
	
}



var stack = new SA.LinkedStack();
console.log(stack.isStackEmpty());
var top = stack.stackTop();
console.log(top.item);
stack.pushToStack("Test1");
console.log(stack.stackTop().item);
stack.pushToStack("Test2");
stack.pushToStack("Test3");
stack.printStack();
var poped = stack.popFromStack();
console.log("Popped item is: " + poped.item);
stack.printStack();

 
   
