/*
    Quick Select Algorithm is used for extracting the kth smallest
    or kth largest element from the array without actually sorting
    the array. It uses the priciple of Quick Sort Algorithm, where
    we partition the array and select a pivot. The elements lesser
    than the pivot lie to its left, and the elements greater than 
    the pivot lie to its right. We can observe that in such scenario
    the pivot element is actually in its correct place and hence is
    the kth smallest element. The best and average time complexity of
    Quick Select is O(n). The worst case complexity is O(n^2).
*/

class Quick_Select
{
    // Function to swap elements
    public static void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Function to partition the array
    public static int partition( int arr[], int left, int right, int pivotIndex ) 
    {  
        // Select pivot element from the pivot index
        int pivotElement = arr[pivotIndex];

        // Move pivot to the right
        swap(arr, pivotIndex, right);

        // Start moving from left of the array
        int pIndex = left;
    
        /*
            Whenever we find an element lesser than the pivot,
            move it towards the left of the array, this way the
            elements greater than the pivot accumulate towards 
            the right of the array, and finally we will swap the
            pIndex and pivot, so that the pivot lies at its
            correct sorted place.
        */ 
        for (int i = left; i < right; i++) 
        {
            if (arr[i] <= pivotElement) 
            {
                swap(arr, i, pIndex);
                pIndex++;
            }
        }

        // Move pivot to its correct place
        swap(arr, pIndex, right);

        // return index of pivot
        return pIndex;
    }

    // Function to return the kth smallest element
    public static int quickSelect(int arr[], int left, int right, int k) 
    {
        // If there is only element in the array,
        // that is the answer
        if (left == right)
            return arr[left];

        // select a pivot which we have selected as
        // the rightmost elemnt everytime
        int pivot = right;

        // Call to the partition function following divide approach
        pivot = partition(arr, left, right, pivot);

        /* 
            if k equals the pivot, that element is our answer.
            Whenever we arrange elements such that elements lesser
            than pivot lie to the left of the pivot and elements
            greater than the pivot, lie to the right of the pivot,
            the pivot index is actually in its right place as it
            would have been in the sorted array.
        */
        if (k == pivot)
             return arr[k];

        // if k is lesser than the pivot, move right to pivot - 1,
        // as the element cannot lie towards the right of pivot
        else if (k < pivot)
            return quickSelect(arr, left, pivot - 1, k);

        // if k is greater than the pivot, move left to pivot + 1,
        // as the element cannot lie towards the left of pivot
        else
            return quickSelect(arr, pivot + 1, right + 1, k);
    }

    // Driver function
    public static void main(String args[]) 
    {
        // Initialise the array
        int arr[] = {2, 7, 6, 1, 8, 10, 12};
        int n = arr.length;

        // Set the value of k to the element we want
        // to extract
        int k = 3;

        // Call to quickSelect Function
        System.out.print("kth smallest element is: ");
        Quick_Select obj = new Quick_Select();
        System.out.println(obj.quickSelect(arr, 0, n - 1, k - 1));
    }
}

/*
    Input:
    [ 2, 7, 6, 1, 8, 10, 12 ]

    Output:
    kth smallest element is: 6
*/
