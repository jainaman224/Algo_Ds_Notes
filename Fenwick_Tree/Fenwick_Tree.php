<?php
/*Fenwick Tree is used when there is a problem of range sum query with update
i.e. RMQ. Suppose you have an array and you have been asked to find sum in
range. It can be done in linear time with static array method. If will be
difficult for one to do it in linear time when you have point updates. In this
update operation is incrementing an index by some value. Brute force approach 
will take O(n^2) time but Fenwick Tree will take O(nlogn) time
*/

//Sum function
function sum ($ft, $index) {
    /*
    Argument
    ft     : Fenwick Tree
    index  : Index upto which you want to find prefix sum
    Initialize the result "s" then increment the value of 
    index "index".

    Returns : sum of given array[0..index]. This function assumes 
    that the array is preprocessed and partial sums of 
    array elements are stored in ft[]. 
    */ 

    // Initialize sum variable to 0
    $s = 0;  
    // Increment index
    $index = $index + 1;
    while( $index > 0){ 
        // Adding tree node to sum
        $s = $s + $ft[$index]; 
        // Update tree node
        $index -= $index & (-$index); 
    }
    // Return total sum
    return $s;
} 
  
// Update function
function update ($ft, $size, $index, $val) { 
    /*
    Arguments
    ft    : Fenwick Tree
    index : Index of ft to be updated
    size  : Length of the original array
    val   : Add val to the index "index"
    Traverse all ancestors and add 'val'.
    Add 'val' to current node of Fenwick Tree. 
    Update index to that of parent in update.  
    */
    $index += 1;
    while( $index <= $size){ 
        // Update tree node value
        $ft[$index] = $ft[$index] + $val; 
        // Update node index
        $index += $index and (-$index);
    }
  } 
  
  
// Build function
function construct($array, $size) { 
    /*
    Argument
    array : The original array
    size : The length of the given array
    This function will construct the Fenwick Tree 
    from the given array of length "size"

    Return : Fenwick Tree array ft[]
    */    
    // Init ft array of length 1000 with zero value initially 
    $ft = array(); 
    // Constructing Fenwick Tree by Update operation  
    for( $i = 0; $i < $size; $i++) {
        // Update operation
        update($ft, $size, $i, $array[$i]);
    }
    // Return Fenwick Tree array
    return $ft;
}

//Driver code to test above methods 
function main() {
    $array = array(2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9); 
    $n = construct($freq, sizeof($array)); 
    echo implode(sum($n, 5));
    $array[3] = $array[3] + 6;
    update($n, sizeof($array), 3, 6) ;
    echo implode(sum($n, 5)); 
}

/* 
INPUT
-------
array : [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
Sum of elements in array[0..5] is 12
Sum of elements in array[0..5] after update is 18

OUTPUT
------ 
12
18
*/  

?>
