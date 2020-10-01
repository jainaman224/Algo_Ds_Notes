
import java.util.*;
import java.lang.*;
import java.io.*;


class Euclid
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int	a = 30;
		int	b = 105;
		int	c = EuclidGCD(a,b);
		System.out.println(c);
		// prints 15
		// GCD of 30 and 105 is 15
	}
	
	public static int EuclidGCD(int a, int b)
	{
		if(b == 0)
			return a;
		else
			return EuclidGCD(b,a%b);
	}
}
