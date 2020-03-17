<?php 
//PHP Program for BellmanFord algorithm
$INT_MAX = 0x7FFFFFFF;

class Edge
{
	public $Source;
	public $Destination;
	public $Weight;
}

class Graph
{
	public $VerticesCount;
	public $EdgesCount;
	public $edge;
}

function CreateGraph($verticesCount, $edgesCount)
{
	$graph = new Graph();
	$graph->VerticesCount = $verticesCount;
	$graph->EdgesCount = $edgesCount;
	$graph->edge = array();
	
	for ($i = 0; $i < $graph->EdgesCount; ++$i)
		$graph->edge[$i] = new Edge();

	return $graph;
}

function PrintResult($distance, $count)
{
	echo "Vertex   Distance from source" . "\xA";

	for ($i = 0; $i < $count; ++$i)
		echo $i . "\t " . $distance[$i] . "\xA";
}

function BellmanFord($graph, $source)
{
	global $INT_MAX;
	$verticesCount = $graph->VerticesCount;
	$edgesCount = $graph->EdgesCount;
	$distance = array();

	for ($i = 0; $i < $verticesCount; ++$i)
		$distance[$i] = $INT_MAX;

	$distance[$source] = 0;

	for ($i = 1; $i <= $verticesCount - 1; ++$i)
	{
		for ($j = 0; $j < $edgesCount; ++$j)
		{
			$u = $graph->edge[$j]->Source;
			$v = $graph->edge[$j]->Destination;
			$weight = $graph->edge[$j]->Weight;

			if ($distance[$u] != $INT_MAX && $distance[$u] + $weight < $distance[$v])
				$distance[$v] = $distance[$u] + $weight;
		}
	}

	for ($i = 0; $i < $edgesCount; ++$i)
	{
		$u = $graph->edge[$i]->Source;
		$v = $graph->edge[$i]->Destination;
		$weight = $graph->edge[$i]->Weight;

		if ($distance[$u] != $INT_MAX && $distance[$u] + $weight < $distance[$v])
			echo "Graph contains negative weight cycle.";
	}

	PrintResult($distance, $verticesCount);
}


//Driver Code
//Modify values below according to graph
$verticesCount = 5;
$edgesCount = 8;
$graph = CreateGraph($verticesCount, $edgesCount);

// Edge 0-1
$graph->edge[0]->Source = 0;
$graph->edge[0]->Destination = 1;
$graph->edge[0]->Weight = -1;

// Edge 0-2
$graph->edge[1]->Source = 0;
$graph->edge[1]->Destination = 2;
$graph->edge[1]->Weight = 4;

// Edge 1-2
$graph->edge[2]->Source = 1;
$graph->edge[2]->Destination = 2;
$graph->edge[2]->Weight = 3;

// Edge 1-3
$graph->edge[3]->Source = 1;
$graph->edge[3]->Destination = 3;
$graph->edge[3]->Weight = 2;

// Edge 1-4
$graph->edge[4]->Source = 1;
$graph->edge[4]->Destination = 4;
$graph->edge[4]->Weight = 2;

// Edge 3-2
$graph->edge[5]->Source = 3;
$graph->edge[5]->Destination = 2;
$graph->edge[5]->Weight = 5;

// Edge 3-1
$graph->edge[6]->Source = 3;
$graph->edge[6]->Destination = 1;
$graph->edge[6]->Weight = 1;

// Edge 4-3
$graph->edge[7]->Source = 4;
$graph->edge[7]->Destination = 3;
$graph->edge[7]->Weight = -3;

BellmanFord($graph, 0);
?>

//Output
//Vertex   Distance from source
//0        0
//1        -1
//2        2
//3        -2
//4        1
