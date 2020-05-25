// version 1.1
 
object FloydWarshall {
    fun doCalcs(weights: Array<IntArray>, nVertices: Int) {
        val dist = Array(nVertices) { DoubleArray(nVertices) { Double.POSITIVE_INFINITY } }
        for (w in weights) dist[w[0] - 1][w[1] - 1] = w[2].toDouble()
        val next = Array(nVertices) { IntArray(nVertices) }
        for (i in 0 until next.size) {
            for (j in 0 until next.size) {
                if (i != j) next[i][j] = j + 1
            }
        }
        for (k in 0 until nVertices) {
            for (i in 0 until nVertices) {
                for (j in 0 until nVertices) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j]
                        next[i][j] = next[i][k]
                    }
                }
            }
        }
        printResult(dist, next)
    }
 
    private fun printResult(dist: Array<DoubleArray>, next: Array<IntArray>) {
        var u: Int
        var v: Int
        var path: String
        println("pair     dist    path")
        for (i in 0 until next.size) {
            for (j in 0 until next.size) {
                if (i != j) {
                    u = i + 1
                    v = j + 1
                    path = ("%d -> %d    %2d     %s").format(u, v, dist[i][j].toInt(), u)
                    do {
                        u = next[u - 1][v - 1]
                        path += " -> " + u
                    } while (u != v)
                    println(path)
                }
            }
        }
    }
}
 
fun main(args: Array<String>) {
    val weights = arrayOf(
            intArrayOf(1, 3, -2),
            intArrayOf(2, 1, 4),
            intArrayOf(2, 3, 3),
            intArrayOf(3, 4, 2),
            intArrayOf(4, 2, -1)
    )
    val nVertices = 4
    FloydWarshall.doCalcs(weights, nVertices)
}

/*

Output:

pair     dist    path
1 -> 2    -1     1 -> 3 -> 4 -> 2
1 -> 3    -2     1 -> 3
1 -> 4     0     1 -> 3 -> 4
2 -> 1     4     2 -> 1
2 -> 3     2     2 -> 1 -> 3
2 -> 4     4     2 -> 1 -> 3 -> 4
3 -> 1     5     3 -> 4 -> 2 -> 1
3 -> 2     1     3 -> 4 -> 2
3 -> 4     2     3 -> 4
4 -> 1     3     4 -> 2 -> 1
4 -> 2    -1     4 -> 2
4 -> 3     1     4 -> 2 -> 1 -> 3

*/