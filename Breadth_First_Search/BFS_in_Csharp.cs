//Breadth First Search ALgorithm implemented using queue in C# 

using System;
// for generic data structures  
using System.Collections.Generic;                        

namespace GraphBfs
{
    class graph
    {   //no of vertices in a graph
        private int vertices;   
        //declaraing list
        private List<Int32>[] adj;                      
        public graph(int v)                    
        {   
            //initialising Adjacency List with number of vertices
            vertices = v;
            adj = new List<Int32>[v];                     
            for(int i = 0; i < v; i++)
            {
                adj[i] = new List<int>();    
            }
        }

        public void addedge(int c,int v)                  
        {                                                 
            adj[c].Add(v);                                
            adj[v].Add(c);                                
        }  

        // function for Breadth First Search ,starting node as parameter
        public void BFS(int v)                          
        {   
            bool[] visited = new bool[vertices];          
            Queue<Int32> queue = new Queue<int>();       
            visited[v] = true;     
            // enqueuing first node in queue                       
            queue.Enqueue(v);                           
            while(queue.Count != 0)
            {
                // dequeue node from beginning of queue
                v = queue.Dequeue();                      
                Console.Write(v + " ");
                foreach(int i in adj[v])
                {
                    //only unvisited node pushed into queue
                    if( !visited[i])                    
                    {
                        visited[i] = true;               
                        queue.Enqueue(i);              
                    }
                }
            }
        }
    }

    class program                                   
    {
        static void Main(string[] args)
        {    //Taking input number of vertices
            Console.WriteLine("Enter number of vertices in a graph");     
            int v = Convert.ToInt32(Console.ReadLine());    

            graph g = new graph(v);  

            //Taking input number of edges
            Console.WriteLine("Enter number of edge in a graph");        
            int e = Convert.ToInt32(Console.ReadLine());  

            for(int i = 0; i < e; i++)                                         
            {   
                Console.WriteLine("Enter nodes of " + (i+1) +" edge");     
                string s = Console.ReadLine();

                int e1 = Convert.ToInt32(s.Split(" ")[0]);                  
                int e2 = Convert.ToInt32(s.Split(" ")[1]);                 

                g.addedge(e1, e2);                                          
            } 
            Console.WriteLine("Breadth First Search of Graph :-");
            //calling BFS function with starting node provided
            g.BFS(0);                                                      
        }
    }
}

/*Sample Input and Output

Enter number of vertices in a graph
10
Enter number of edge in a graph
12
Enter nodes of 1 edge
0 1
Enter nodes of 2 edge
0 2
Enter nodes of 3 edge
1 3
Enter nodes of 4 edge
2 4
Enter nodes of 5 edge
2 5
Enter nodes of 6 edge
3 6
Enter nodes of 7 edge
6 4
Enter nodes of 8 edge
4 5
Enter nodes of 9 edge
4 7
Enter nodes of 10 edge
7 8
Enter nodes of 11 edge
7 9
Enter nodes of 12 edge
8 9
Breadth First Search of Graph :-
0 1 2 3 4 5 6 7 8 9

Adjacency List of Sample Input

0 -> 1,2
1 -> 0,3
2 -> 0,4,5
3 -> 1,6
4 -> 2,6,5,7,
5 -> 2,4
6 -> 3,4
7 -> 4,8,9
8 -> 7,9
9 -> 7,8 

*/
