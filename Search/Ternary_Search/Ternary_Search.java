class Ternary_Search
{
    // Function for binary search
    public static int TernarySearch(int array[], int left, int right, int desired)
    {
       if(right >= left)
       {
            int mid1 = left + (right - left) / 3;
            int mid2 = mid1 + (right - left) / 3;

            // If x is present at the mid1
            if(array[mid1] == desired)
                return mid1;

            // If x is present at the mid2
            if(array[mid2] == desired)
                return mid2;

            // If x is present in left one-third
            if(array[mid1] > desired)
                return TernarySearch(array, left, mid1 - 1, desired);

            // If x is present in right one-third
            if(array[mid2] < desired)
                return TernarySearch(array, mid2 + 1, right, desired);

            // If x is present in middle one-third
            return TernarySearch(array, mid1 + 1, mid2 - 1, desired);
       }

       // We reach here when element is not present in array
       return -1;
    }

    // Driver Function
    public static void main(String[] args)
    {
        int[] array = {1, 2, 3, 4, 5, 6, 7};

        // Element 4 to be searched
        if(TernarySearch(array, 0, 6, 4) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");

        //Element 9 to be searched
        if(TernarySearch(array, 0, 6, 9) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}

/* Output

Found
Not Found

*/
