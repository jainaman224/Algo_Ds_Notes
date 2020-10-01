using System; 
public class Next_Smallest_Palindrome { 
      
    // This function is for when -> 
    // 1.The input number is not palindrome. 
    // 2.number is palindrome but not all digits as nine

    static void helper(int []number, int n)  
    { 
        int mid = n / 2, i = mid - 1; 
         
        // handling middle for odd and even lengths
        if(n % 2 == 0) 
        j = mid;
        else mid + 1; 
  
        // ignore the middle same digits 
        while (i >= 0 && number[i] == number[j])  
        { 
            i--; 
            j++; 
        } 
          
        bool isLeftSmaller = false;     
        if (i < 0 || number[i] < number[j])  
        { 
            isLeftSmaller = true; 
        } 
          
        // Copy the mirror of left to tight 
        while (i >= 0)  
        { 
            number[j] = number[i]; 
            j++;
            i--;
        } 
          
        // the case where middle digit must be incremented. 
        if (isLeftSmaller)  
        { 
            int cflag = 1; 
           
            if (n % 2 == 1) { 
                number[mid] += 1; 
                cflag = number[mid] / 10; 
                number[mid] %= 10; 
            } 
            i = mid - 1; 

            if(n % 2 == 0) 
            j = mid;
            else mid + 1; 

            // copy left to right   
            while (i >= 0)  
            { 
                number[i] = number[i] + cflag; 
                cflag = number[i] / 10; 
                number[i] %= 10; 
                number[j] = number[i];
                i--; 
                j++; 
            } 
  
        } 
    } 
  
    static void next_smallest_palindrome(int []num, int n)  
    { 
        bool b = true;
        for (int i = 0; i < n; i++) 
            if (num[i] != 9) 
                b = false

        // simply o/p 1 followed by n-1 0's followed by 1. 
        if (b) { 
            Console.Write("1"); 
            for (int i = 0; i < n - 1; i++) 
                Console.Write("0"); 
            Console.Write("1"); 
        } 
      
        // Input type 2 and 3 
        else { 
            helper(num, n); 

            for (int i = 0; i < num.Length; i++) 
                Console.Write(num[i]+ " "); 

            Console.Write(" "); 
        } 
    } 
   
    public static void Main()  
    { 
        // Sample Input
        int []num = {9, 4, 1, 8, 7, 9, 7}; 
        next_smallest_palindrome(num, num.Length); 
    } 
} 

// Sample Output
// 9 4 1 9 1 4 9 
  