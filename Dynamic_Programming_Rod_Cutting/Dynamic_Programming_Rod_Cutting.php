<?php
//Maximum Function 
function maximum($a , $b )
{
    if($a>$b)
    return $a ;
        else 
    return $b ;
}
//Max Money 
function money( $cost , $n)
{

     $val= new SplFixedArray($n+1);
   
     $val[0]=0;
    
     for ($i=1;$i<=$n;$i++)
     { $max_value=0;
       for($j=0;$j<$i;$j++)
        $max_value=maximum($max_value,$cost[$j]+$val[$i-$j-1]);
        $val[$i]=$max_value;
     }
     return $val[$n];
}

$cost  = array(3, 4, 5, 4, 7);
$size = sizeof($cost);
echo money($cost , $size);
//output 15

?>
