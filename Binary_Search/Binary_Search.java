import java.util.Scanner;

class Binary_Search
{
    // Function for binary search
    public static int binarySearch(int[] array, int size, int desired)
    {
        int left = 0, right = size - 1, middle;
        // While loop for Searching Middle
        while (left <= right)
        {
            middle = left + (right - left) / 2;

            if (array[middle] == desired)
                return middle;
            else if (desired < array[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        return -1;
    }

    // Driver Function
    public static void main(String[] args)
    {
        int num;
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        int array[] = new int[num];
        for (int i = 0; i < num; i++) {
            array[i] = s.nextInt();
        }
        int desired;
        desired = s.nextInt();
        if (binarySearch(array, num, desired) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}

/* 
Input:
num = 7
array = {1, 2, 3, 4, 5, 6, 7}
desired = 4

Output:
Found

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
Not Found
*/
