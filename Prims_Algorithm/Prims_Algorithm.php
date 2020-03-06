									
$INT_MAX = 0x7FFFFFFF;

function MinKey($key, $set, $verticesCount)
{
	global $INT_MAX;
	$min = $INT_MAX;
	$minIndex = 0;

	for ($v = 0; $v < $verticesCount; ++$v)
	{
		if ($set[$v] == false && $key[$v] < $min)
		{
			$min = $key[$v];
			$minIndex = $v;
		}
	}

	return $minIndex;
}

function PrintResult($parent, $graph, $verticesCount)
{
	echo "<pre>" . "Edge     Weight" . "</pre>";
	for ($i = 1; $i < $verticesCount; ++$i)
		echo "<pre>" . $parent[$i] . " - " . $i . "    " . $graph[$i][$parent[$i]] . "</pre>";
}

function Prim($graph, $verticesCount)
{
	global $INT_MAX;
	$parent = array();
	$key = array();
	$mstSet = array();

	for ($i = 0; $i < $verticesCount; ++$i)
	{
		$key[$i] = $INT_MAX;
		$mstSet[$i] = false;
	}

	$key[0] = 0;
	$parent[0] = -1;

	for ($count = 0; $count < $verticesCount - 1; ++$count)
	{
		$u = MinKey($key, $mstSet, $verticesCount);
		$mstSet[$u] = true;

		for ($v = 0; $v < $verticesCount; ++$v)
		{
			if ($graph[$u][$v] && $mstSet[$v] == false && $graph[$u][$v] < $key[$v])
			{
				$parent[$v] = $u;
				$key[$v] = $graph[$u][$v];
			}
		}
	}

	PrintResult($parent, $graph, $verticesCount);
}

								


/*Sample Input :
									
$graph = array(
	array(0, 2, 0, 6, 0),
	array(2, 0, 3, 8, 5),
	array(0, 3, 0, 0, 7),
	array(6, 8, 0, 0, 9),
	array(0, 5, 7, 9, 0),
);

Prim($graph, 5);

								


Output :
									
Edge     Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5

*/
