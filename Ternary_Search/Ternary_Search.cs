using System;

public class ternarysrc {

    // Function to perform Ternary Search
    static int ternarySearch(int l, int r, int key, int[] ar)
    {
        while (r >= l)
        {

            // Finding the mid1 and mid2
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            // To check if key is present at any mid
            if (ar[mid1] == key)
            {
                return mid1;
            }
            if (ar[mid2] == key)
            {
                return mid2;
            }

            // Checking region where KEY might be present
            if (key < ar[mid1])
            {
                r = mid1 - 1;
            }
            else if (key > ar[mid2])
            {
                l = mid2 + 1;
            }
            else
            {
                l = mid1 + 1;
                r = mid2 - 1;
            }
        }

        // If the KEY is not found
        return -1;
    }

    // Main Function to Execute
    public static void Main(String[] args)
    {
        int l, r, p, i, key = 0, len = 0;

        // Taking the input of Array Length from user
        Console.WriteLine("Enter Length of Array : ");
        len = Convert.ToInt32(Console.ReadLine());

        int[] ar = new int[len];

        Console.WriteLine("Enter Array Elements in Ascending Order : ");

        for(i = 0; i < len; i++ )       // Array input
        {
            ar[i] = Convert.ToInt32(Console.ReadLine());
        }

        // Starting index
        l = 0;

        // Ending Index
        r = len - 1;

        Console.WriteLine("\nEnter the Number to be Searched : ");
        // KEY to be searched in the array
        key = Convert.ToInt32(Console.ReadLine());

        // Searching the KEY using ternarySearch function
        p = ternarySearch(l, r, key, ar);


        // Checking if the KEY is present or not
        if(p == -1)
            Console.WriteLine("\nNumber Not Found");
        else
            Console.WriteLine("\n The Index of " + key + " is " + p);
        Console.ReadKey();


    }
}

// Sample Input/Output:
/*
    Enter Length of Array : 5
    Enter Array Elements in Ascending Order : 
    10
    20
    30
    40
    50

    Enter the Number to be Searched : 
    50

    The Index of 50 is 4

*/
