/*Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an 
edge of the least possible weight that connects any two trees in the forest

Code in C#
*/

using System;

public struct Edge
{
    public int Source;
    public int Destination;
    public int Weight;
}

public struct Graph
{
    public int VerticesCount;
    public int EdgesCount;
    public Edge[] edge;
}

public struct Subset
{
    public int Parent;
    public int Rank;
}

public static Graph CreateGraph(int verticesCount, int edgesCoun)
{
    Graph graph = new Graph();
    graph.VerticesCount = verticesCount;
    graph.EdgesCount = edgesCoun;
    graph.edge = new Edge[graph.EdgesCount];

    return graph;
}

private static int Find(Subset[] subsets, int i)
{
    if (subsets[i].Parent != i)
	    subsets[i].Parent = Find(subsets, subsets[i].Parent);

    return subsets[i].Parent;
}

private static void Union(Subset[] subsets, int x, int y)
{
    int xroot = Find(subsets, x);
    int yroot = Find(subsets, y);

    if (subsets[xroot].Rank < subsets[yroot].Rank)
	    subsets[xroot].Parent = yroot;
    else if (subsets[xroot].Rank > subsets[yroot].Rank)
	    subsets[yroot].Parent = xroot;
    else
    {
         subsets[yroot].Parent = xroot;
         ++subsets[xroot].Rank;
    }
}

private static void Print(Edge[] result, int e)
{
    for (int i = 0; i < e; ++i)
        Console.WriteLine("{0} -- {1} == {2}", result[i].Source, result[i].Destination, result[i].Weight);
}

public static void Kruskal(Graph graph)
{
    int verticesCount = graph.VerticesCount;
    Edge[] result = new Edge[verticesCount];
    int i = 0;
    int e = 0;

    Array.Sort(graph.edge, delegate (Edge a, Edge b)
        return a.Weight.CompareTo(b.Weight);
    );

    Subset[] subsets = new Subset[verticesCount];

    for (int v = 0; v < verticesCount; ++v)
    {
	    subsets[v].Parent = v;
	    subsets[v].Rank = 0;
    }

    while (e < verticesCount - 1)
    {
	    Edge nextEdge = graph.edge[i++];
	    int x = Find(subsets, nextEdge.Source);
	    int y = Find(subsets, nextEdge.Destination);

	    if (x != y)
	    {
		    result[e++] = nextEdge;
		    Union(subsets, x, y);
	    }
    }

    Print(result, e);
}

/*
Input
=int verticesCount = 4;
int edgesCount = 5;
Graph graph = CreateGraph(verticesCount, edgesCount);

// Edge 0-1
graph.edge[0].Source = 0;
graph.edge[0].Destination = 1;
graph.edge[0].Weight = 10;

// Edge 0-2
graph.edge[1].Source = 0;
graph.edge[1].Destination = 2;
graph.edge[1].Weight = 6;

// Edge 0-3
graph.edge[2].Source = 0;
graph.edge[2].Destination = 3;
graph.edge[2].Weight = 5;

// Edge 1-3
graph.edge[3].Source = 1;
graph.edge[3].Destination = 3;
graph.edge[3].Weight = 15;

// Edge 2-3
graph.edge[4].Source = 2;
graph.edge[4].Destination = 3;
graph.edge[4].Weight = 4;

Kruskal(graph);

Output
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10

*/
