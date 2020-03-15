public class Driver {
	public static void main(String[] args) {
		BST b=new BST();
		b.insert(50);
		b.insert(20);
		b.insert(80);
		b.insert(30);
		b.insert(10);
		b.insert(70);
		b.insert(90);
		b.levelorder();
		b.delete(80);
		b.levelorder();
	}
}
