<?php 
//Function to find GCD
function gcd($a, $b) 
{ 
    if ($a == 0) 
        return $b; 
    return gcd($b % $a, $a); 
} 

// Driver Code 
$a = 35; 
$b = 15; 
echo "\nGCD of ",$a ," and ", $b," is ", gcd($a, $b); 

/*
    Input
    a = 35, b = 15; 
    Output: 
    GCD of 35 and 15 is 5
*/
?> 

