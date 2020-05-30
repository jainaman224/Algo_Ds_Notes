<?php
//function which actually sorts the array
function pancakeSort(&$arr, $num)    
{ 
    //start with whole array as input and reduces size by 1 on every iteration
    for ($currentSize = $num; $currentSize > 1; $currentSize--)  
    { 
        //finds the index of the maximum element in the array
        $maxIndex = findMaxIndex($arr, $currentSize);  
         //if the maximum index is not at the end of the current array then move the element to the end 
        if ($maxIndex != $currentSize-1)     
        { 
            //moves maximum number to the beginning
            reverseArray($arr, $maxIndex);
            //moves maximum number to the end by reversing the array    
            reverseArray($arr, $currentSize-1);  
        } 
    } 
} 

//reverses the array from index 0 to index 
function reverseArray(&$arr, $index)  
{ 
    $startIndex = 0; 
    //reverses till the startindex is not greater than index provided
    while ($startIndex < $index)   
    {  
        //swapping of elements
        $temp = $arr[$startIndex];        
        $arr[$startIndex] = $arr[$index]; 
        $arr[$index] = $temp; 
        //increasing starting Index of an array
        $startIndex++;      
        //decreasing ending index of an array
        $index--;           
    } 
} 

//Find the index of the maximum element in an array
function findMaxIndex($arr, $num)   
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
//Counts the number of elements in the array
$num = count($arr);    
  
pancakeSort($arr, $num); 
  
echo("Sorted Array is:\n"); 
//Prints the sorted array
for($i = 0;$i < $num; $i++)    
{
    print($arr[$i]." "); 
}
  
return 0; 

/*
Input: 
  112,65,12,56,100,93,20

Output:
  12,20,56,65,93,100,112
*/
?>
