using System;
using System.Collections.Generic;

namespace Declaring_Method
{
    public static class Kosaraju_Algorithm
    {
        public static void Main(string[] args)
        {
            List<int>[] g = new List<int>[3];
            for (int i = 0; i < g.Length; i++)
                g[i] = new ArrayList<>(); 

            //Initializing the List.
            g[2].Add(0);
            g[2].Add(1);
            g[0].Add(1);
            g[1].Add(0);

            List<List<int>> components = scc(g);

            //Final Output
            foreach (int i in components)
            {
                Console.WriteLine(i);
            }
        }
        
        public static List<List<int>> scc(List<int>[] graph)
        {
            int n = graph.Length; // Storing length of the graph
            bool[] used = new bool[n];
            List<int> order = new ArrayList<>();
            for (int i = 0; i < n; i++)
                if (!used[i])
                    dfs(graph, used, order, i);

            List<int>[] reverseGraph = new List<int>[n];
            for (int i = 0; i < n; i++)
                reverseGraph[i] = new ArrayList<>();
            for (int i = 0; i < n; i++)
                foreach (int j in graph[i])
                    reverseGraph[j].Add(i);

            List<List<int>> components = new ArrayList<>();
            fill(used, false);
            order.Reverse(); // Reversing the contents

            foreach (int u in order)
                if (!used[u])
                {
                    List<int> component = new ArrayList<>();
                    dfs(reverseGraph, used, component, u);
                    components.Add(component);
                }

            return components;
        }

        //Depth First Search
        static void dfs(List<int>[] graph, bool[] used, List<int> res, int u)
        {
            used[u] = true;
            foreach (int v in graph[u])
                if (!used[v])
                    dfs(graph, used, res, v);
            res.Add(u);
        }

        //To fill the bool array
        public static void fill<T>(this T[] originalArray, T with)
        {
            for (int i = 0; i < originalArray.Length; i++)
            {
                originalArray[i] = with;
            }
        }

    }
}
/*OUTPUT:
2
1
0*/
