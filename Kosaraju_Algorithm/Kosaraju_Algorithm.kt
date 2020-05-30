import java.util.*

object SCCKosaraju
{
    fun scc(graph: Array<MutableList<Int>>): List<List<Int>>
    {
        // Storing length of the graph
        val n: Int = graph.size
        //Boolean Array Initialisation
        val used = BooleanArray(n)
        val order: MutableList<Int> = ArrayList()
        for (i in 0 until n)
            if (!used[i])
                dfs(graph, used, order, i)

        val reverseGraph: Array<MutableList<Int>> = arrayOf<MutableList<Int>>(n)
        for (i in 0 until n)
            reverseGraph[i] = ArrayList()
        for (i in 0 until n)
            for (j in graph[i])
                reverseGraph[j].add(i)

        val components: MutableList<List<Int>> = ArrayList()
        Arrays.fill(used, false)
        Collections.reverse(order) // Reversing the contents

        for (u in order) if (!used[u])
        {
            val component: MutableList<Int> = ArrayList()
            dfs(reverseGraph, used, component, u)
            components.add(component)
        }
        return components
    }

    //Depth First Search
    fun dfs(graph: Array<MutableList<Int>>, used: BooleanArray, res: MutableList<Int>, u: Int)
    {
        used[u] = true
        for (v in graph[u])
            if (!used[v])
                dfs(graph, used, res, v)
        res.add(u)
    }

    // Usage example
    @JvmStatic
    fun main(args: Array<String>)
    {
        val g: Array<MutableList<Int>> = arrayOf<MutableList<Int>>(3)
        for (i in g.indices)
            g[i] = ArrayList()

        //Initializing the List.
        g[2].add(0)
        g[2].add(1)
        g[0].add(1)
        g[1].add(0)
        val components = scc(g)
        println(components)
    }
}
/*Input:-
0
1
1
0
Output:-
[[2],[1, 0]]*/

