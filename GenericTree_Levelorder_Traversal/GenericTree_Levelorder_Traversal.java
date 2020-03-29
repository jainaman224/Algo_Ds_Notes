import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class GenericTree_Levelorder_Traversal {

    Scanner scn = new Scanner(System.in);

    private class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();
    }

    private Node root;

    public GenericTree_Levelorder_Traversal() {
        root = takeInput(null, -1);
    }

    private Node takeInput(Node parent, int ith) {

        if (parent == null) {
            System.out.println("Enter the data for Root Node ?");
        } else {
            System.out.println(
                    "Enter data for " + ith + " child of " + parent.data);
        }

        // take input
        int item = scn.nextInt();

        // make a new node
        Node nn = new Node();
        nn.data = item;

        System.out.println("No. of children for " + nn.data + " ?");
        int noc = scn.nextInt();

        for (int i = 0; i < noc; i++) {

            Node child = takeInput(nn, i);

            // add children in array list
            nn.children.add(child);
        }

        return nn;

    }

    public void display() {

        display(root);

    }

    // function to display generic tree

    private void display(Node node) {

        String str = node.data + " -> ";

        for (Node child : node.children) {
            str += child.data + ", ";
        }

        str += ".";
        System.out.println(str);

        for (Node child : node.children) {
            display(child);
        }

    }

    // level order traversal

    public void levelorder() {

        // create a linked list which will be used as queue
        LinkedList<Node> queue = new LinkedList<Node>();

        // add root node to last of queue
        queue.addLast(root);

        while (!queue.isEmpty()) {

            // remove node from front and print
            Node rn = queue.removeFirst();

            System.out.print(rn.data + " ");

            // add children of current node to the end of queue
            for (Node child : rn.children) {
                queue.addLast(child);
            }

        }

        System.out.println();

    }

    public static void main(String[] args) {

        GenericTree_Levelorder_Traversal gt = new GenericTree_Levelorder_Traversal();
        gt.levelorder();

    }

}

//SAMPLE INPUT: 10 3 20 2 50 0 60 0 30 0 40 0
//OUTPUT: 10 20 30 40 50 60
