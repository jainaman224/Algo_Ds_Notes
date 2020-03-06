<?php   
/*A series of numbers in which each number is the sum of the two preceding numbers. Eg : 1, 1, 2, 3, 5, 8, etc. */
function FibonacciNum($num){ 
      
    if ($num == 0) 
        return 0;     
    else if ($num == 1) 
        return 1;     
    else
        return (FibonacciNum($num-1) +  
                FibonacciNum($num-2)); 
} 

//Driver Program -
$num = 6; 
for ($count = 0; $count < $num; $count++){   
    echo FibonacciNum($count),' '; 
} 

/*
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
*/

?> 
