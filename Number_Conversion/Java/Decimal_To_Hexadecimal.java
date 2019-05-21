import java.io.*; 
import java.util.Scanner;
  
class Decimal_To_Hexadecimal
{ 
    static void decToHexa(int num) 
    {   
        char[] hexa= new char[100]; 

        int i = 0; 
        while (num != 0)
        {            
            int temp  = 0; 

            temp = num % 16; 

            // Checking if temp < 10; if it then it is a letter
            if(temp < 10) 
            { 
                hexa[i] = (char)(temp + 48); 
                i++; 
            } 
            else
            { 
                hexa[i] = (char)(temp + 55); 
                i++; 
            } 

            num = num / 16; 
        }    

        for(int j = i - 1; j >= 0; j--) 
            System.out.print(hexa[j]); 
    } 

    // driver program 
    public static void main (String[] args)  
    { 
        int num;
        Scanner sc = new Scanner(System.in);
        num = sc.nextInt(); 
        decToHexa(num); 
    } 
} 

/*
Input:
1234
Output:
4D2
*/
