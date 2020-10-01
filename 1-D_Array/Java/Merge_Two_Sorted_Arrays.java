    
import java.util.Scanner;
import java.util.*; 

class Merge_Two_Sorted_Arrays
{
    static void merge(int a[], int num1, int b[], int num2)
    {
        int c[] = new int[num1 + num2];
        int k = 0;
        int j = 0;
        int i = 0;

        // Traverse both array 
        while (i < num1 && j < num2) 
        { 
            if (a[i] > b[j]) 
                c[k++] = b[j++]; 
            else
                c[k++] = a[i++]; 
        } 

        // copying remaining elements of array a 
        while (i < num1) 
            c[k++] = a[i++]; 

        // copying remaining elements of array b
        while (j < num2) 
            c[k++] = b[j++]; 

        System.out.println("New merged array: \n");
        for (i = 0; i < (num1 + num2); i++)	
        {
            System.out.println(c[i] + " ");
        }
    }
    
    public static void main(String args[]) 
    {
        int num1;
        Scanner s = new Scanner(System.in);
        num1 = s.nextInt();
        int arr1[] = new int[num1];
        for (int i = 0; i < num1; i++)
        {
            arr1[i] = s.nextInt();
        }
        
        int num2;
        num2 = s.nextInt();
        int arr2[] = new int[num2];
        for (int i = 0; i < num2; i++)
        {
            arr2[i] = s.nextInt();
        }

        merge(arr1, num1, arr2 , num2);       
    }
}

/*
Input:
num1 = 3
arr1 = {1, 3, 4}
num2 = 3
arr2 = {2, 5, 6}

Output:
New merged array:
1 2 3 4 5 6
*/
