//java program to find the greatest comman divisor of 2 numbers
import java.util.Scanner;

public class GCD{
	//recursive method which returns the gcd of two numbers m and n 
	public static int gcd(int m,int n){
		//assuming m is greater than n 
		if(n>m){
			//if n is greater than m, then swap
			int temp=m;
			m=n;
			n=temp;
		}
		//if divisible, then n is the gcd 
		if(m%n==0)
			return n;
		//else, call the gcd for n and the remainder
		else
			return(gcd(n,m%n));
	}
	
	public static void main(String args[]){
		//define Scanner object toread the input
		Scanner sc=new Scanner(System.in);
		
		//read the numbers 
		System.out.print("Enter Number 1 ");
		int num1=sc.nextInt();
		System.out.print("Enter Number 2 ");
		int num2=sc.nextInt();
		
		//call the function and display the results
		System.out.println("Gcd of "+num1+", "+num2+" = "+gcd(num1, num2));
	}
}


/*
* Output
* Enter number 1 14
* Enter number 2 63
* Gcd of 14, 63 = 7
*/
