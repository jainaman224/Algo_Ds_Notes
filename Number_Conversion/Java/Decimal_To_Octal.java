import java.io.*; 
import java.util.Scanner;

class Decimal_To_Octal
{ 
    static void decToOctal(int num) 
    {         
        int[] octal = new int[20]; 
  
        int i = 0; 
        while (num != 0)  
        { 
            octal[i] = num % 8; 
            num = num / 8; 
            i++; 
        }   
         
        for (int j = i - 1; j >= 0; j--) 
            System.out.print(octal[j]); 
    }      
     
    public static void main (String[] args)  
    { 
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt();
        decToOctal(num);  
    } 
} 

/*
Input:
20
Output:
24
*/
