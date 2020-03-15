public class Driver {
	public static void main(String[] args) {
		BST b=new BST();
		Scanner sc=new Scanner(); //number of numbers in an array
		for(int i=0;i<sc;i++){
			Scanner a=new Scanner();
			b.insert(a);
		}
		b.levelorder();
		b.inorder();
		b.preorder();
		b.postorder();
	}
}
