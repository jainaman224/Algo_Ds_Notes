<?php

class InsertionSort 
{
    private $arr;
    public function __construct($arr) 
    {
        $this->arr = $arr;
    }
    
    //Printing the array
    public function printArray($array) 
    {
        for($i = 0; $i < count($array); $i++) 
        {
            echo $array[$i]." ";
        }
    }    
        
    //Sorting the array
    public function sort() 
    {
        for($i = 1; $i < count($this->arr); $i++) 
            {
                $temp = $this->arr[$i];
                while($i > 0 && $temp < $this->arr[$i-1]) 
                {    
                    $this->arr[$i] = $this->arr[$i-1];
                    --$i;
                }
                $this->arr[$i] = $temp;
            }    
        return $this->arr;
    }       
}    
 
//Driver Code
echo "<p> Implementing Insertion Sort Algorithm : </p>";
$num = array();
    
    for($i = 1; $i <= rand(1, 10); $i++) 
    {    
        $num[] = $i;
    }
    shuffle($num);
    
    $is = new InsertionSort($num);
    
//Printing Unsorted array
echo "<br>Unsorted Array : ";
$is->printArray($num);
  
//Printing Sorted array
echo "<br>Sorted Array : ";
$is->printArray($is->sort());

/*
Implementing Insertion Sort Algorithm :

Unsorted Array : 5 2 3 4 8 6 1 7

Sorted Array : 1 2 3 4 5 6 7 8
*/
?>
