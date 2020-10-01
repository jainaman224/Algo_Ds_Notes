/*
SIMPLE INTEREST

Simple Interest in Accounting is calculated as :

S.I. = (p * r * t) / 100
where p = principal amount
      r = rate of interest
      t = time
*/

import java.util.Scanner;

class Simple_Interest {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        float p, r, t;
        System.out.print("Enter Principal: ");
        p = s.nextInt();
        System.out.print("Enter Rate: ");
        r = s.nextInt();
        System.out.print("Enter Time: ");
        t = s.nextInt();
        System.out.print("Simple Interest is: " + ((p * r * t) / 100));
    }
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : Simple Interest is: 160.00
*/
