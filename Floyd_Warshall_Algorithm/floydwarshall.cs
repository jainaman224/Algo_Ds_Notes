using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
 
namespace FloydWarshallAlgorithm
{
    class FloydWarshallAlgo
    {
 
        readonly static int INF = 99999;
 
        private static void Print(int[,] distance, int vertexCnt)
        {
            Console.WriteLine("Shortest distances between every pair of vertices:");
 
            for (int i = 0; i < vertexCnt; ++i)
            {
                for (int j = 0; j < vertexCnt; ++j)
                {
                    if (distance[i, j] == INF)
                        Console.Write("INF".PadLeft(7));
                    else
                        Console.Write(distance[i, j].ToString().PadLeft(7));
                }
 
                Console.WriteLine();
            }
        }
 
        public static void FloydWarshall(int[,] graph, int vertexCnt)
        {
            int[,] distance = new int[vertexCnt, vertexCnt];
 
            for (int i = 0; i < vertexCnt; ++i)
                for (int j = 0; j < vertexCnt; ++j)
                    distance[i, j] = graph[i, j];
 
            for (int k = 0; k < vertexCnt; ++k)
            {
                for (int i = 0; i < vertexCnt; ++i)
                {
                    for (int j = 0; j < vertexCnt; ++j)
                    {
                        if (distance[i, k] + distance[k, j] < distance[i, j])
                            distance[i, j] = distance[i, k] + distance[k, j];
                    }
                }
            }
 
            Print(distance, vertexCnt);
        }
        static void Main(string[] args)
        {
            int[,] Graph = {
                         { 0,   6,  INF, 11 },
                         { INF, 0,   4, INF },
                         { INF,  INF, 0,   2 },
                         { INF, INF, INF, 0 }
                           };
 
            FloydWarshall(Graph, 4);
        }
    }
}
