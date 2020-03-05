import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AhoCorasick {

    static final int ALPHABET_SIZE = 26;

    Node[] nodes;
    //Initially number of nodes in a Trie are Zero
    int nodeCount = 0;

    public static class Node {
        
        //Parent node
        int parent = 0;
        
        //The character that the parent has
        char charFromParent;
        
        //Suffix link
        int suffLink = -1;
        int[] children = new int[ALPHABET_SIZE];
        int[] transitions = new int[ALPHABET_SIZE];
        boolean leaf = false;
        {
            Arrays.fill(children, -1);
            Arrays.fill(transitions, -1);
        }
    }

    public AhoCorasick(int max_nodes) {
        nodes = new Node[max_nodes];
        // create root node
        nodes[0] = new Node();
        nodes[0].suffLink = 0;
        
        //parent of root is always -1 (i.e, does not exists)
        nodes[0].parent = -1;
        nodeCount = 1;
    }

    public void addString(String s) {
        int cur = 0;
        for (char ch : s.toCharArray()) { //slicing the string, one character at a time
            int c = ch - 'a';
            
            //if the current node does not have this character as a child, then create a new node
            //with this character as the new node
            if (nodes[cur].children[c] == -1) {
                nodes[nodeCount] = new Node();
                
                //parent of this new node will be the current node
                nodes[nodeCount].parent = cur;
                
                //character from parent is set to the character sliced from the string
                nodes[nodeCount].charFromParent = ch;
                
                nodes[cur].children[c] = nodeCount++;
            }
            
            //current node is incremented on the same chain, one character forward
            cur = nodes[cur].children[c];
        }
        
        //after the string is completed we can set the leaf to true to indicate that the complete
        //string is terminated
        nodes[cur].leaf = true;
    }

    public int suffLink(int nodeIndex) {
        Node node = nodes[nodeIndex];
        if (node.suffLink == -1)
        
        //if the parent of node is 0, i.e., root, then suffix link will be 0 else it will be transition 
        //of suffix link of the parent node
            node.suffLink = node.parent == 0 ? 0 : transition(suffLink(node.parent), node.charFromParent);
        return node.suffLink;
    }

    public int transition(int nodeIndex, char ch) {
        int c = ch - 'a';
        Node node = nodes[nodeIndex];
        if (node.transitions[c] == -1)
        
        //if child node of 'c' is not -1, i.e, is present, then assign transition of that node with
        //the child node but if the child node is -1, and node index is 0, i.e., it is the root node,
        //then assign transition with 0, but if it is not root, then go to the next node (recursively).
            node.transitions[c] = node.children[c] != -1 ? node.children[c] : (nodeIndex == 0 ? 0 : transition(suffLink(nodeIndex), ch));
        return node.transitions[c];
    }

    public static void main(String[] args) {
        
        AhoCorasick ahoCorasick = new AhoCorasick(100);
        ahoCorasick.addString("trie");
        ahoCorasick.addString("aho");
        ahoCorasick.addString("cor");

        //this string contains "aho" twice and therefore will give both the occurrences of ti
        String s = "ahotrcohaoahocorasicktrie";
        int node = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            node = ahoCorasick.transition(node, s.charAt(i));
            if (ahoCorasick.nodes[node].leaf)
                list.add(i);
        }
        System.out.println(list);
    }
}