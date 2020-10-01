<?php

$str1 = "namanchamanbomanamansanam";
$str2 = "aman";

$len1 = strlen($str1);
$len2 = strlen($str2);

for($i = 0; $i <= $len1 - $len2; $i++)
    {
        for($j = 0; $j < $len2; $j++)
            if($str1[$i + $j] != $str2[$j])
                break;

        if($j == $len2)
           echo "Pattern Found at ".($i+1)."<br>" ;
    }
?>
