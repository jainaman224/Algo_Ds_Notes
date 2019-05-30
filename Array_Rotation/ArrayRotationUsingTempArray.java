import java.util.Arrays;
 
public class ArrayRotationUsingTempArray
{
    // function to left rotate the array by d elements 
    private static void rotate(int[] arr, int n, int d) 
    {
        // it brings down d to the minimum number of rotations we need to make in case d > n
         d = d % n; 
        
        // initialize temp array of size d
        int[] temp = new int[d];
        
        // copy the first d elements to temp array
        for (int i = 0; i < d; i++)
        {
            temp[i] = arr[i];
        }
        
        // left moves the rest of the elements in original array by d elements
        for (int i = 0; i < n-d; i++)
        {
            arr[i] = arr[i+d];
        }
        
        // assigns the remaining elements from temp array to original array
        for (int i = 0; i < d; i++)
        {
            arr[i+n-d] = temp[i];
        } 
    }
     
    public static void main(String[] args) 
    {
        int[] arr = new int[] {1, 2, 3, 4, 5, 6, 7};
        int d = 2;
        System.out.println("Initial Input Array");
        System.out.println(Arrays.toString(arr));
        rotate(arr, 7, d);
        System.out.println("Result after " + d + " left rotations");
        System.out.println(Arrays.toString(arr));
    }
}

/*  Sample Input - 
   [1,2,3,4,5,6,7]
 Sample Output - 
  [3,4,5,6,7,1,2]
*/
