import java.util.Scanner;
import java.lang.Math;

public class practice1{

    public static void main (String[] args){

        //        int left[] = new int [];

        Scanner input = new Scanner(System.in);

        System.out.print("Enter numbers separated by spaces: ");
        String elements = input.nextLine();

        //break up numbers and put into array
        String arr[]= elements.split(" ");
        int intArr[] = new int[arr.length];
        for (int i = 0; i < intArr.length; ++i) {
            intArr[i] = Integer.parseInt(arr[i]);
            //            System.out.printf("%d\n", intArr[i]);
        }
        
        int size = intArr.length;
             
        //3-way partition
        int pivot = intArr[0];
        int i = 0;
        int j = 0; 
        int n = size - 1;
        int temp;
        System.out.print("Original Array: ");
        for ( int k = 0; k < size; k++) 
            System.out.printf("%d ", intArr[k]);
        System.out.printf("\nThe pivot is: %d\n", pivot);


        while(j <= n){
            if (intArr[j] < pivot){
                temp = intArr[i];
                intArr[i] = intArr[j];
                intArr[j] = temp;
                i+=1;
                j+=1;
            }
            else if (intArr[j] > pivot){
                temp = intArr[j];
                intArr[j] = intArr[n];
                intArr[n] = temp;
                n-=1;
            }
            else
                j+=1;

        }

        System.out.print("Sorted Array: ");
        for ( int k = 0; k < size; k++)
            System.out.printf("%d ", intArr[k]);
        System.out.printf("\n");
    }
}
