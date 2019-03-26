
public class Main {

	public static void main(String[] args) {
		int[] pre = { 20, 10, 5, 15, 30, 25, 35 };
		int[] in = { 5, 10, 15, 20, 25, 30, 35 };
		BinaryTree bt = new BinaryTree(pre, in);
		bt.display();
	}

	public static class BinaryTree {

		private class Node {
			int data;
			Node left;
			Node right;
		}

		private Node root;

		public BinaryTree(int[] preorder, int[] in) {
			this.root = constructPre(preorder, 0, preorder.length - 1, in, 0, in.length - 1);
		}

		private Node constructPre(int[] pre, int plo, int phi, int[] in, int ilo, int ihi) {

			if (plo > phi || ilo > ihi)
				return null;

			Node root = new Node();
			root.data = pre[plo];
			int si = -1;
			for (int i = ilo; i <= ihi; i++) {
				if (in[i] == pre[plo]) {
					si = i;
					break;
				}
			}

			int nel = si - ilo;
			root.left = constructPre(pre, plo + 1, plo + nel, in, ilo, si - 1);
			root.right = constructPre(pre, plo + nel + 1, phi, in, si + 1, ihi);
			return root;
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
	}

}
