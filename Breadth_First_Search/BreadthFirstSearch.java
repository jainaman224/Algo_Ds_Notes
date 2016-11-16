import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstSearch
{
    //structure of a node that contains data and node's state
    static class Node
    {
        int data;
        boolean visited;
        Node(int data)
        {
            this.data = data;
        }
    }
    //just a queue to maintain bfs
    private Queue<Node> queue;
    //let's define initial list of nodes
    static ArrayList<Node> list_of_nodes = new ArrayList<Node>();
    public BreadthFirstSearch()
    {
        queue = new LinkedList<Node>();
    }
    // finding the neighbors of node
    // making use of adjacency matrix
    // if adjMatrix[i][j]==1, then nodes at index i and index j are connected
    public ArrayList<Node> findNeighbours(int adjMatrix[][],Node node)
    {
        int index = -1;
        ArrayList<Node> neighbours = new ArrayList<Node>();
        for (int i = 0; i < list_of_nodes.size(); i++)
        {
            if (list_of_nodes.get(i).equals(node))
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int j = 0; j < adjMatrix[index].length; j++)
            {
                if (adjMatrix[index][j] == 1)
                    neighbours.add(list_of_nodes.get(j));
            }
        }
        return neighbours;
    }

    public  void bfs(int adjacency_matrix[][], Node node)
    {
        queue.add(node);
        node.visited = true;
        while (!queue.isEmpty())
        {
            Node element = queue.remove();
            System.out.print(element.data + "\t");
            ArrayList<Node> neighbours=findNeighbours(adjacency_matrix,element);
            for (int i = 0; i < neighbours.size(); i++)
            {
                Node n = neighbours.get(i);
                if(n != null && !n.visited)
                {
                    queue.add(n);
                    n.visited = true;
                }
            }

        }
    }

    public static void main(String arg[])
    {
        Node n1, n2, n3, n4, n5, n6, n7;
        n1 = new Node(45);
        n2 = new Node(27);
        n3 = new Node(33);
        n4 = new Node(55);
        n5 = new Node(99);
        n6 = new Node(84);
        n7 = new Node(67);

        list_of_nodes.add(n1);
        list_of_nodes.add(n2);
        list_of_nodes.add(n3);
        list_of_nodes.add(n4);
        list_of_nodes.add(n5);
        list_of_nodes.add(n6);
        list_of_nodes.add(n7);

        int adjacency_matrix[][] = {
                {0,1,1,0,0,0,0},  // Node 1: 45
                {0,0,0,1,0,0,0},  // Node 2 :27
                {0,1,0,1,1,1,0},  // Node 3: 33
                {0,0,0,0,1,0,0},  // Node 4: 55
                {0,0,0,0,0,0,1},  // Node 5: 99
                {0,0,0,0,0,0,1},  // Node 6: 84
                {0,0,0,0,0,0,0},  // Node 7: 67
        };

        System.out.println("Output");
        BreadthFirstSearch bfs = new BreadthFirstSearch();
        bfs.bfs(adjacency_matrix, n1);
    }
}


// Output:
// 45	27	33	55	99	84	67
