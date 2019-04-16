class Binary_Search
{
    // Function for binary search
    public static int BinarySearch(int[] array, int size, int desired)
    {
        int left = 0, right = size - 1, middle;

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
        int[] array = {1, 2, 3, 4, 5, 6, 7};

        // Element 4 to be searched
        if (BinarySearch(array, 7, 4) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");

        //Element 9 to be searched
        if (BinarySearch(array, 7, 9) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}

/* Output

Found
Not Found

*/
