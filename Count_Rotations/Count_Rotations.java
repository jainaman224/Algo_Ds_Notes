/**
 *   A sorted array has been rotated in clockwise direction.   
 *   Find how many times it was rotated.
 */

import java.util.Scanner;

class CountRotations
{
    static int findRotations(int[] arr)
    {    
        /**
         * returns no. of times a sorted array was rotated.
         */
        int size = arr.length;
        int left = 0, right = size - 1;

        while(left <= right)
        {
            int middle = (right + left) / 2;
            int previous = (middle + size - 1) % size, next = (middle + 1) % size;
            
            // next is index of element after middle
            // previous is index of element before middle
            
            if(arr[left] <= arr[right])
                return left;
            
            if(arr[middle] <= arr[next] && arr[middle] <= arr[previous])
                return middle;
            
            if(arr[middle] <= arr[right])
                right = middle - 1;
            
            else if(arr[middle] >= arr[left])
                left = middle + 1;
        }
        return 0;
    }
    
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter size of the array: ");
        int size = scan.nextInt();

        int[] arr = new int[size];

        System.out.println("Enter " + size + " elements: ");
        for(int i = 0; i < size; i++)
            arr[i] = scan.nextInt();

        int count = findRotations(arr);
        // count variable stores no. of rotations in the array.    
        
        System.out.println("The array is rotated " + count + " times.");
    }
}

/**
 *    Sample Input
 *    size = 6
 *    arr = 5, 6, 1, 2, 3, 4
 */
    
/**
 *    Sample Output
 *    The array is rotated 2 times.
 */
