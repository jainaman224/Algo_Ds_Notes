<?php 

// Dynamic Programming implementation of LCS problem 

// Returns length of LCS for X[0..m-1], Y[0..n-1] 
function lcs( $X, $Y, $m, $n ) 
{ 
    $L = array_fill(0, $m + 1, array_fill(0, $n + 1, NULL)); 
    
    /* Following steps build L[m+1][n+1] in bottom 
    up fashion. Note that L[i][j] contains length 
    of LCS of X[0..i-1] and Y[0..j-1] */
    
    for ($i = 0; $i <= $m; $i++) 
    { 
        for ($j = 0; $j <= $n; $j++) 
        { 
            if ($i == 0 || $j == 0) 
                $L[$i][$j] = 0; 
            else if ($X[$i - 1] == $Y[$j - 1]) 
                $L[$i][$j] = $L[$i - 1][$j - 1] + 1; 
            else
                $L[$i][$j] = max($L[$i - 1][$j], $L[$i][$j - 1]); 
        } 
    } 
    
    // Following code is used to print LCS 
    $index = $L[$m][$n]; 
    $temp = $index; 
    
    // Create a character array to store the lcs string 
    $lcs = array_fill(0, $index + 1, NULL); 
    $lcs[$index] = ''; // Set the terminating character 
    
    // Start from the right-most-bottom-most corner 
    // and one by one store characters in lcs[] 
    $i = $m; 
    $j = $n; 
    while ($i > 0 && $j > 0) 
    { 
        // If current character in X[] and Y are same, 
        // then current character is part of LCS 
        if ($X[$i - 1] == $Y[$j - 1]) 
        { 
            // Put current character in result 
            $lcs[$index - 1] = $X[$i - 1]; 
            $i--; 
            $j--; 
            $index--; // reduce values of i, j and index 
        } 
    
        // If not same, then find the larger of two 
        // and go in the direction of larger value 
        else if ($L[$i - 1][$j] > $L[$i][$j - 1]) 
            $i--; 
        else
            $j--; 
    } 
    
    // Print the lcs 
    echo "LCS of " . $X . " and " . $Y . " is "; 
    for($k = 0; $k < $temp; $k++) 
        echo $lcs[$k]; 
} 

// Driver Code 
$X = "ABCDE"; 
$Y = "BCDEF"; 
$m = strlen($X); 
$n = strlen($Y); 
lcs($X, $Y, $m, $n); 

/* 
OUTPUT: 
LCS of ABCDE and BCDEF is BCDE 
*/

?> 
