<?php
// PHP implementation of Boyer Moore Algorithm for Pattern Searching using 
// Bad Character Heuristic

// Function for Boyer Moore's bad character heuristic  
function badCharHeuristic(&$badChar, $str, $size){
    
    // Initialize all occurrences as -1 
    for ($i = 0; $i < 256; $i++)
        $badChar[$i] = -1;
		
    // To fill actual value of last occurrence of characters  
    for ($i = 0; $i < $size; $i++)
        $badChar[ord($str[$i])] = $i;
}

// Function that uses Bad Character Heuristic of Boyer Moore Algorithm 
// to search pattern
function search($text, $pattern) {
    
    $patternLength = strlen($pattern);
    $textLength = strlen($text);
    $i = 0;
	
    $badChar = array();
    badCharHeuristic($badChar, $pattern, $patternLength);
	
    // s represents pattern shift with respect to text
    $s = 0;

    while ($s <= ($textLength - $patternLength)){
	    
        $j = $patternLength - 1;
        // Reduce index j of pattern while characters of pattern and text match at current shift
        while ($j >= 0 && $pattern[$j] == $text[$s + $j])
            $j--;
			
        // If the pattern is present at current shift, then index j will become -1, so  
        // Shift the pattern so that the next character in text aligns 
        // with the last occurrence of it in pattern.
        // Else, Shift the pattern so that the bad character in text aligns with 
        // the last occurrence of it in pattern.
        if ($j < 0){
            $arr[$i++] = $s;
            $s += ($s + $patternLength < $textLength) ? 
                        $patternLength - $badChar[ord($text[$s + $patternLength])] : 1;
        }
        else
            $s += max(1, $j - $badChar[ord($text[$s + $j])]);
    }
	
    for ($j = 0; $j < $i; $j++)
        $result[$j] = $arr[$j];
    return $result;
}

// Sample Input
$text = "I scream, you scream, we all scream for ice cream";
$pattern = "scream";

$occ = search($text, $pattern);
echo "Occurrences of pattern in text are as follows:\n";
foreach ($occ as $res){
    echo "$res \n";
}

/*
Sample Input as mentioned in the code-
$text = "I scream, you scream, we all scream for ice cream"
$pattern = "scream"

Sample Output-
Occurrences of pattern in text are as follows:
2
14
29
8
*/
?>


