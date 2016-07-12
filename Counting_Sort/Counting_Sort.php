<?php
$list = array(3, 4, 5, 4, 7);
//Counting sort Function 
function countingsort($list , $largest,  $arrsize )
{
            $size = $largest + 1;

            $b= new SplFixedArray(10000);
            for($i=0 ; $i<$arrsize;$i++)
            {
                 $val = $list[$i];
                 $b[$val] =   $b[$val]+1;
            }
           $l = 0; 
           $r=0;
             
           $c= array(0,0,0,0,0);
            for ($j = 0; $l < $size; $j++)
            {


                while ($b[$l] != 0)
                {
                    $c[$r] = $l;
                    $r++;
                    $b[$l]=$b[$l]-1;

                }
                $l++;
            }
         
         for ( $k=0 ; $k<$arrsize;$k++)   
         echo $c[$k];

}
//Calling Countingsort function 
countingsort($list , 7 , 5);
// output 34457
?>
