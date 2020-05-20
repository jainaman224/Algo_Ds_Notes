<?php

//Floyd-Warshall Algorithm is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph.

$f = fopen('php://stdin', 'r');

$line = fgets($f);

$arr = explode(" ", $line);

$m = $arr[0]; // first int as m rows 
$n = $arr[1]; // second int as n cols

unset($arr[0]);
unset($arr[1]);

$arr = array_values($arr);
$graph = [];

for ($i = 0; $i < $m; $i++)
{
    for ($j = 0; $j < $n; $j++) 
    {
        $result[$i][$j] = current($arr);
        next($arr);
    }
}

fclose($f);

$INF = 99999;

function PrintResult($distance, $verticesCount)
{
    global $INF;	
    echo "<pre>" . "Shortest distances between every pair of vertices:" . "<br/>";

    for ($i = 0; $i < $verticesCount; ++$i)
    {
         for ($j = 0; $j < $verticesCount; ++$j)
	     {
             if ($distance[$i][$j] == $INF)
                 echo str_pad("INF", 7);
             else
                echo str_pad($distance[$i][$j], 7);
	     }
	     echo "<br/>";
    }
    echo  "</pre>";
}

function FloydWarshall($graph, $verticesCount)
{
    $distance = array();

    for ($i = 0; $i < $verticesCount; ++$i)
    {
        for ($j = 0; $j < $verticesCount; ++$j)
        {
            $distance[$i][$j] = $graph[$i][$j];
        }
    }    

    for ($k = 0; $k < $verticesCount; ++$k)
    {
        for ($i = 0; $i < $verticesCount; ++$i)
	    {
	        for ($j = 0; $j < $verticesCount; ++$j)
	        {
                if ($distance[$i][$k] + $distance[$k][$j] < $distance[$i][$j])
                    $distance[$i][$j] = $distance[$i][$k] + $distance[$k][$j];
	        }
	    }
   }
   PrintResult($distance, $verticesCount);
}

/*
Sample Input:
 
m=4
n=4
$graph = array(
	array(0, 5, $INF, 10)
	array($INF, 0, 3, $INF)
	array($INF, $INF, 0, 1)
	array($INF, $INF, $INF, 0)
)

Sample Output:

Shortest distances between every pair of vertices:
0   5   8   9
INF 0   3   4
INF INF 0   1
INF INF INF 0

*/
?>
