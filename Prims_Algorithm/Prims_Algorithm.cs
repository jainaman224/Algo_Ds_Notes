private static int MinKey(int[] key, bool[] set, int verticesCount)
{
	int min = int.MaxValue, minIndex = 0;

	for (int v = 0; v < verticesCount; ++v)
	{
		if (set[v] == false && key[v] < min)
		{
			min = key[v];
			minIndex = v;
		}
	}

	return minIndex;
}

private static void Print(int[] parent, int[,] graph, int verticesCount)
{
	Console.WriteLine("Edge     Weight");
	for (int i = 1; i < verticesCount; ++i)
		Console.WriteLine("{0} - {1}    {2}", parent[i], i, graph[i, parent[i]]);
}

public static void Prim(int[,] graph, int verticesCount)
{
	int[] parent = new int[verticesCount];
	int[] key = new int[verticesCount];
	bool[] mstSet = new bool[verticesCount];

	for (int i = 0; i < verticesCount; ++i)
	{
		key[i] = int.MaxValue;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < verticesCount - 1; ++count)
	{
		int u = MinKey(key, mstSet, verticesCount);
		mstSet[u] = true;

		for (int v = 0; v < verticesCount; ++v)
		{
			if (Convert.ToBoolean(graph[u, v]) && mstSet[v] == false && graph[u, v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u, v];
			}
		}
	}

	Print(parent, graph, verticesCount);
}

/*
Sample Input :
int[,] graph = {
	{ 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
};

Prim(graph, 5);

								


Output :
									
Edge     Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5

*/
