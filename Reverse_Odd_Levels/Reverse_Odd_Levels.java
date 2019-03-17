import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
public static class BinaryTree{
	Scanner scan = new Scanner(System.in);

	private class Node {
		int data;
		Node left;
		Node right;
	}

	private Node root;

	public BinaryTree() {
		levelOrderInput();
	}

	public void display() {
		display(this.root);
	}

	private void display(Node node) {
		if (node == null)
			return;

		String str = "";

		if (node.left == null)
			str += ".";
		else
			str += node.left.data;

		str += " -> " + node.data + " <- ";

		if (node.right == null)
			str += ".";
		else
			str += node.right.data;

		System.out.println(str);

		display(node.left);
		display(node.right);

	}


	public void levelOrderInput() {

		LinkedList<Integer> inputData = new LinkedList<>();
		LinkedList<Node> nodes = new LinkedList<>();

		Node root = new Node();
		int data = scan.nextInt();
		root.data = data;
		nodes.addLast(root);
		int flag = 1;
		int total = 1;
		while (flag <= total) {

			data = scan.nextInt();
			inputData.addLast(data);
			if (data != -1)
				total += 1;
			data = scan.nextInt();
			inputData.addLast(data);
			if (data != -1)
				total += 1;

			Node pos = nodes.removeFirst();

			Node lchild = new Node();
			Node rchild = new Node();

			int ldata = inputData.removeFirst();
			int rdata = inputData.removeFirst();

			if (ldata == -1)
				lchild = null;
			else
				lchild.data = ldata;

			if (rdata == -1)
				rchild = null;
			else
				rchild.data = rdata;

			pos.left = lchild;
			pos.right = rchild;
			if (lchild != null)
				nodes.addLast(lchild);
			if (rchild != null)
				nodes.addLast(rchild);

			flag++;
		}

		this.root = root;

	}

	public void reverseOddLevels() {
		int level = 0;
		LinkedList<Node> primary = new LinkedList<>();
		LinkedList<Node> helper = new LinkedList<>();
		primary.addLast(this.root);
		while (!primary.isEmpty()) {

			Node temp = primary.removeFirst();
			if (temp.left != null)
				helper.addLast(temp.left);
			if (temp.right != null)
				helper.addLast(temp.right);

			if (primary.isEmpty()) {
				if (level % 2 == 0) {
					int size = helper.size();
					ArrayList<Node> nextLevel = new ArrayList<>();
					for (int i = 0; i < size; i++) {
						Node t = helper.removeFirst();
						nextLevel.add(t);
						helper.addLast(t);
					}

					for (int i = 0, j = size - 1; i < j; i++, j--) {
						int t = nextLevel.get(i).data;
						nextLevel.get(i).data = nextLevel.get(j).data;
						nextLevel.get(j).data = t;
					}
				}
				primary = helper;
				helper = new LinkedList<>();
				level++;

			}
		}
	}
}

	public static void main(String[] args) {
		BinaryTree bt = new BinaryTree();
		bt.display();
		System.out.println();
		bt.reverseOddLevels();
		bt.display();
	}
}
