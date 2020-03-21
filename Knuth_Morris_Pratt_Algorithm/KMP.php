<?php

// Function to perform the LPS (Longest Proper Prefix Suffix)
function ComputeLPS(string $pattern, array &$lps) { 

    $len = 0; 
    $i = 1; 
    $M = strlen($pattern); 
    $lps[0] = 0; 

    while ($i < $M) { 
        if ($pattern[$i] == $pattern[$len]) { 
            $len++; 
            $lps[$i] = $len; 
            $i++; 
        } else { 
            if ($len != 0) { 
            $len = $lps[$len - 1]; 
            } else { 
            $lps[$i] = 0; 
            $i++; 
            } 
        } 
    } 
}

// A function to perform the Knuth Morris Algorithm for string matching.
function KMPStringMatching(string $str, string $pattern): array { 

    $matches = []; 
    $M = strlen($pattern); 
    $N = strlen($str); 
    $i = $j = 0; 
    $lps = []; 

    ComputeLPS($pattern, $lps); 

    while ($i < $N) { 

        if ($pattern[$j] == $str[$i]) { 
            $j++; 
            $i++; 
        } 

        if ($j == $M) { 
            array_push($matches, $i - $j); 
            $j = $lps[$j - 1]; 
        } else if ($i < $N && $pattern[$j] != $str[$i]) { 
            if ($j != 0) 
            $j = $lps[$j - 1]; 
            else 
            $i = $i + 1; 
        } 
    } 

    return $matches; 
} 

$txt = "AABAACAADAABABBBAABAA"; 
$pattern = "AABA"; 
// Performing the Pattern Matching Operation.
$matches = KMPStringMatching($txt, $pattern); 

if ($matches) { 
    foreach ($matches as $pos) { 
        echo "Pattern found at index : " . $pos . "\n"; 
    }
}

/*
    Complexity for the Algorithm : O(N + M)
    Where O(M) is for Computing LPS
    O(N) is for Computing KMP Algorithm. 
 */

 /*
    INPUT:
    $txt = "AABAACAADAABABBBAABAA"; 
    $pattern = "AABA"; 

    OUTPUT:

    Pattern found at index : 0
    Pattern found at index : 9
    Pattern found at index : 16
  */
?>