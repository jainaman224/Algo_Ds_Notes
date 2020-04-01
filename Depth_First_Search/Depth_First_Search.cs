/// C# program for Depth First Search Traversal

using System; 
using System.Collections.Generic; //used for including List 
  
class DirectedGraph 
{ 
    List<int>[] adjacencylist; 
    int vertix; 
   
    DirectedGraph(int newv) //Constructor with same name as that of class
    { 
        vertix = newv; 
        adjacencylist = new List<int>[newv]; 
        for (int i = 0; i < newv; ++i) 
            adjacencylist[i] = new List<int>(); 
    } 
    
    void DFSFunction(int newv, bool[] traversed) 
    { 
        traversed[newv] = true; 
        Console.Write(newv + " "); 
        List<int> vList = adjacencylist[newv]; 
        foreach (var n in vList) 
        { 
            if (!traversed[n]) 
                DFSFunction(n, traversed); 
        } 
    } 

    void Addition_of_Edge(int newv, int var) 
    { 
        adjacencylist[newv].Add(var); 
    } 
   
    void Depth_First_Search(int newv) 
    { 
        bool[] traversed = new bool[vertix]; 
  
        DFSFunction(newv, traversed); 
    } 
    
  public static void Main(String[] args) 
    { 
        DirectedGraph newgraph = new DirectedGraph(4); 
  
        newgraph.Addition_of_Edge(0, 2); 
        newgraph.Addition_of_Edge(0, 1); 
        newgraph.Addition_of_Edge(2, 1); 
        newgraph.Addition_of_Edge(2, 0); 
        newgraph.Addition_of_Edge(3, 2); 
        newgraph.Addition_of_Edge(2, 2); 
  
        Console.WriteLine("Depth First Search Traversal starting from vertex 3 is :"); 
        newgraph.Depth_First_Search(3); 
    } 
} 

// Sample OP: 3 2 1 0
   