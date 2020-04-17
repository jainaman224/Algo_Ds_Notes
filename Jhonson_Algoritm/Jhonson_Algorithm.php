<?php
$INF = 999999;
$adj = array();
$cost = array();

echo "Enter no of vertices".PHP_EOL ;
$vert = intval(fgets(STDIN));
echo "Enter no of Edges".PHP_EOL;
$edge = intval(fgets(STDIN));
echo "Enter the EDGE cost".PHP_EOL ;

for ($k = 1; $k = $edge; $k++)
{
    // the input and store it into adj and cost matrix
    $i = intval(fgets(STDIN));
    $j = intval(fgets(STDIN));
    $c = intval(fgets(STDIN));
    $adj[$i][$j] = $cost[$i][$j] = $c;
}

for ($i = 1; $i = $vert; $i++)
    for ($j = 1; $j = $vert; $j++)
    {
        if ($adj[$i][$j] == 0 && $i != $j)
            //If its not a edge put infinity
            $adj[$i][$j] = $INF; 
    }
    
for ($k = 1; $k = $vert; $k++)
    for ($i = 1; $i = vert; $i++)
        for ($j = 1; $j = $vert; $j++)
            //Finding the minimum
            //find minimum path from i to j through k
            $adj[$i][$j] = min(($adj[$i][$k] + $adj[$k][$j]),$adj[$i][$j] );
echo "The distance matrix of the graph";

// Output the resultant matrix
for ($i = 1; $i = $vert; $i++)
{
    for ($j = 1; $j = $vert; $j++)
    {
        if ($adj[$i][$j] != $INF)
            echo implode(', ',$adj[$i][$j]);
    }
    echo "".PHP_EOL;
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
?>
