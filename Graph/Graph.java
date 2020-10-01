import java.io.*;
import java.util.*;

class Graph
{
    private int numberOfNodes;
    private LinkedList<Integer> adjacencyList[];

    Main(int nodesCount)
    {
        numberOfNodes = nodesCount;
        adjacencyList = new LinkedList[numberOfNodes];
        
        for(int i=0;i<numberOfNodes;i++)
        {
            adjacencyList[i] = new LinkedList();
        }
    }
    
    void addEdge(int a, int b)
    {
        adjacencyList[a].add(b);
        adjacencyList[b].add(a);
    }
    
    void showConnections()
    {
        for(int i=0; i<numberOfNodes;i++)
        {
            System.out.println(i+" -->" + adjacencyList[i]);
            System.out.println();
        }
    }


	public static void main(String[] args) {
		Graph graph1 = new Graph(7);
		
		graph1.addEdge(3, 1);
        graph1.addEdge(3, 4);
        graph1.addEdge(4, 2);
        graph1.addEdge(4, 5);
        graph1.addEdge(1, 2);
        graph1.addEdge(1, 0);
        graph1.addEdge(0, 2);
        graph1.addEdge(6, 5);
        
        graph1.showConnections();
	}

}

//OUTPUT 
// 0--> [1, 2] 
// 1--> [3, 2, 0] 
// 2--> [4, 1, 0] 
// 3--> [1, 4] 
// 4--> [3, 2, 5] 
// 5--> [4, 6] 
// 6--> [5]
