fun main()
{
    var vert = 0
    var edge = 0
    var i = 0
    var j = 0
    var k = 0
    var c = 0
    var inf = 999999;
    var cost = Array(10, {IntArray(10)})
    var adj = Array(10, {IntArray(10)})

    println("Enter no of vertices: ")
    vert = readLine() !!.toInt()
    println("Enter no of Edges: ");
    edge = readLine() !!.toInt()
    println("Enter the EDGE cost: ");

    for (k in 1..edge)
    {
        i = readLine() !!.toInt()
        j = readLine() !!.toInt()
        c = readLine() !!.toInt()
        adj[i][j] = c
        cost[i][j] = c
    }

    for (i in 1..vert)
        for (j in 1..vert)
        {
            if (adj[i][j] == 0 && i != j)
                //If its not a edge put infinity
                adj[i][j] = inf
        }
    
    for (k in 1..vert)
        for (i in 1..vert)
            for (j in 1..vert)
                //Finding the minimum
                //find minimum path from i to j through k
                if ((adj[i][k] + adj[k][j]) > adj[i][j])
                    adj[i][j] = adj[i][j]
                else
                    adj[i][j] = (adj[i][k] + adj[k][j])
    
    println("The distance matrix of the graph.");
    // Output the resultant matrix
    for (i in 1..vert)
    {
        for (j in 1..vert)
        {
            if (adj[i][j] != inf)
                print("${adj[i][j]} ");
        }
        println(" ");
    }
}

/*Enter no of vertices:
3
Enter no of Edges:
5
Enter the EDGE cost:
1 2 8

2 1 12

1 3 22

3 1 6

2 3 4
The distance matrix of the graph.
0  8  12
10  0  4
6  14  0*/
