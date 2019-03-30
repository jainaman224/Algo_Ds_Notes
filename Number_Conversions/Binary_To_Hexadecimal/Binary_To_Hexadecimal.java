//Java code to convert binary to hexadecimal
import java.util.Scanner;
class number 
{
    public static void main(String[] args) 
    {
        int[] hex = new int[1000];
        int i = 1, j = 0, rem, decimal_num = 0, binary_num;
        Scanner in = new Scanner(System.in);
        System.out.print("Input a Binary Number: ");
        binary_num = in.nextInt();
        //operation
        while (binary_num > 0) {
            rem = binary_num % 2;
            decimal_num = decimal_num + rem * i;
            i = i * 2;
            binary_num = binary_num / 10;
        }
        i = 0;

        while (decimal_num != 0) {
            hex[i] = decimal_num % 16;
            decimal_num = decimal_num / 16;
            i++;
        }

        for (j = i - 1; j >= 0; j--)
        {
            if (hex[j] > 9) 
            {
                System.out.print((char)(hex[j] + 55));
            } else
            {
                System.out.print(hex[j]);
            }
        }
    }
}

//Output
//IMPUT the binary number: 1101010
//6A
