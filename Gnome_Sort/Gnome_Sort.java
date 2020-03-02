import java.util.*;
class GnomeSort { 
    // A function which is used to sort the given list using Gnome sort 
    public static void gnome_sort(final int arr[], final int n) {
        int index = 0;

        // Checking the Condition
        while (index < n) {

            // Intially Index is set to Zero then It will be incremented to 1
            if (index == 0)
                index++;
            // Checking the values between the array elements
            if (arr[index] >= arr[index - 1])
                index++;
            else {
                int temp = 0;
                temp = arr[index];
                arr[index] = arr[index - 1];
                arr[index - 1] = temp;
                index--;
            }
        }
    }

    // Sample Input to test above function
    public static void main(String[] args) {
        final int arr[] = { 3, 2, 1, -5, 7 };
  
        gnome_sort(arr, arr.length); 
  
        System.out.println(Arrays.toString(arr)); 
    } 
} 

// Output:
// -5, 1, 2, 3, 7
  