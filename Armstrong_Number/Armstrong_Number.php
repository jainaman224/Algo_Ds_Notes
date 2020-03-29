<?php
    function isArmstrongNumber($number){ 
        // Initial Sum is equal to 0;
        $sum = 0;   
        $x = $number;   
        while($x != 0)   
        {   
            $rem = $x % 10;   
            $sum = $sum + ($rem*$rem*$rem);   
            $x = $x / 10;   
        }   
          
        // Armstrong number Condition ==> given number = SumOf(cubeOf(single Digit))
        if ($number == $sum) 
            return true; 
          
        // not an armstrong number     
        return false;     
    } 
      
    // Driver Code 
    $number = 333; 
    $flag = isArmstrongNumber($number); 
    if ($flag == true) 
        echo "Given number is an Armstrong Number"; 
    else
        echo "Given number is not an Armstrong Number";
    
?>

/**
    OUTPUT: 
        Given Number is not an ArmStrong Number.
 */