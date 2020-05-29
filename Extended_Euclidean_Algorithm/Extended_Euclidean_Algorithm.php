<?php 

/* Extended Euclidean Algorithm 
  ==============================
  GCD of two numbers is the largest number that divides both of them.  
    GCD(a,b) = ax + by
  If we can find the value of  x and y then we can easily find the 
  value of GCD(a,b) by replacing (x,y) with their respective values.
*/

//Function to find GCD
//This function returns an array having elements gcd, x and y
function gcd($a, $b) 
{  
    // Base Case 
    if ($a == 0)
        return array($b, 0, 1);
        
    // To store results of recursive call 
    $arr = gcd($b % $a, $a);
    // Update x and y using results of recursive call 
    $gcd = $arr[0];
    $x = $arr[1];
    $y = $arr[2];
    return array($gcd, (int)($y - ($b / $a) * $x), $x);
}
 
// Driver Code 
$a = readline("Enter number 1 : ");
$b = readline("Enter number 2 : ");
$arr = gcd($a, $b);
echo "\nGCD of ", $a, " and ", $b, " is ", $arr[0];
echo "\nx = ", $arr[1];
echo "\ny = ", $arr[2];


/*
Sample input/output: 
Enter number 1 : 100                                                                                                          
Enter number 2 : 20                                                                                                                                                                                                                                         
GCD of 100 and 20 is 20                                                                                                       
x = 0                                                                                                                         
y = 1   
*/ 
?>
