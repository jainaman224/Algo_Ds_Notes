// Java Code for Comb Sort 
class CombSort 
{ 
    // function to update gap value
    int updateGap(int gap) 
    { 
        // Shrink gap by the shrink factor 
        gap = (gap*10)/13; 
        if (gap < 1) 
            return 1;
        return gap; 
    }

    // Function to sort arr[] using Comb Sort 
    void combSort(int arr[], int n) 
    { 
        // initialize gap value to array length
        int gap = n;
        boolean swapped = true; 
        while (gap != 1 || swapped == true) 
        { 
            // Update gap value
            gap = updateGap(gap); 
            swapped = false; 
            // Compare all elements with the obtained gap value
            for (int i=0; i< (n-gap); i++) 
            { 
                if (arr[i] > arr[i+gap]) 
                { 
                    // Swap arr[i] and arr[i+gap] 
                    int temp = arr[i]; 
                    arr[i] = arr[i+gap]; 
                    arr[i+gap] = temp; 
                    swapped = true; 
                } 
            } 
        } 
    } 

    // Driver function
    public static void main(String args[]) 
    { 
        CombSort obj = new CombSort(); 
        int arr[] = {3, -6, 20, 66, 25, -52, 0, 11, 42};
        int n=arr.length;
        // Call to combSort function
        obj.combSort(arr,n);
        // Printing sorted array
        System.out.println("Sorted array"); 
        for (int i=0; i<n; i++) 
            System.out.print(arr[i] + " ");
    } 
}
