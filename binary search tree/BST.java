import java.util.ArrayDeque;
public class BST {
	Node root;
	void insert(int key) {
		if(root == null) {
			root = new Node(key);
		}
		else root.insert(key);
	}
	void inorder() {
		if(root == null) return;
		else root.inorder();
	}
	void preorder() {
		if(root == null) return;
		else root.preorder();
	}
	void postorder() {
		if(root == null) return;
		else root.postorder();
	}
	void levelorder() {
		if(root == null) return;
		else {
			ArrayDeque<Node> deq = new ArrayDeque<Node>();
			deq.addLast(root);
			while ( !deq.isEmpty() ) { // until queue is not empty
			    Node n = deq.removeFirst();
			    System.out.print(n.data + " ");
			    if (n.left != null)
				deq.addLast(n.left);
			    if (n.right != null)
				deq.addLast(n.right);
			}
			System.out.println();
		}
	}
	boolean search(int key) {
		if(root == null) return false;
		else return root.search(key);
	}
	void delete(int key) {
		if(root == null) return;
		else if(root.data == key) {
			Node pp = root.left; // pp = predecessor parent
			if(pp.right == null) {
				root.data = pp.data;
				root.left = pp.left;
			}
			else {
				Node p = pp.right;   // p = predecessor
				while(p.right != null) {
					pp = p;
					p = p.right;
				}
				root.data = p.data;
				pp.right = p.left;
			}
		}
		else root.delete(key);
	}
}
