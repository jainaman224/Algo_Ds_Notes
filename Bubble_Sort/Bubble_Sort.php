<?php
 
 $arr = array(3, 1 ,6 , 9 , 3 );
 //Bubble sort function 
 function Bubble_Sort($arr, $size)
 {
 	for( $i = 0; $i < $size - 1; $i++)
    {
        for( $j = 0; $j < $size - $i - 1; $j++)
        {
            // Do swapp$ing
            if($arr[$j] > $arr[$j + 1])
            {
                $temp = $arr[$j];
                $arr[$j] = $arr[$j + 1];
                $arr[$j + 1] = $temp;
            }
        }
    }

   for ( $k=0 ; $k<$size;$k++)   
         echo "$arr[$k]";
}
 //Bubble sort function calling 
 Bubble_Sort($arr, 5);
 ?>
