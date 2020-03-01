class Doubly_Linked_List {

	int size;
	Node head;
	Node tail;

	class Node {
		int data;
		Node next;
		Node prev;

		Node(int d) {
			data = d;
		}
	}

	// Adding an element at the beginning of the list
	void addFirst(int d) {

		// If head will be null new node is created and assigned to head
		if (head == null) {
			Node n = new Node(d);
			head = n;
			tail = n;
			size++;
		} else {
			Node n = new Node(d);
			head.prev = n;
			n.next = head;
			head = n;
			size++;
		}
	}

	// Adding an element at the last of the list
	void addLast(int d) {
		if (head == null) {
			Node n = new Node(d);
			head = n;
			tail = n;
			size++;
		} else {
			Node n = new Node(d);
			tail.next = n;
			n.prev = tail;
			tail = n;
			size++;
		}
	}

	// Adding an element at the index given by the user
	void addAt(int d, int idx) {
		try {
			if (idx > size) {
				throw new ArrayIndexOutOfBoundsException();
			} else if (idx == 0) {
				if (head == null) {
					Node n = new Node(d);
					head = n;
					tail = n;
					size++;
				} else {
					Node n = new Node(d);
					head.prev = n;
					n.next = head;
					head = n;
					size++;
				}
			} else if (idx == size) {
				Node n = new Node(d);
				tail.next = n;
				n.prev = tail;
				tail = n;
				size++;
			} else {
				Node temp = head;
				for (int i = 0; i < idx - 1; i++) {
					temp = temp.next;
				}
				Node n = new Node(d);
				n.next = temp.next;
				n.prev = temp;
				temp.next.prev = n;
				temp.next = n;
				size++;
			}
		} catch (Exception e) {
			System.out.println("Index out of Bounds");
		}
	}

	// Removes the first element of list
	void removeFirst() {

		// If the list is empty i.e head is null no element can be removed
		if (head == null) {
			System.out.println("List is Empty");
		} else if (size == 1) {
			head = null;
			tail = null;
			size--;
		} else {
			Node temp = head.next;
			temp.prev = null;
			head = temp;
			size--;
		}
	}

	// Removes the last element of the list
	void removeLast() {

		// If there are no elements in the list i.e head is null no element will be
		// removed
		if (head == null) {
			System.out.println("List is Empty");
		} else if (size == 1) {
			head = null;
			tail = null;
			size--;
		} else {
			Node temp = tail.prev;
			temp.next = null;
			tail = temp;
			size--;
		}
	}

	// Removes at a given index given by the user
	void removeAt(int idx) {
		if (idx > size) {
			System.out.println("Index Out Of Bounds");
		} else if (idx == 0) {
			if (size == 1) {
				head = null;
				tail = null;
				size--;
			} else {
				Node temp = head.next;
				temp.prev = null;
				head = temp;
				size--;
			}
		} else if (idx == size - 1) {
			Node temp = tail.prev;
			temp.next = null;
			tail = temp;
			size--;
		} else {
			Node temp = head;
			for (int i = 0; i < idx - 1; i++) {
				temp = temp.next;
			}
			temp.next = temp.next.next;
			Node t = temp;
			temp = temp.next;
			temp.prev = t;
			size--;
		}
	}

	void display() {
		Node temp = head;

		// Traverse over diubly linked list and print the elements

		while (temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}

	public static void main(String[] args) {
		doublyLL lst = new doublyLL();
		lst.addFirst(30);
		lst.addFirst(20);
		lst.addFirst(10);
		lst.display();
		lst.addLast(10);
		lst.addLast(20);
		lst.addLast(30);
		lst.display();
		lst.removeFirst();
		lst.removeLast();
		lst.display();
		lst.removeLast();
		lst.removeLast();
		lst.removeFirst();
		lst.removeFirst();
		lst.display();
		lst.addAt(10, 0);
		lst.addAt(20, 1);
		lst.addAt(30, 2);
		lst.display();
		lst.removeAt(1);
		lst.display();

	}
	
	/*
	 * Sample Input 1: lst.addFirst(10)
	 * 				   lst.addLast(30)
	 * 				   lst.addAt(20,1);
	 * 				   lst.display();  =>  10, 20, 30
	 * 				   lst.removeFirst();
	 * 				   lst.removeLast();
	 * 				   lst.display(); => 20
	 * */
	
}
