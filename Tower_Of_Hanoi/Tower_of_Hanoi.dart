/* Tower of Hanoi is a mathematical problem where we have three rods A, B and C and n
number of disks where n is taken from user in this code. 
The goal of the problem is to transfer the entire stack of disks to another rod,
obeying the conditions as follows:
1) Only one disk can be moved at a time.
2) Each move consists of taking the top disk from one of the stacks and placing 
it on top of another stack.
3) No disk can be placed on top of a smaller disk. */

import 'dart:io';

void tower (int disks, String beg, String aux, String end)
{
    if (disks == 1)
    {
    	print ("\nMove disk 1 from $beg ---> $end \n") ;
	return ;
    }
    tower (disks - 1, beg, end, aux) ;
    print ("\nMove disk $disks from $beg ---> $end \n") ;
    tower (disks - 1, aux, beg, end) ;
    return ;
}

main()
{
    print ("ENTER NUMBER OF DISCS :\n") ;
    int disks = int.parse (stdin.readLineSync()) ;
    tower (disks, "A", "B", "C") ;
}

/*OUTPUT:
ENTER NUMBER OF DISCS:
4
Move disk 1 from A ---> B
Move disk 2 from A ---> C
Move disk 1 from B ---> C
Move disk 3 from A ---> B
Move disk 1 from C ---> A
Move disk 2 from C ---> B
Move disk 1 from A ---> B
Move disk 4 from A ---> C
Move disk 1 from B ---> C
Move disk 2 from B ---> A
Move disk 1 from C ---> A
Move disk 3 from B ---> C
Move disk 1 from A ---> B
Move disk 2 from A ---> C
Move disk 1 from B ---> C */
