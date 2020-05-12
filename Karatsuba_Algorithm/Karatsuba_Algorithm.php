<?php
/*
The Karatsuba Algorithm implements faster multiplication, 
than the traditional approach.
*/
function karatsuba($num1,$num2){

    // for single digit number multiply directly
    if ($num1 < 10 || $num2 < 10) {
        return $num1 * $num2;
    }

    $num1Str = strval($num1);
    $num2Str = strval($num2);

    $n = min(strlen($num1Str),strlen($num2Str));
    $half = round($n / 2);

    // divide num1 into two halves
    $num1_H = intval(substr($num1Str,0, strlen($num1Str) - $half));
    $num1_L = intval(substr($num1Str,strlen($num1Str) - $half, strlen($num1Str)));

    // divide num2 into two halves
    $num2_H = intval(substr($num2Str,0, strlen($num2Str) - $half));
    $num2_L = intval(substr($num2Str,strlen($num2Str) - $half, strlen($num2Str)));

    // using the KaratSuba Definition
    $s1 = karatSuba($num1_L, $num2_L);
    $s2 = karatSuba($num1_L + $num1_H, $num2_L + $num2_H);
    $s3 = karatSuba($num1_H, $num2_H);

    $s4 = $s2 - $s3 -$s1;

    // karatsuba formula for finding product
    $result = $s3 * pow(10, 2 * $half) + $s4 * pow(10, $half) + $s1;

    return $result;
}

$num1 = 23984;
$num2 = 183672;
echo "\nInputs are: ".$num1." ".$num2;
$result = karatSuba($num1,$num2);
echo "\nThe result is: ".$result;

// Input :
// 23984 183672
// Output: 
// 4405189248
?>