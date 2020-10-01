import java.util.Scanner;
import java.util.*; 

class Max_And_Next_Max_Number
{
    static void maxAndNextMax(int arr[], int n) 
    {
        // max is for maximum number and 
        // smax for next(second) maximum number
        int max, smax;

        // Assigning max and smax with arr[0] and arr[1] depending
        // on the condition max > smax
        if (arr[0] > arr[1])
        {
            max = arr[0];
            smax = arr[1];
        }
        else 
        {
            max = arr[1];
            smax = arr[0];
        }

        // Comparing rest of the element in the array
        for (int i = 2; i < n; i++)
        {
            if (arr[i] > smax)
            {
                if (arr[i] > max)
                {
                    smax = max;				
                    max = arr[i];
                }
                else
                {
                    smax = arr[i];
                }
            }
        }
        System.out.println("Max: " + max);
        System.out.println("Next max: " + smax);
    } 
    
    public static void main(String args[]) 
    {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = s.nextInt();
        }

        maxAndNextMax(arr, n);
    }
}

/*
Input:
n = 5
array = {1, 2, 3, 4, 5}

Output:
Max: 5
Next max: 4
*/
