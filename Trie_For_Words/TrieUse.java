import java.util.HashMap;

class TrieNode {
	char value;
	boolean isTerminal;

	HashMap<Character, TrieNode> children ;

	public TrieNode(char value) {
		this.value = value;
		children = new HashMap<>();
	}
}

class Trie {

	TrieNode root;
	int count = 0;

	public Trie() 
	{
		root = new TrieNode('\0');
	}

	public void add(String word)
	{
		add(root, word);
	}

	private void add(TrieNode root, String word)
	{
		if(word.length() == 0)
		{
			if(root.isTerminal)
				return;

			root.isTerminal = true;
			count++;
			return;
		}
		TrieNode child = root.children.get(word.charAt(0));
		if(child == null)
		{
			child = new TrieNode(word.charAt(0));
			root.children.put(word.charAt(0), child);
		}
		add(child, word.substring(1));
	}

	public boolean findWord(String word)
	{
		TrieNode currentNode = root;
		for(int i = 0; i < word.length(); i++){
			TrieNode child = currentNode.children.get(word.charAt(i));
			if(child == null){
				return false;
			}
			currentNode = child;
		}
		return currentNode.isTerminal;
	}

	public void remove(String word) 
	{
		remove(root, word);
	}

	private void remove(TrieNode root, String word)
	{
		if(word.length() == 0)
		{
			if(!root.isTerminal)
				return;

			root.isTerminal = false;
			count--;
			return;
		}

		TrieNode child = root.children.get(word.charAt(0));
		if(child == null)
			return;

		remove(child, word.substring(1));

		if(child.children.isEmpty() && !child.isTerminal)
		{
			root.children.remove(child);
		}
	}
}


class TrieUse{
	//Driver Funtion
	public static void main(String args[])
	{
		Trie trie = new Trie();
		trie.add("ayushi");
		trie.add("aman");
		trie.add("adish");
		trie.add("swati");
		trie.add("ayesha");
		trie.add("ayu");

		System.out.println(trie.findWord("ayushi"));
		System.out.println(trie.findWord("ayush"));
		System.out.println(trie.findWord("swati"));

		trie.remove("swati");
		trie.remove("ayushi");

		System.out.println(trie.findWord("ayushi"));
		System.out.println(trie.findWord("swati"));
		System.out.println(trie.findWord("ayu"));
		System.out.println(trie.findWord("ayush"));


/*		OUTPUT 

		true
		false
		true
		false
		false
		true
		false	  
*/
	}

}
