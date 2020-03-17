import java.util.*;
class Node {
    char value;
    Node left, right;
    Node(char data) {
        value = data;
        left = right = null;
    }
}
class expressionTree {
    void inorder_taversal(Node node) {
        if (node != null) {
            inorder_taversal(node.left);
            System.out.print(node.value + " ");
            inorder_taversal(node.right);
        }
    }
    // func. to check if 'c' is an operator or not
    boolean isOp(char cc) {
        if (cc == '+' || cc == '-' || cc == '*' || cc == '/' || cc == '^') {
            return true;
        }
        return false;
    }
    // Returns root of constructed tree for given postfix expression
    Node constructTree(char postfix[]) {
        Stack<Node> stack = new Stack();
        Node t, t1, t2;
        // Traverse through each character of input expression
        for (int i = 0; i < postfix.length; i++) {
            // If operand, simply push into stack
            if (!isOp(postfix[i])) {
                t = new Node(postfix[i]);
                stack.push(t);
            } else {
                t = new Node(postfix[i]);
                // Pop two top nodes
                t1 = stack.pop();
                t2 = stack.pop();
                // make children
                t.right = t1;
                t.left = t2;
                stack.push(t);
            }
        }
        // only element will be root of expression tree
        t = stack.peek();
        stack.pop();
        return t;
    }
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        String postfix = scn.next();
        expressionTree tree = new expressionTree();
        char[] charArray = postfix.toCharArray();
        Node root = tree.constructTree(charArray);
        System.out.print("Output: ");
        tree.inorder_taversal(root);
    }
}

/*
   sample input : 395+2*+ 
   sample output : 3 + 9 + 5 * 2
*/
