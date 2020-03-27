<?php
  
  /*
    
    Heap Sort is a comparison-based sorting technique performed on a Heap data structure
        
  */
 
function MaxHeapify(&$data, $heapSize, $index) {
    $left = ($index + 1) * 2 - 1; // left = 2*i + 1 
    $right = ($index + 1) * 2; // right = 2*i + 2 
    $largest = 0;

    // To heapify a subtree rooted with node i which is 
    // an index in arr[]. n is size of heap 
     if ($left < $heapSize && $data[$left] > $data[$index])  // If left child is larger than root 
         $largest = $left;
     else
         $largest = $index;
 
     if ($right < $heapSize && $data[$right] > $data[$largest]) // If right child is larger than largest so far 
         $largest = $right;
  
     if ($largest != $index)  // If largest is not root 
     {
         $temp = $data[$index];
         $data[$index] = $data[$largest];
         $data[$largest] = $temp;
 
         //Recursively heapify the affected sub-tree 
         MaxHeapify($data, $heapSize, $largest);
      }
}
 
function HeapSort(&$data, $count) {
    $heapSize = $count;
 
    // Build heap (rearrange array) 
    for ($p = ($heapSize - 1) / 2; $p >= 0; $p--)
        MaxHeapify($data, $heapSize, $p);
 
    // One by one extract an element from heap
    for ($i = $count - 1; $i > 0; $i--)
    {
        $temp = $data[$i];
        $data[$i] = $data[0];
        $data[0] = $temp;
 
        $heapSize--;
        MaxHeapify($data, $heapSize, 0);
    }
}
 
// example of driver function
$array = array(20 , 43 , 65 , 88 , 11 , 33 , 56 , 74);
HeapSort($array , 8);
print_r($array);
 
 // output
   /*Array
   (
    [0] => 11
    [1] => 20
    [2] => 33
    [3] => 65
    [4] => 43
    [5] => 56
    [6] => 74
    [7] => 88
    )
    
*/

?>
