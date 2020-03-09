import java.util.Scanner;
import java.util.*; 
import java.lang.Math;

public class Mean_Variance_Standard_Deviation
{
    static void meanVarianceStandardeviation(int arr[], int num) 
    {    
        float mean, v, sd;
        mean = 0;
        int i;

        for (i = 0; i < num; i++)
        {
            // Calculating sum of the array
            mean = mean + arr[i];
        }

        //  mean is the average of the numbers
        mean = mean / num;

        float sum = 0;

        for (i = 0; i < num; i++)
        {
            sum = sum + (float)(Math.pow(arr[i] - mean, 2));
        }

        // Variance is the average of the squared differences from the Mean
        v = sum / num;

        // Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
        sd = (float)Math.pow(v, 1/2);

        System.out.println("Mean = " + mean);
        System.out.println("Variance = " + v);
        System.out.println("Standard Deviation = " + sd);
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

        meanVarianceStandardeviation(arr, n);
    }
}

/*
Input:
n = 5
arr = {1, 2, 3, 4, 5}
Output:
Mean = 3.0
Variance = 2.0
Standard Deviation = 1.0
*/
