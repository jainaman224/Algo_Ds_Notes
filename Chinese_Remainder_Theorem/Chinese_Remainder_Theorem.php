<?php 
// Implementation of Chinese Remainder Theorem in PHP

// function to find modular multiplicative inverse of 
// 'val' under modulo 'm' 
function modInv($val, $m) { 
    $val = $val % $m; 
    for ($x = 1; $x < $m; $x++) 
        if (($val * $x) % $m == 1) 
            return $x; 
} 

/* 
findVal() returns the smallest number reqValue such that: 
reqValue % div[0] = rem[0], 
reqValue % div[1] = rem[1], 
..... 
reqValue % div[k-2] = rem[k-1] 
It is assumed that the numbers in div[] are pairwise coprime. 
*/
function findVal($div, $rem, $size) { 
	// $totalProd represents product of all numbers 
	$totalProd = 1; 
	for ($i = 0; $i < $size; $i++) 
		$totalProd *= $div[$i]; 

    // $result represents summation of 
    // (rem[i] * partialProd[i] * modInv[i]) 
    // for 0 <= i <= size-1
	$result = 0; 
	for ($i = 0; $i < $size; $i++) { 
		$partialProd = (int)$totalProd / $div[$i]; 
		$result += $rem[$i] * $partialProd * modInv($partialProd, $div[$i]); 
	} 
	
    $reqValue = $result % $totalProd;
    return $reqValue; 
} 

// Sample case to test the code
$divisor = array(5, 7, 8); 
$remainder = array(3, 1, 6); 
$size = sizeof($divisor); 
echo "Value is ". findVal($divisor, $remainder, $size); 


/* 
Sample Input as specified in the code:
Divisors: 5, 7, 8
Remainders: 3, 1, 6

Sample Output:
Value is 78
*/

?> 

