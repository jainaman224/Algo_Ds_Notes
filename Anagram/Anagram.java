/*
    Anagrams are strings formed by rearranging the
    letters of another string.
    Example: LISTEN and SILENT, as they have the same
    characters just appearing in another order.
*/

import java.util.*;

class Anagrams
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1st string");
        String str1 = sc.nextLine();

        System.out.println("Enter 2nd string");
        String str2 = sc.nextLine();

       
        // if lengths are not equal, they cannot be anagrams
        if (str1.length() != str2.length())
        {
            System.out.println("The strings are not anagrams");
            return;
        }
        
        // convert the strings into respective Arrays
        
        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();
        
        // sort the respective arrays 
        
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        
        // now convert the arrays back into strings and compare them 
        // if the equalsIgnoreCase() method returns true they are anagrams
        // if the equalsIgnoreCase() method returns false they are not anagrams
        
        String str_temp1 = new String(arr1);
        String str_temp2 = new String(arr2);
        
        if(str_temp1.equalsIgnoreCase(str_temp2)==true)
            System.out.println("The strings are anagrams");
        else
            System.out.println("The strings are not anagrams");
    }
}


/*
Input:
car
arc

Output:
The strings are anagrams

Input:
Listen
Silent

Output:
The strings are not anagrams
*/
