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
    
    private static void rightRotate(int arr[], int n)
    {
        int temp=arr[n-1], i;
        //shifting all the elements of the array to right
        for(i=n-1;i>0;i--)
            arr[i]=arr[i-1];
        arr[0] = temp;
    }
    private static void RotateDriverLeft(int arr[], int rotations, int n) 
    { 
        // call for rotation one by one
        for (int i = 0; i < rotations; i++) 
            leftRotate(arr, n); 

        // print the array
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " ");    
    } 
    private static void RotateDriverRight(int arr[], int rotations, int n) 
    { 
        // call for rotation one by one
        for (int i = 0; i < rotations; i++) 
            rightRotate(arr, n); 

        // print the array
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " ");    
    } 

    public static void main(String args[]) 
    { 
        // Sample input
        int arr1[] = {1, 2, 3, 4, 5}; 
        int arr2[]={1,2,3,4,5};
        int n = arr1.length; 
        int m=arr2.length;
        RotateDriverLeft(arr1, 2, n);
        System.out.println();
        RotateDriverRight(arr2,2,m);
    } 
}
/*
Input array: {1, 2, 3, 4, 5}
Sample Output
3 4 5 1 2 
*/
