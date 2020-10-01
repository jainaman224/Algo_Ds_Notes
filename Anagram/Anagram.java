/*
    Anagrams are strings formed by rearranging the
    letters of another string.
    Example: LISTEN and SILENT, as they have the same
    characters just appearing in another order.
*/

import java.util.Scanner;

class Anagram
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 1st string");
        String str1 = sc.nextLine();

        System.out.println("Enter 2nd string");
        String str2 = sc.nextLine();

        int count1[] = new int[256];
        int count2[] = new int[256];

        // if lengths are not equal, they cannot be anagrams
        if (str1.length() != str2.length())
        {
            System.out.println("The strings are not anagrams");
            return;
        }
    
        // Store the count of every character in string
        for (int i = 0; i < str1.length(); i++)
        {
            count1[str1.charAt(i) - 'a']++;
            count2[str2.charAt(i) - 'a']++;
        }
    
        // If the counts of characters are not equal,
        // they are not anagrams
        for (int i = 0; i < 256; i++)
        {
            if (count1[i] != count2[i])
            {
                System.out.println("The strings are not anagrams");
                return;
            }
        }
        System.out.println("The strings are anagrams");
    }
}

/*
Input:
car
arc

Output:
The strings are anagrams

Input:
cap
tap

Output:
The strings are not anagrams
*/
