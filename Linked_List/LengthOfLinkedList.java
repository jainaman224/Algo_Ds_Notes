import java.util.*;

/*
This code is written for Strings to store in LinkedList, if you want to store numericals or any other datatype,
just replace relevent data type in place of string in class Node.
*/

class Node {
	String data;
	Node next;
	Node(String info) {
		data = info;
		next = null;
	}
}

class LinkedListLength {
	Node head;
	
	public void pushing_data_to_LL(String new_data) {
		Node new_node = new Node(new_data); // Creating the node and assign the data.
		new_node.next = head; // making the next node as head node
		head = new_node; // making head to point to new Node
	}
	public int gettingLength() {
		Node temp = head;
		int count = 0;
		while(temp != null) {
			count++;
			temp = temp.next;
		}
		return count;
	}
}

class Mainer {
	public static void main(String[] args) {
		LinkedListLength thisList = new LinkedListLength();
		
		thisList.pushing_data_to_LL("G");
		thisList.pushing_data_to_LL("S");
		thisList.pushing_data_to_LL("S");
		thisList.pushing_data_to_LL("O");
		thisList.pushing_data_to_LL("C");
		thisList.pushing_data_to_LL("2020");
		
		System.out.println("The Length of the LinkedList is: " + thisList.gettingLength());
	}
}
