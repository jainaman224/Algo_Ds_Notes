// This function is for when -> 
// 1.The input number is not palindrome. 
// 2.number is palindrome but not all digits as nine

class Next_Smallest_Palindrome 
{
    private static void helper(int num[], int n)
    {
        int middle = n/2, i = middle - 1;
        int j = 0;

        // handling middle for odd and even lengths
        if(n % 2 == 0)
        j = middle;
        else
        j = middle + 1;

        boolean isLeftSmaller = false;

        // ignore the middle same digits  
        while(i >= 0 && num[i] == num[j])
        {
            i--;
            j++;
        }

        if(i < 0 && num[i] < num[j])
        isLeftSmaller = true;

        while(i >= 0)
        {
            num[j] = num[i];
            i--;
            j++;
        }

        // the case where middle digit must be incremented.  
        if (isLeftSmaller) 
        { 
            int cflag = 1; 
            i = middle - 1; 
            if (n%2 == 1) 
            { 
                num[middle] += cflag; 
                cflag = num[middle] / 10; 
                num[middle] %= 10; 
                j = middle + 1; 
            } 
            else
                j = middle; 

            // copy same left to right
            while (i >= 0) 
            { 
                num[i] += cflag; 
                cflag = num[i] / 10; 
                num[i] %= 10; 
                num[j] = num[i]; 
                j++;
                i--;
            } 
        } 
    }

    private static void next_smallest_palindrome(int num[], int n)
    {
        // Check if all digits are 9's
        int b = 1;
        for(int i = 0; i < n; i++)
        {
            if(num[i] != 9)
            b = 0;
        }

        // if yes, o/p would be 1 followed by n-1 0's followed by 1. 
        if(b > 0)
        {
            System.out.print(1 + " ");

            for(int j = 0; j < n-1; j++)
            System.out.print(0 + " ");

            System.out.print(1 + " ");
        }
        else
        {
            helper(num, n);
            for(int i = 0; i < n; i++)
            System.out.print(num[i] + " ");
        }
    }

    public static void main(String args[])
    {
        // Sample input
        int num[] = {9, 4, 1, 8, 7, 9, 7}; 
        int n = num.length;
        next_smallest_palindrome(num, n); 
    }
}

// Sample Output
// 9 4 1 9 1 4 9 
