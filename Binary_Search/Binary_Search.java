import java.util.Scanner;

class Binary_Search
{
    // Function for binary search
    public static int binarySearch(int[] array, int size, int desired)
    {
        int left = 0, right = size - 1, middle;

        while (left <= right)//Condition to check
        {
            middle = left + (right - left) / 2;//Finding Middle element

            if (array[middle] == desired)//Checking Condition
                return middle;
            else if (desired < array[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        return -1;
    }

    // Driver Function
    public static void main(String[] args)//Main function
    {
        int num;
        Scanner s = new Scanner(System.in);//Scanner class in java
        num = s.nextInt();//Integer Input from keyboard through Scanner class in Java
        int array[] = new int[num];//Initializing array
        for (int i = 0; i < num; i++) {//Loop till number of elements
            array[i] = s.nextInt();//Integer Input from keyboard through Scanner class in Java
        }
        int desired;
        desired = s.nextInt();//Integer Input from keyboard through Scanner class in Java
        if (binarySearch(array, num, desired) != -1)//Condition check using function
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
