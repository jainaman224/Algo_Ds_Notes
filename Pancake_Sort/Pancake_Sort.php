<?php

function pancakeSort(&$arr, $num)    //function which actually sorts the array
{ 
    for ($currentSize = $num; $currentSize > 1; $currentSize--)  //start with whole array as input and reduces size by 1 on every iteration
    { 
        $maxIndex = findMaxIndex($arr, $currentSize);  //finds the index of the maximum element in the array
        if ($maxIndex != $currentSize-1)      //if the maximum index is not at the end of the current array then move the element to the end 
        { 
            reverseArray($arr, $maxIndex);    //moves maximum number to the beginning
            reverseArray($arr, $currentSize-1);  //moves maximum number to the end by reversing the array
        } 
    } 
} 

function reverseArray(&$arr, $index)  //reverses the array from index 0 to index 
{ 
    $startIndex = 0; 
    while ($startIndex < $index)   //reverses till the startindex is not greater than index provided
    {  
        $temp = $arr[$startIndex];        //swapping of elements
        $arr[$startIndex] = $arr[$index]; 
        $arr[$index] = $temp; 
        $startIndex++;      //increasing starting Index of an array
        $index--;           //decreasing ending index of an array
    } 
} 

function findMaxIndex($arr, $num)   //Find the index of the maximum element in an array
{ 
    $maxIndex = 0; 
    for ($i = 0; $i < $num; $i++) 
    {
        if ($arr[$i] > $arr[$maxIndex])
        {
            $maxIndex = $i;
        }
    }              
    return $maxIndex; 
} 

  
$arr = array(112,65,12,56,100,93,20); 
$num = count($arr);    //Counts the number of elements in the array
  
pancakeSort($arr, $num); 
  
echo("Sorted Array is:\n"); 
for($i = 0;$i < $num; $i++)    //Prints the sorted array
{
    print($arr[$i]." "); 
}
  
return 0; 
?>
