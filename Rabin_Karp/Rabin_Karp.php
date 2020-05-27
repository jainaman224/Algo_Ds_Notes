// Rabin Karp Algorithm
/*
AN : range or No of alphabets
val : AN ^ patlen-1
patlen : pattern length
PN: any prime no given input from main
*/

/* Time-Complexity:-
The average case running time of the Rabin-Karp algorithm = O(n+m).
The best case running time of the Rabin-Karp algorithm = O(n+m).
The worst-case running time of the Rabin-Karp algorithm = O(nm).
*/

<?php

$text = "XWINGO XOR WINGO";
$pattern = "WINGO";
$PN = 101;  // A prime number
search($pattern, $text, $PN);

function search($pattern, $text, $PN){
    $patlen = strlen($pattern);    // pattern length
    $txtlen = strlen($text);       // text length
    $AN = 256;
    $val = 1;
    $hpat = 0;       // pattern hash value
    $htxt = 0;       // text hash value
    for($i = 0; $i < $patlen; $i++) {
        $val = ($val * $AN) % $PN;
    }
    for($i = 0; $i < $patlen; $i++) {
         $hpat = ($AN * $hpat + $pattern[$i]) % $PN;
         $htxt = ($AN * $htxt + $text[$i]) % $PN;
    }
    for($i = 0; $i <= $txtlen - $patlen; $i++) {
        if ($hpat == $htxt ){
            // Check for patterns
            for ($j = 0; $j < $patlen; $j++) {
                if ($text[$i + $j] != $pattern[$j]) {
                    break;
                }
            }
            if ($j == $patlen) {
                echo "Found at index starting from $i";
            }
        }
        // Calculate the new pattern including i + m
        $htxt = ($AN * ($htxt - $val * $text[$i]) + $text[$i + $patlen]) % $PN;
        if($htxt < 0) {
            $htxt = $htxt + $PN;
        }
    }
}
?>

/*
INPUT : XWINGO XOR WINGO
        WINGO
        101
OUTPUT: Found at index starting from 1
        Found at index starting from 11
*/
