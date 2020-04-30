<?php
class Graph{

  protected $graph;
  protected $visitedNode = array();

  public function __construct($graph) {
    $this->graph = $graph;
  }

  // find least number of hops (edges) between 2 nodes
  // (vertices)
  public function breadthFirstSearch($origin, $destination) {
    // mark all nodes as unvisited
    foreach ($this->graph as $vertex => $adj) {
      $this->visited[$vertex] = false;
    }

    // create an empty queue
    $q = new SplQueue();

    // enqueue the origin vertex and mark as visited
    $q->enqueue($origin);
    $this->visited[$origin] = true;

    // this is used to track the path back from each node
    $path = array();
    $path[$origin] = new SplDoublyLinkedList();
    $path[$origin]->setIteratorMode(
      SplDoublyLinkedList::IT_MODE_FIFO|SplDoublyLinkedList::IT_MODE_KEEP
    );

    $path[$origin]->push($origin);

    $found = false;
    // while queue is not empty and destination not found
    while (!$q->isEmpty() && $q->bottom() != $destination) {
      $t = $q->dequeue();

      if (!empty($this->graph[$t])) {
        // for each adjacent neighbor
        foreach ($this->graph[$t] as $vertex) {
          if (!$this->visited[$vertex]) {
            // if not yet visited, enqueue vertex and mark
            // as visited
            $q->enqueue($vertex);
            $this->visited[$vertex] = true;
            // add vertex to current path
            $path[$vertex] = clone $path[$t];
            $path[$vertex]->push($vertex);
          }
        }
      }
    }

    if (isset($path[$destination])) {
      echo "$origin to $destination in ", 
        count($path[$destination]) - 1,
        " hopsn";
      $sep = '';
      foreach ($path[$destination] as $vertex) {
        echo $sep, $vertex;
        $sep = '->';
      }
      echo "\n";
    }
    else {
      echo("No route from $origin to $destination");
    }
  }
}

// Graph Array
$graph = array(
    'A' => array('B', 'C'),
    'B' => array('A', 'D', 'C'),
    'C' => array('D', 'E'),
    'D' => array('A', 'F'),
    'E' => array('B', 'D', 'F', 'A', 'C'),
    'F' => array('A', 'E', 'C'),
  );

$graphObject = new Graph($graph);

//Least number of hops between B and F
$graphObject->breadthFirstSearch('B', 'F');
// output:
// D to C in 2 hops
// B->D->F

// least number of hops between B and E
$graphObject->breadthFirstSearch('B', 'E');
// output:
// B to F in 2 hops
// B->C->E

// least number of hops between A and C
$graphObject->breadthFirstSearch('A', 'C');
// output:
// least number of A to C in 1 hops
// A->C

// least number of hops between A and G
$graphObject->breadthFirstSearch('A', 'F');
// output:
// least number of hops between A and F
// A->B->D->->F
?>