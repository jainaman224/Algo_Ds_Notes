/*
    Compound Interest = P(1 + R/100)^T
    
    P is principle amount
    R is the rate and
    T is the time span
*/

import java.util.Scanner;
import  java.lang.Math;

public class Compound_Interest {

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        double p, r, t;
        System.out.print("Enter Principal: ");
        p = s.nextDouble();
        System.out.print("Enter Rate: ");
        r = s.nextDouble();
        System.out.print("Enter Time: ");
        t = s.nextDouble();
        System.out.print(p * (Math.pow((1 + r / 100), t)));
    }
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : 1166.40
*/
