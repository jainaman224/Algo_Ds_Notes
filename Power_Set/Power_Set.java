/*
POWER SET

A power set of a set is the set of all possible subsets of 
a given set S. 
example - {a, b, c} :
Power Set = {}, {a}, {b}, {c}, {a, b}, {a, c},  {a, b}, {b, c}, 
            {a, b, c}

Total elements in a power set of a set with n elements = 2^n
*/

import java.util.Scanner;

class Power_Set {

    public static void PowerSet(int a[], int b[], int n, int index) {
        if (index == n) {
            System.out.print("{");
            for (int i = 0; i < n; i++) {
                if (b[i] == 1) {
                    System.out.print(a[i] + " ");
                }
            }
            System.out.print("}\n");
            return;
        }
        PowerSet(a, b, n, index + 1);
        b[index] = 1;
        PowerSet(a, b, n, index + 1);
        b[index] = 0;
    }

    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.nextInt();
            b[i] = 0;
        }
        PowerSet(a, b, n, 0);
    }
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
{}
{32 }
{15 }
{15 32 }
{3 }
{3 32 }
{3 15 }
{3 15 32 }
*/
