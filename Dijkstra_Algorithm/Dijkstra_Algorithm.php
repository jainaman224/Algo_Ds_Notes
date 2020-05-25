<?php
// PHP program to implement Dijkstra's algorithm.
// Also known as single-source shortest path algorithm.
// It is a Greedy algorithm.

// function to find unvisited vertex with minimum distance 
function getMinVertex($dist, $visited, $n){
    $minVertex = -1;
    for($i = 0; $i < $n; ++$i){
        if(!$visited[$i] && (($minVertex == -1) || ($dist[$minVertex] > $dist[$i])) ){
            $minVertex = $i;
        }
    }
    return $minVertex;
}
  
function dijkstra($graph, $vertices){
    
    $visited = array();
    $dist = array();
    
    for($i = 0; $i < $vertices; ++$i){
        $visited[$i] = false;
        $dist[$i] = PHP_INT_MAX;
    }
	
    // 0 is the source/starting vertex
    $dist[0] = 0;
	
    for($i = 0; $i < $vertices-1; ++$i){    
        $minVertex = getMinVertex($dist, $visited, $vertices);
        // Mark the minVertex as visited
        $visited[$minVertex] = true;
        
        // Explore all unvisited neighbours of minVertex
        // and update the dist array if required
        for($j = 0; $j < $vertices; ++$j){
            if($graph[$minVertex][$j] != 0 && !$visited[$j]){
                $currD = $dist[$minVertex] + $graph[$minVertex][$j];
                if($dist[$j] > $currD){
                    $dist[$j] = $currD;
                }
            }
        }   
    }
    
    // Print the vertices and their corresponding distances from the source vertex
    echo "Vertex\tDistance from source\n";
    for($k = 0; $k < $vertices; ++$k){
        echo $k."\t".$dist[$k]."\n"; 
    }
}

// Sample Graph (Sample Input) - Adjacency Matrix representation
$graph = array(
                array(0, 3, 0, 5),
	        array(3, 0, 1, 0),
	        array(0, 1, 0, 8),
	        array(5, 0, 8, 0)
              );

// Function for Dijkstra'a algorithm
dijkstra($graph, 4);

/* 
Sample Input:
$graph = array(
                array(0, 3, 0, 5),
	        array(3, 0, 1, 0),
	        array(0, 1, 0, 8),
	        array(5, 0, 8, 0)
              );

Sample Output:
Vertex    Distance from source
0              0
1              3
2              4
3              5
*/

?>
