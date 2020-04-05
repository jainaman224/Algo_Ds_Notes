// PHP program for implementation of Z algorithm

<?php
// Prints occurrences of pat[] in data[] 
function Z_Algo($pat, $data) 
{
    $M = strlen($pat);
    $N = strlen($data);
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    $lps=array_fill(0,$M,0);
    
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray($pat, $M, $lps);
    $i = 0; // index for data[]
    $j = 0; // index for pat[]
    while ($i < $N)
    {
        if ($pat[$j] == $data[$i])
        {
            $j++;
            $i++;
        }
        if ($j == $M)
        {
            printf("\n Found pattern at index ".($i - $j)." \n");
            $j = $lps[$j - 1];
        }
        // mismatch after j matches
        else if ($i < $N && $pat[$j] != $data[$i])
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if ($j != 0)
                $j = $lps[$j - 1];
            else
                $i = $i + 1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
function computeLPSArray($pat, $M, &$lps)
{
    // length of the previous longest prefix suffix
    $len = 0;
    $lps[0] = 0; // lps[0] is always 0
    // the loop calculates lps[i] for i = 1 to M-1
    $i = 1;
    while ($i < $M)
    {
        if ($pat[$i] == $pat[$len])
        {
            $len++;
            $lps[$i] = $len;
            $i++;
        }
        else // (pat[i] != pat[len])
        {
            if ($len != 0)
            {
                $len = $lps[$len - 1];
            }
            else // if (len == 0)
            {
                $lps[$i] = 0;
                $i++;
            }
        }
    }
} 

// Driver program 
$data = "GITHUB ALGO DS NOTES GITHUB"; 
$pat = "GITHUB"; 
Z_Algo($pat, $data); 

?> 

/*  
    Sample Input: $data = "GITHUB ALGO DS NOTES GITHUB"; $pat = "GITHUB"; 
    Sample Output: Found pattern at index 0 Found pattern at index 21 
*/
