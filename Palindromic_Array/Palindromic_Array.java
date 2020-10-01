/* A Palindromic Sequence is a sequence of numbers which is 
the same when read both forward and backward.
Example: 1, 2, 3, 2, 1 */

import java.util.Scanner;

class Palindromic_Array
{
    public static boolean isPalindromic(int arr[], int N) 
    {
        for (int i = 0; i <= (N / 2); i++)
        {
            if (arr[i] != arr[N -i -1])
                return false;
        }
        return true;
    } 

    public static void main(String args[])
    {
        System.out.println("Enter number of elements in array");
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println("Enter elements of array");
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }
        if (isPalindromic(arr, N))
            System.out.println("The array is palindromic");
        else
            System.out.println("The array is not palindromic");
    }
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not palindromic

Input:
N = 6
arr = {0, 2, 4, 4, 2, 0}

Output:
The array is palindromic
*/
