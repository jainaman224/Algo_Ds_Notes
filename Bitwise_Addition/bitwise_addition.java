import java.io.*;
class Bitwise
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        System.out.print("Enter two numbers: ");
        String s[] = bu.readLine().split(" ");
        int a = Integer.parseInt(s[0]), b = Integer.parseInt(s[1]);
        sb.append("\nusing bitwise operations,\n");
        sb.append("\n" + a + " + " + b + " = " + bitwise(a,b));
        System.out.print(sb);
    }

    static int bitwise(int a,int b)
    {
        while(b != 0)
        {
            int carry = a & b;  //common set bits of a and b
            a = a ^ b;  //sum of bits of a and b where at least one bit is unset
            b = carry << 1; //left shifting carry by 1 so that a can give the sum
        }
        return a;
    }
}

/*
INPUT:
    Enter two numbers: 12 30
OUTPUT:
    using bitwise operations,

	12+30 = 42
*/
