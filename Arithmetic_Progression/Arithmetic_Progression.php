
<?php
/*
        ARITHMETIC PROGRESSION

        Any sequence of elements where the difference between any two 
        consecutive elements is equal is termed to be in A.P.
        The nth term of an A.P. is defined as (a + (n - 1)*d)
        where a is the first element of the A.P.
        d is the common difference of the A.P.
*/

    
    //input first term, i.e, a
    fscanf(STDIN, "%d\n",$a);
    
    //input common difference, i.e., d
    fscanf(STDIN, "%d\n",$d);
    
    //input number of terms, i.e, n
    fscanf(STDIN, "%d\n",$n);

    //progression[] is an array to store AP terms
    $progression[0] = $a;
    for ($i = 0; $i < $n; $i++) {
        $progression[$i + 1] = $progression[$i] + $d;
    }
    
    // output 
    for($i = 0; $i < $n; $i++) {
        echo $progression[$i];
        echo " ";
    }

    /*
    INPUT : a = 5
            d = 2
            n = 7
    OUTPUT : The term at index 7 is 17
             Sum is: 77
    VERIFICATION : The A.P. would be 5,7,9,11,13,15,17...
    */
?>
