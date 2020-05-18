/*
    Z Algorithm In C#

    This algorithm finds all occurrences 
    of a pattern in a text in linear time.
*/

using System; 

class PatternSearch
{ 

    /*
        This function prints all the occurences 
        of a pattern in a text using Z algorithm
    */

    public static void search(string text, string pattern) 
    {
        // Creation of Concatenated String
        string concat = pattern + "$" + text; 
        int l = concat.Length; 

        // Construct a new temporary array
        int[] temp = new int[l]; 

        getTempArr(concat, temp); 

        /* 
            Iterate through temp array to 
            find the matching condition
        */

        for (int i = 0; i < l; ++i) 
        {
            /*
                If matched region is equal to 
                pattern lentgh, pattern is found 
            */

            if (temp[i] == pattern.Length) 
            {
                Console.WriteLine("Pattern occurs at index: " + 
                            (i - pattern.Length - 1)); 
            } 
        } 
    } 

    // Fills temporary array for given string str 
    private static void getTempArr(string str, int[] temp) 
    { 
        int n = str.Length; 
        int L = 0, R = 0; 

        for (int i = 1; i < n; ++i) 
        { 
            if (i > R) 
            { 
                L = R = i; 

                while (R < n && str[R - L] == str[R]) 
                { 
                    R++; 
                } 
                temp[i] = R - L; 
                R--; 
            } 

            else
            { 
                int k = i - L; 

                if (temp[k] < R - i + 1) 
                { 
                    temp[i] = temp[k]; 
                } 

                else
                { 
                    L = i; 

                    while (R < n && str[R - L] == str[R]) 
                    { 
                        R++; 
                    } 
                    temp[i] = R - L; 
                    R--; 
                } 
            } 
        }
    } 

    public static void Main(string[] args) 
    {
        Console.WriteLine("Enter the String value: ");
        String text = Console.ReadLine();

        Console.WriteLine("Enter the Pattern to search: ");
        String pattern = Console.ReadLine();
        Console.WriteLine();

        search(text, pattern); 
    } 
} 

/**

Enter the String value: AABACAADAAABACHGGH 
Enter the Pattern to search: AABA

Pattern occurs at index: 0 
Pattern occurs at index: 9 

---------------------------------------------------

Enter the String value: THIS IS A TEST CASE 
Enter the Pattern to search: TEST 

Pattern occurs at index: 10 

*/
