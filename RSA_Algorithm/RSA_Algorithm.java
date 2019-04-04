import java.io.*;
import java.util.Scanner;
import java.lang.Math;

public class RSA_Algorithm
{
    // gcd function
    public static int egcd(int a, int b) 
    {
        int rem;
        while(b != 0) {
            rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    public static void main(String args[])
    {
    // m is message to be encrypted, 1 < m < n
    int m, p, q, phi, e, d, temp, n, c, message;
    
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter numeric text message : ");
    m = sc.nextInt();

    // p & q are two random prime numbers
    p = 5;
    q = 7;
    n = p * q;

    // eulers toitent function
    phi = (p - 1) * (q - 1);

    //(n,e) forms our public key, 1 < e < phi
    e = 2;
    while(e < phi) {
        if (egcd(e, phi) == 1.0)
            break;
        e ++;
    }
    // (n,d) forms our private key, 1 < d < phi
    d = 2;
    while (d < phi){
        temp = ((e * d) - 1) % phi;
        if (temp == 0)
            break;
        d ++;
    }

    // printing cipher text 
    c = (int)Math.pow(m, e) % n;
    System.out.println("Cipher = "+c);

    // printing original message
    message =(int)Math.pow(c, d) % n;
    System.out.println("Message = "+message);

    sc.close();
    }

}

/*
Input :
Enter numeric text message : 34

Output :
Cipher = 34
Message = 34
*/
