<?php

$val1 = 23121;
$val2 = 1422414;

function gcd($a, $b) 
{  
    if ($b == 0)  
        return $a;  
    return gcd($b, $a%$b);  
}

echo "GCD of ".$val1." and ".$val2." is ".gcd($val1,$val2);

?>