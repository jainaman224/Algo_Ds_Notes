/*
    This is the solution for tower of hanoi problem using recursion implemented in Kotlin
    Tower of Hanoi is an application of recursion in which our aim is to shift n disks from source tower(peg) to destination tower(peg)
    We can use third tower as auxilary tower. In it's solution we first try to shift n-1 disks.
    Minimum number of steps required for this are 2^n-1 where n is number of disks.
*/
import java.util.Scanner

fun main() {

    val reader = Scanner(System.`in`)
    var n:Int = reader.nextInt()
    solveHanoi(n, 'A', 'C', 'B')
}

/*
    n - Number of disks
    src - Source pole
    dest - Destination pole
    aux - Auxiliary pole
*/

fun solveHanoi(n: Int,src: Char, dest: Char, aux: Char)
{
    if(n >= 1)
    {
        solveHanoi(n - 1, src, dest, aux)
        println("Move disk $n from $src to $dest")
        solveHanoi(n - 1, aux, dest, src)
    }
}

/*
Output: 
    for 3 disks
    Move disk 1 from A to C
    Move disk 2 from A to C
    Move disk 1 from B to C
    Move disk 3 from A to C
    Move disk 1 from B to C
    Move disk 2 from B to C
    Move disk 1 from A to C
*/
