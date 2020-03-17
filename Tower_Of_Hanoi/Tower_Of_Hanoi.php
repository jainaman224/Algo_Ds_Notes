<?php 
// Tower of Hanoi 
// Recursive Function to solve Tower of Hanoi 
function towerOfHanoi($n, $from_rod, $to_rod, $aux_rod) { 
	//base case 
	if ($n === 1) { 
	echo ("Move disk 1 from rod $from_rod to rod $to_rod \n"); 
	return; 
	} 
	
	towerOfHanoi($n-1, $from_rod, $aux_rod, $to_rod); 
	echo ("Move disk $n from rod $from_rod to rod $to_rod \n"); 
	towerOfHanoi($n-1, $aux_rod, $to_rod, $from_rod); 
} 
// number of disks 
$n = 4; 
// A, B and C are names of rods 
towerOfHanoi($n, 'A', 'C', 'B'); 
//OUTPUT:
 //Move disk 1 from rod A to rod B
 //Move disk 2 from rod A to rod C
 //Move disk 1 from rod B to rod C
 //Move disk 3 from rod A to rod B
 //Move disk 1 from rod C to rod A
 //Move disk 2 from rod C to rod B
 //Move disk 1 from rod A to rod B
 //Move disk 4 from rod A to rod C
 //Move disk 1 from rod B to rod C
 //Move disk 2 from rod B to rod A
 //Move disk 1 from rod C to rod A
 //Move disk 3 from rod B to rod C
 //Move disk 1 from rod A to rod B
 //Move disk 2 from rod A to rod C
 //Move disk 1 from rod B to rod C
 
?> 

