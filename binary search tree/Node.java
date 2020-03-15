public class Node {
	int data;
	Node left;
	Node right;
	int balanceFactor;
	Node(int d){
		data = d;
	}

	void insert(int key) {
		if(key < data) {
			if(left == null) left = new Node(key);
			else left.insert(key);
		}
		else {
			if(right == null) right = new Node(key);
			else right.insert(key);
		}
	}

	void inorder() {
		if(left != null) left.inorder();
		System.out.print(data + " ");
		if(right != null) right.inorder();
	}

	void preorder() {
		System.out.print(data + " ");
		if(left != null) left.preorder();
		if(right != null) right.preorder();
	}

	void postorder() {
		if(left != null) left.postorder();
		if(right != null) right.postorder();
		System.out.print(data + " ");
	}

	boolean search(int key) {
		if(key == data) return true;
		else if(key < data) {
			if(left == null) return false;
			return left.search(key);
		}
		else {
			if(right == null) return false;
			return right.search(key);
		}
	}

	boolean isLeaf() {
		if(left == null && right == null) return true;
		return false;
	}

	boolean hasOnlyLeft() {
		if(left != null && right == null) return true;
		return false;
	}

	boolean hasOnlyRight() {
		if(left == null && right != null) return true;
		return false;
	}

	void delete(int key) {
		if(left != null && left.data == key) {
			if(left.isLeaf()) left = null;
			else if(left.hasOnlyLeft()) left = left.left;
			else if(left.hasOnlyRight()) left = left.right;
			else {
				Node pp = left.left; // pp = predecessor parent
				if(pp.right == null) {
					left.data = pp.data;
					left.left = pp.left;
				}
				else {
					Node p = pp.right;   // p = predecessor
					while(p.right != null) {
						pp = p;
						p = p.right;
					}
					left.data = p.data;
					pp.right = p.left;
				}
			}
		}
		else if(right != null && right.data == key) {
			if(right.isLeaf()) right = null;
			else if(right.hasOnlyLeft()) right = right.left;
			else if(right.hasOnlyRight()) right = right.right;
			else {
				Node pp = right.left; // pp = predecessor parent
				if(pp.right == null) {
					right.data = pp.data;
					right.left = pp.left;
				}
				else {
					Node p = pp.right;   // p = predecessor
					while(p.right != null) {
						pp = p;
						p = p.right;
					}
					right.data = p.data;
					pp.right = p.left;
				}

			}
		}
		else if(left != null && key < data) left.delete(key);
		else if(right != null && key >= data) right.delete(key);

	}
}
