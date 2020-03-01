/*
 * Problem Statement
 * 	Program to find if a No. is a power of any Given No. in Java
 *	
 *Approach
 *	comparing the log's value with the floor value of log 
 */
import java.util.Scanner;

public class PowerOfAnyGivenNo {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);	//input
		System.out.print("Enter a no. : ");	
		int number = sc.nextInt();
		
		System.out.print("Check for which no. ? ");	//base element
		int base = sc.nextInt();
		
		if( isPowerOfGivenNo(number, base) )
			System.out.println("Yes "+number +" is a power of "+base);
		else
			System.out.println("No "+number +" is not a power of "+base);
		sc.close();
	}

	private static boolean isPowerOfGivenNo(int number, int base) {
		
		//explicitly check for 1 because log(1) = 0
		if(base == 1){
			if(number == 1)
				return true;
			else	
				return false;
		}
		//converting to positive	
		number = Math.abs(number);
		
		float logValue = (float) (Math.log(number)/Math.log(base));
		return logValue == Math.floor(logValue);
	}

}

/*
* Input :
Enter a no. : 14641
Check for which no. ? 11
 
* Output :
Yes 14641 is a power of 11
 * */
