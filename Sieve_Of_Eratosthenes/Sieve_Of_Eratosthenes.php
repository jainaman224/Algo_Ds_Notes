<?php
function Sieve_of_Eratosthenes($num)
{
    $sieve = array_fill(0, $num + 1, true); 
    for ($i = 2; $i * $i <= $num; $i++) 
    { 
        if ($sieve[$i] == true) 
        { 
             for ($j = $i * $i; $j <= $num; $j += $i) 
                 $sieve[$j] = false; 
        } 
    } 
    for ($i = 2; $i <= $num; $i++) 
     {   
         if ($sieve[$i]) 
             echo $i." "; 
     }      
} 
$num = (int)readline('Enter an integer: '); 
echo "Prime numbers upto " .$num."\n" ; 
Sieve_of_Eratosthenes($num); 
?>

/*Input:
Enter an integer
 10
Output
 2 3 5 7
*/
