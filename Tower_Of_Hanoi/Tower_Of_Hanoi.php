<?php 

function towerOfHanoi($n, $src_rod, $dest_rod, $aux_rod) 
{
    if ($n === 1)
    {
        echo (" Move disk 1 from rod $src_rod to rod $dest_rod \n");
        return;
    }
    towerOfHanoi($n-1, $src_rod, $aux_rod, $dest_rod);
    echo (" Move disk $n from rod $src_rod to rod $dest_rod \n");
    towerOfHanoi($n-1, $aux_rod, $dest_rod, $src_rod);
} 

// number of disks 
$n = 4; 
// A, B and C are names of rods 
towerOfHanoi($n, 'A', 'C', 'B'); 
?> 

/* Sample Output

Move disk 1 from rod A to rod B 
Move disk 2 from rod A to rod C 
Move disk 1 from rod B to rod C 
Move disk 3 from rod A to rod B 
Move disk 1 from rod C to rod A 
Move disk 2 from rod C to rod B 
Move disk 1 from rod A to rod B 
Move disk 4 from rod A to rod C 
Move disk 1 from rod B to rod C 
Move disk 2 from rod B to rod A 
Move disk 1 from rod C to rod A 
Move disk 3 from rod B to rod C 
Move disk 1 from rod A to rod B 
Move disk 2 from rod A to rod C 
Move disk 1 from rod B to rod C 

*/
