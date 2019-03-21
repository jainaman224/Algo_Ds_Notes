import java.lang.Math;

// Java Code for Comb Sort 
class CombSort
{ 
    // Function to swap elements at index a and b
    void swap(int arr[], int a, int b)
    {
        int temp = arr[a]; 
        arr[a] = arr[b]; 
        arr[b] = temp; 
    }

    // Function to sort arr[] using Comb Sort 
    void combSort(int arr[], int n) 
    { 
        // initialize gap value to array length
        int gap = n;
        int flag= 1;
        while (gap > 1 || flag == 1 ) 
        { 
            // Update gap value by using shrink factor 1.3
            gap = (gap*10) / 13;
            // if gap is less than 1, set gap to 1
            gap = Math.max(1, gap);
            flag = 0;
            // Compare all elements with the obtained gap value
            for (int i=0; i< (n-gap); i++) 
            { 
                // Swap arr[i] and arr[i+gap] is arr[i] is greater
                if (arr[i] > arr[i+gap]) 
                {
                    swap(arr, i, i+gap);
                    flag = 1; 
                } 
            } 
        }
    } 

    // Driver function
    public static void main(String args[]) 
    { 
        CombSort obj = new CombSort(); 
        int arr[] = {-10, 50, 20, 0, 15, -25, 30};
        int n=arr.length;
        // Call to combSort function
        obj.combSort(arr, n);
        // Printing sorted array
        System.out.println("Array after sorting:"); 
        for (int i=0; i<n; i++) 
            System.out.print(arr[i] + " ");
    } 
}

/* Output
Array after sorting:
-25 -10 0 15 20 30 50
*/
