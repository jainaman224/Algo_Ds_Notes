<?php 
function SieveOfEratosthenes($n) 
{  
    $prime = array_fill(0, $n+1, true); 
    for ($p = 2; $p*$p <= $n; $p++) 
    {     
        if ($prime[$p] == true) 
        { 
            for ($i = $p*$p; $i <= $n; $i += $p) 
                $prime[$i] = false; 
        } 
    } 
    for ($p = 2; $p <= $n; $p++) 
        if ($prime[$p]) 
            echo $p." "; 
}   
$n = 30; 
echo "Following are the prime numbers "
."smaller than or equal to " .$n."\n" ; 
SieveOfEratosthenes($n); 
?> 
// Following are the prime numbers below 30
// 2 3 5 7 11 13 17 19 23 29
