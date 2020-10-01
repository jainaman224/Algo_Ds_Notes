<?php

$list = array(2, 4, 6, 7, 3, 1, 5);
$val1 = 4;
$val2 = 9;

function linear_search($list, $val, $count)
{
    for($i = 0; $i < $count ; $i++)
    {
        if($list[$i] == $val)
            return $i;
    }

    return -1;
}

if(linear_search($list,$val1,count($list)) != -1)
        echo $val1." Found<br>" ;
    else
        echo $val1." Not Found<br>";

if(linear_search($list,$val2,count($list)) != -1)
        echo $val2." Found<br>" ;
    else
        echo $val2." Not Found<br>";

?>
