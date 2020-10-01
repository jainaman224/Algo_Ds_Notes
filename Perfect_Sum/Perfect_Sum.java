/*
Perfect Sum problem:
Given an array of elements and a sum, print all subsets
which adds upto the given sum.
Example: arr = [1, 7, 3, 5, 6] and sum = 8, the solutions possible 
are [1, 7], [3, 5].
*/

import java.util.Scanner;

class Perfect_Sum 
{
    public static int flag = 0;

    public static void isSubsetSum(int arr[], int subset[], int N, int subsetSize,
                                int subsetSum, int index ,int sum) 
    {
        if (subsetSum == sum) 
        {
            flag = 1;
            for (int i = 0; i < subsetSize; i++)
                System.out.print(subset[i] + "  ");
            System.out.println("");
        }
        else 
        {
            for (int i = index; i < N; i++) 
            { 
                subset[subsetSize] = arr[i];
                isSubsetSum(arr, subset, N, subsetSize + 1, 
                            subsetSum + arr[i], i + 1, sum);
            }
        }
    }

    public static void main(String args[])
    { 
        System.out.println("Enter size of array");
        int N;
        Scanner s = new Scanner(System.in);
        N = s.nextInt();
        System.out.println("Enter elements of array");
        int arr[] = new int[N];
        for (int i = 0; i < N; i++)
            arr[i] = s.nextInt();
        System.out.println("Enter sum");
        int sum;
        sum = s.nextInt();
        int subset[] = new int[N];
        isSubsetSum(arr, subset, N, 0, 0, 0, sum);
        if (flag == 0) {
            System.out.print("No such subset present");
        }
    }
}

/*
INPUT:
N = 5
arr = [1 2 3 4 5]
sum = 7

OUTPUT:
1  2  4
2  5
3  4
*/
