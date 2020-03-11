/* 
Function to implement Comb sort using JavaScript
Example : If input array is [9,7,8,3,2], then after implementing this code the output array will be [2,3,7,8,9].  
*/

function combSort(arr)
{
    // the shrink factor is taken to be 1.3
    var gap = Math.floor(arr.length / 1.3);
    
    /* loop to reduce gap and implement sorting */ 
    while(gap > 0){
        for(var i=0; i+gap < arr.length; i++){
            // swap the values using a temporary variable
                if(arr[i] > arr[i+gap]){
                    var next = arr[i+gap];
                    arr[i+gap] = arr[i];
                    arr[i] = next;
                 }
        }
        gap=Math.floor(gap / 1.3);
    }
    return arr;
};

/* psuedo data for array */
var arr = [3,9,8,2,5,1];

/* prints the solution */
console.log('The sorted array is' + combSort(arr));

/*
    Output : 1, 2, 3, 5, 8, 9
*/
