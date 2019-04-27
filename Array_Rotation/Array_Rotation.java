//Program to rotate array Arr[] of size n by d Elements
class Array_Rotation
{
    private static void leftRotate(int arr[], int n) 
    { 
        int temp = arr[0], i; 
        // shifting all the elements of the array to left
        for (i = 0; i < n - 1; i++) 
            arr[i] = arr[i + 1]; 

        arr[i] = temp; 
    } 
    
    private static void Rotate(int arr[], int rotations, int n) 
    { 
        // call for rotation one by one
        for (int i = 0; i < rotations; i++) 
            leftRotate(arr, n); 

        // print the array
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " ");    
    } 

    public static void main(String args[]) 
    { 
        // Sample input
        int arr[] = {1, 2, 3, 4, 5}; 
        int n = arr.length; 
        Rotate(arr, 2, n);
    } 
}

/*
Input array: {1, 2, 3, 4, 5}
Sample Output
3 4 5 1 2 
*/
