package GSSoC;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class GENERIC_TREE_LOTRAVERSAL {

	Scanner scn = new Scanner(System.in);

	private class Node {
		int data;
		ArrayList<Node> children = new ArrayList<>();
	}

	private Node root;

	public GENERIC_TREE_LOTRAVERSAL() {
		root = takeInput(null, -1);
	}

	private Node takeInput(Node parent, int ith) {

		if (parent == null) {
			System.out.println("Enter the data for Root Node ?");
		} else {
			System.out.println("Enter the data for " + ith + " child of " + parent.data);
		}

		// take input
		int item = scn.nextInt();

		// make a new node
		Node nn = new Node();
		nn.data = item;

		System.out.println("No. of children for " + nn.data + " ?");
		int noc = scn.nextInt();

		for (int i = 0; i < noc; i++) {

			Node child = takeInput(nn, i);

			// add children in array list
			nn.children.add(child);
		}

		return nn;

	}

	public void display() {

		display(root);

	}

	private void display(Node node) {

		String str = node.data + " -> ";

		for (Node child : node.children) {
			str += child.data + ", ";
		}

		str += ".";
		System.out.println(str);

		for (Node child : node.children) {
			display(child);
		}

	}

	// level order traversal

		public void levelorder() {
			LinkedList<Node> queue = new LinkedList<Node>();

			queue.addLast(root);

			while (!queue.isEmpty()) {

				Node rn = queue.removeFirst();

				System.out.print(rn.data + " ");

				for (Node child : rn.children) {
					queue.addLast(child);
				}

			}

			System.out.println();

		}

	public static void main(String[] args) {

		  GENERIC_TREE_LOTRAVERSAL gt = new GENERIC_TREE_LOTRAVERSAL();
		  gt.levelorder();


	}

}
