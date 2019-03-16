import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static class BinaryTree {
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

		public void diagonalTraversal() {
			HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
			diagonalTraversal(this.root, map, 0, 'r');
			for (int key : map.keySet()) {
				for (int val : map.get(key))
					System.out.print(val + " ");
				System.out.println();
			}
		}

		private void diagonalTraversal(Node node, HashMap<Integer, ArrayList<Integer>> map, int dist, char check) {

			if (node == null)
				return;

			if (!map.containsKey(dist)) {
				ArrayList<Integer> list = new ArrayList<>();
				list.add(node.data);
				map.put(dist, list);
			} else {
				ArrayList<Integer> list = map.get(dist);
				list.add(node.data);

			}

			diagonalTraversal(node.left, map, dist + 1, 'l');
			diagonalTraversal(node.right, map, dist, 'r');

		}

	}

	public static void main(String[] args) {
		BinaryTree bt = new BinaryTree();
		System.out.println();
		bt.diagonalTraversal();
	}
}
