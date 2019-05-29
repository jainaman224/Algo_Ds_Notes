import java.io.*;
import java.util.Scanner;

public class Josephus_Problem
{
    public static int Josephus(int n, int m) {
        // base case when only 1 person left return 0 assuming people numbered from 0 to n -1 
        if (n == 1) {
        return 0;
        }
        // recursive function to calculate survivor's position.
        return(Josephus(n - 1, m) + m) % n;
    }
    public static void main(String args[]) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of persons : ");
        n = sc.nextInt();
        // m <= n
        System.out.print("Enter the value of m : ");
        m = sc.nextInt();
        // printing survivor's position with people number form 1 to n in circle.
        System.out.println("Survivor's position : " + (Josephus(n, m) + 1));
        sc.close();	
    }
}
/*
Input :
Enter the number of persons : 15
Enter the value of m : 5
Output :
Survivor's position : 1
 */
