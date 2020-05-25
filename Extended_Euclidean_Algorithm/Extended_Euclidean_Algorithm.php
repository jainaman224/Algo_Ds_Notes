<?php 
//Function to find GCD
function gcd($a, $b, $x, $y) 
{ 
    // Base Case 
    if ($a == 0) 
    { 
        $x = 0; 
        $y = 1; 
        return $b; 
    } 

    // To store results of recursive call 
    $gcd = gcd($b % $a, $a, $x, $y); 

    // Update x and y using results of recursive call 
    $x = $y - ($b / $a) * $x; 
    $y = $x; 
    return $gcd; 
} 

// Driver Code 
$x = 0; 
$y = 0; 
$a = 20; 
$b = 5; 
echo "\nGCD of ", $a, " and ", $b, " is ", gcd($a, $b, $x, $y); 

/*
    Input:
    a = 20, b = 5; 
    Output: 
    GCD of 20 and 5 is 5
*/
?> 
