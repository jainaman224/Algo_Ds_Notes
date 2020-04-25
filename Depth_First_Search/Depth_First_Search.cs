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
        DirectedGraph newgraph = new DirectedGraph(4); // Number of vertices is 4
        Console.WriteLine("Number of edges between the vertices to enter");
        int n = Convert.ToInt32(Console.ReadLine());
        for (int i=0;i<n;i++){
          int x = Convert.ToInt32(Console.ReadLine());
          int y = Convert.ToInt32(Console.ReadLine());
          newgraph.Addition_of_Edge(x, y);
        }
  
        Console.WriteLine("Enter vertex which is the starting point");
        int s = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Depth First Search Traversal starting from vertex " + s + " is : "); 
        newgraph.Depth_First_Search(s); 
    } 
} 
// Sample input:
// Number of edges between the vertices to enter
// 6
// 0 2 0 1 2 1 2 0 3 2 2 2
// Enter vertex which is the starting point
// 3

// Sample OP:
// Depth First Search Traversal starting from vertex 3 is :
// 3 2 1 0
