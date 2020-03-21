/*
    @author : Chand Bud
    @date : 18/03/2020

    This is the solution for tower of hanoi problem using recursion implemented in Kotlin
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
