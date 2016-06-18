class Linear_Search
{
    // Function for linear search
    public static int LinearSearch(int[] array, int size, int desired)
    {
        for(int i = 0; i < size; i++)
        {
            // return position if element is found
            if(array[i] == desired)
                return i;
        }

        return -1;
    }

    // Driver Function
    public static void main(String[] args)
    {
        int[] array = {2, 4, 6, 7, 3, 1, 5};

        // Element 4 to be searched
        if(LinearSearch(array, 7, 4) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");

        //Element 9 to be searched
        if(LinearSearch(array, 7, 9) != -1)
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}

// Output
// Found
// Not Found
