/*
A majority element in an array arr of size n is an
element that appears more than n/2 times.
Example: 
N = 9, arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}
Majority Element = 2 as count[2] = 5 which is greater
than n/2 i.e 4
*/

import java.util.Scanner;
import java.util.Map; 
import java.util.HashMap; 

class Majority_Element
{
    public static int checkMajorityElement(int arr[], int N)
    {
        Map<Integer, Integer> mp = new HashMap<Integer, Integer>();
        // Computing frequency of each element using Map
        for (int i = 0; i < N; i++) 
        { 
            if (mp.containsKey(arr[i]))
                mp.put(arr[i], mp.get(arr[i]) + 1); 
            else 
                mp.put(arr[i], 1); 
        } 
        for (Map.Entry<Integer, Integer> entry : mp.entrySet())
        {
            if (entry.getValue() > (N / 2))
            return entry.getKey();
        }
        return -1;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size of array:");
        int N = sc.nextInt();
        int arr[] = new int[N];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < N; i++)
            arr[i] = sc.nextInt();
        int ans = checkMajorityElement(arr, N);
        if (ans != -1)
            System.out.println("Majority Element is: " + ans);
        else
            System.out.println("No majority element in array");
    }
}

/*
Input:
N = 9
arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}

Output:
Majority Element is: 2

Input:
N = 5
arr = {1, 2, 3, 4, 5}

Output:
No majority element in array
*/
