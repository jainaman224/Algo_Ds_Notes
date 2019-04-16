

// to calculate the sum of this maximum subArray
function maxSubArraySum(a, size) 
{ 
    // overall maximum variable to keep track of subarray elements for largest sum
    var max_so_far = Number.NEGATIVE_INFINITY;
    
    var max_ending_here = 0; 
  
    for (var i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    }
     
    return max_so_far; 
} 
  

// input array
var a = [-2, -3, 4, -1, -2, 1, 5, -3]; 

console.log(maxSubArraySum(a , a.length));

//   OUTPUT : 
//   7