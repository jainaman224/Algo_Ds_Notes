/**
 * Decimal To Binary Conversion
 */
package algo_ds;

import java.util.Scanner;
public class DecimalToBinary 
{
    static void Decimal_to_binary(int decimal)
    {   
         int i = 0;
	 int binary[]=new int[100];
	  while(decimal > 0)
	  {
	       binary[i]=decimal % 2;
	       decimal=decimal / 2;
	       i++;
	  }
	  System.out.println("binary representation");
	  for(int j = i; j <= i; j--)
	      System.out.print(binary[j]);
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
	System.out.println("Enter a decimal number");
	int decimal=sc.nextInt();
	Decimal_to_binary(decimal);
    }
}

/*INPUT:4
OUTPUT:100
*/
