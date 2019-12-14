import java.util.Scanner;

public class GCD {
    public static void main(String args[])
    {
        long x,y;

        //Reading the inputs
        Scanner sc=new Scanner(System.in);
        System.out.println("enter  number 1");
        x=sc.nextLong();
        System.out.println("enter  number 2");
        y=sc.nextLong();

        if(x>0 && y>0)
        {
            while(x!=y)
            {
                if(x>y)
                    x=x-y;
                else
                    y=y-x;

            }

            //Display the result
            System.out.println("Gcd of two numbers is: "+x);
        }
        else
            System.out.println("Please enter numbers greater than zero");
    }

}
