import java.util.ArrayList;
import java.util.HashMap;

public class Trie {

	public static void main(String[] args) {


		Trie trie = new Trie() ;
		trie.addWord("abc");
		trie.addWord("abd");
		trie.addWord("abl");
		trie.addWord("axc");
//		trie.display();
		//trie.displayTree();
		System.out.println(trie.searchWord("abc"));
		System.out.println(trie.searchWord("abd"));
		System.out.println(trie.searchWord("abds"));
		System.out.println(trie.searchWord("axc"));

		/* output
		 * true
		 * true
		 * false
		 * false
		 */

	}


	private class Node {
		Character ch;
		boolean eow;
		HashMap<Character, Node> table;

		public Node(Character word) {
			ch = word;
			eow = false;
			table = new HashMap<>();
		}
	}

	private Node root;
	private int numNodes;
	private int numWords;

	public Trie() {

		this.root = new Node('*');
		numWords = 0;
	}

	public void addWord(String word) {
		addWord(this.root, word);
	}

	private void addWord(Node parent, String word) {

		if (word.length() == 0) {
			parent.eow = true;
			this.numWords++;
			return;
		}

		Character ch = word.charAt(0);
		String ros = word.substring(1);

		Node child = parent.table.get(ch);

		if (child == null) {
			child = new Node(ch);
			numNodes++;
			parent.table.put(ch, child);
		}

		this.addWord(child, ros);

	}

	public boolean searchWord(String word) {
		return searchWord(this.root, word);
	}

	private boolean searchWord(Node parent, String word) {

		if (word.length()==0) {

			return parent.eow;
		}

		Character ch = word.charAt(0);
		String ros = word.substring(1);

		Node child = parent.table.get(ch);

		if (child == null) {
			return false ;
		}

		return searchWord(child, ros);

	}

	public void removeWord(String word) {
		 removeWord(this.root, word);
	}

	private void removeWord(Node parent, String word) {

		if (word.length()==0) {

			parent.eow =false;
			 this.numWords--;
		}

		Character ch = word.charAt(0);
		String ros = word.substring(1);

		Node child = parent.table.get(ch);

		if (child==null) {
			return ;
		}

		removeWord(child , ros);

		if (child.eow==false && child.table.size()==0) {

			parent.table.remove(ch);
			numNodes--;

		}


	}

	public void display() {

		this.display(this.root, "");
	}
	private void display (Node parent , String wsf) {

		if(parent.eow) {
			System.out.println(wsf);
		}

		ArrayList<Character> cks = new ArrayList<>(parent.table.keySet());
		for (Character ck : cks) {
			this.display(parent.table.get(ck) , wsf + ck);
		}



	}

	public void displayTree() {

		displayTree(this.root);
	}
	private void displayTree (Node parent) {

		String str = parent.ch + "==>";

		ArrayList<Character> cks = new ArrayList<>(parent.table.keySet());
		for (Character ck : cks) {
			str+=ck+",";
		}
		System.out.println(str);
		for (Character ck : cks) {
			this.displayTree(parent.table.get(ck) );
		}


	}



}