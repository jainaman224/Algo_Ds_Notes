/*Fenwick Tree is used when there is a problem of range sum query with update
i.e. RMQ. Suppose you have an array and you have been asked to find sum in
range. It can be done in linear time with static array method. If will be
difficult for one to do it in linear time when you have point updates. In this
update operation is incrementing an index by some value. Brute force approach 
will take O(n^2) time but Fenwick Tree will take O(nlogn) time
*/

//Sum function
function sum(ft, index) {
    /*
    Argument
    ft     : Fenwick Tree
    index  : Index upto which you want to find prefix sum
    Initialize the result "s" then increment the value of 
    index "index".

    Returns : sum of given arr[0..index]. This function assumes 
    that the array is preprocessed and partial sums of 
    array elements are stored in ft[]. 
    */ 
    
    // Initialize sum variable to 0
    var s = 0;

    // Increment index
    index = index + 1;
    while(index > 0) {
      
        // Adding tree node to sum
        s += ft[index];

        // Update tree node 
        index -= index & (-index);
    }
    
    // Return total sum
    return s;
}

// Update function
function update(ft, size, index, val) {
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

    index += 1;
    while(index <= size) {

        // Update tree node value 
        ft[index] += val;

        // Update node index  
        index += index & (-index);
    }
}

// Build function
function construct(arr, size) {
    /*
    Argument
    arr : The original array
    size : The length of the given array
    This function will construct the Fenwick Tree 
    from the given array of length "size"

    Return : Fenwick Tree array ft[]
    */    

    // Init ft array of length 1000 with zero value initially 
    var ft = Array.from(Array(1000), () => 0);
   
    // Constructing Fenwick Tree by Update operation  
    for( var i = 0; i < size; i++) {

        // Update operation
        Update(ft, size, i, arr[i]);
    }

    // Return Fenwick Tree array
    return ft;
}

/* 
INPUT
-------
arr : [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
Print sum of freq[0...5] 
Update position 4 by adding 16
Print sum of freq[2....7] after update
Update position 5 by adding 10
Print sum of freq[2....7] after update 

OUTPUT
------ 
12
33
43 
*/  

// Given array
var arr = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9];

// Build Fenwick Tree
ft = construct(arr, 12);

// Print Sum of array from index = 0 to index = 5
console.log(sum(ft, 5));

// Increment arr[4] by 16
update(ft, 12, 4, 16);

// Print sum fron index = 2 to index = 7
console.log(sum(ft,7) - sum(ft, 2));

// Increment arr[5] by 10
update(ft, 12, 5, 10);

// Print sum from index = 2 to index = 7
console.log(sum(ft, 7) - sum(ft, 2)); 
