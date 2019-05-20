import java.util.Scanner;
import java.util.*; 

class Frequency_Of_A_Element
{
    static int frequency(int input[], int n, int x) 
    {    
        // Frequency is how many times a number have occurred
        int f = 0;
        for (int i = 0; i < n; i++)
        {
            if (input[i] == x)
            {
                f = f + 1;
            }
        } 
        return f; 
    } 
    
    public static void main(String args[]) 
    {
        int n;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = s.nextInt();
        }

        // Number whose frequency has to be found
        int x = s.nextInt();
        
        int result = frequency(arr, n, x); 
        System.out.println(result);
    }
}

/*
INPUT:
n = 6
arr = {1, 2, 3, 3, 4, 3}
x (number whose occurence is to be found) = 3

OUTPUT:
3
*/
