import java.io.*; 
import java.util.Scanner;

public class Binary_To_Octal 
{
    public static void binToOctal(long num)
    {  
         int n = 0, decimal = 0;
	  //converting binary to decimal
	  while(num > 0)
	  {
	       long temp = num % 10;  
	       decimal += temp * Math.pow(2, n);  
	       num = num / 10;  
	       n++;  
	  }
	  int octal[] = new int[20];
	  int i = 0;
	  while(decimal > 0)
	  {
              int t = decimal % 8;
	      octal[i++] = t;
       	      decimal = decimal / 8;
	  }
	  System.out.print("Octal representation");
	  for(int j = i-1 ; j >= 0 ; j--)
	      System.out.print(octal[j]); 
      } 
      public static void main(String[] args)
      {
          long num;
          Scanner sc = new Scanner(System.in);
          System.out.println("Enter a Binary number");
          num = sc.nextLong();
          binToOctal(num);  
          sc.close();
      }
}
/*
Input:
Enter a Binary number
1011001010
Output:
Octal representation
2625
*/
