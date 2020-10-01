/*
    @author: kunal-kushwaha
    @date: 21/03/2019
*/

import java.util.Scanner;

public class Tower_Of_Hanoi {

    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Number of discs: ");
        int N = input.nextInt();

        towerOfHanoi(N, "T1", "T2", "T3");
        int c = count(N, "T1", "T2", "T3");
        System.out.println(c);

    }

    static void towerOfHanoi(int n, String from, String to, String aux){
        if (n == 1)
        {
            System.out.println("Move 1th disc from " +  from + " to " + to);
            return;
        }
        towerOfHanoi(n-1, from, aux, to);

        System.out.println("Move " + n + "th disc from " +  from + " to " + to);

        towerOfHanoi(n-1, aux, to, from);
    }

    /*
        This is just for demonstration. The number of steps can be found of in constant time:
        Number of steps = 2^N − 1, where N is the number of discs.
    */
    static int count(int n, String from, String to, String aux){
        if (n == 1)
        {
            int count = 0;
            count += 1;
            return count;
        }
        return count(n-1, from, aux, to) + 1 + count(n-1, aux, to, from);
    }

}

/*
OUTPUT :

    Enter Number of discs:
    3
    Move 1th disc from T1 to T2
    Move 2th disc from T1 to T3
    Move 1th disc from T2 to T3
    Move 3th disc from T1 to T2
    Move 1th disc from T3 to T1
    Move 2th disc from T3 to T2
    Move 1th disc from T1 to T2
    7

*/
