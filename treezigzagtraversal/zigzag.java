import java.util.*;

/**
 * zigzag
 */
// sample input
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false
// false true 73 false false
// sample output
// 10 30 20 40 50 60 73
public class zigzag {
    static Scanner sc = new Scanner(System.in);

    static class node {
        int data;
        node left;
        node right;

        node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    private static node root;

    private static node buildtree() {
        int data = sc.nextInt();
        node n = new node(data);
        boolean choice1 = sc.nextBoolean();
        if (choice1)
            n.left = buildtree();
        boolean choice2 = sc.nextBoolean();
        if (choice2)
            n.right = buildtree();
        return n;
    }

    private static void zigzag() {
        if (root == null)
            return;
        boolean islr = true;
        Stack<node> currentlevel = new Stack<>();
        Stack<node> nextlevel = new Stack<>();
        currentlevel.push(root);
        while (!currentlevel.isEmpty()) {
            node n = currentlevel.pop();
            System.out.print(n.data + " ");
            if (islr) {
                if (n.left != null)
                    nextlevel.push(n.left);
                if (n.right != null)
                    nextlevel.push(n.right);
            } else {
                if (n.right != null)
                    nextlevel.push(n.right);
                if (n.left != null)
                    nextlevel.push(n.left);
            }

            if (currentlevel.isEmpty()) {
                islr = !islr;
                Stack<node> temp = currentlevel;
                currentlevel = nextlevel;
                nextlevel = temp;
            }

        }
    }

    public static void main(String[] args) {
        root = buildtree();
        zigzag();
    }

}