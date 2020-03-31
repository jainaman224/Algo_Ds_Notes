/*simpson's 1/3 rule in C#
Used for numerical approximation of definite integrals
*/

using System; 

public class simpsonRule 
{ 

	// Function to calculate f(x) 
	static float func(float x) 
	{ 
		return (float)Math.Log(x); 
	} 

	// Function for approximate integral 
	static float simpsons_(float ll, float ul, 
										int n) 
	{ 
		float h = (ul - ll) / n; 
		float[] x = new float[10]; 
		float[] fx = new float[10]; 

		// Calculatiion of x and f(x) 
		for (int i = 0; i <= n; i++) 
		{ 
			x[i] = ll + i * h; 
			fx[i] = func(x[i]); 
		} 

		// Result Calculation
		float res = 0; 
		for (int i = 0; i <= n; i++) 
		{ 
			if (i == 0 || i == n) 
				res += fx[i]; 
			else if (i % 2 != 0) 
				res += 4 * fx[i]; 
			else
				res += 2 * fx[i]; 
		} 
		
		res = res * (h / 3); 
		return res; 
	} 

	// MAIN FUNCTION 
	public static void Main() 
	{  
        string val;
        int n;
        float lower_limit, upper_limit;

        Console.WriteLine("Input lower limit, upper limit and internal : ");
        lower_limit = float.Parse(Console.ReadLine());
        upper_limit = float.Parse(Console.ReadLine());
        
        val = Console.ReadLine();
        n = Convert.ToInt32(val);
	Console.WriteLine("Result : ");                             
	Console.WriteLine(simpsons_(lower_limit, upper_limit, n));
	Console.WriteLine("Result : ");                                
	} 
}

/*
OUTPUT
Inout lower limit, upper limit and interval : 2
9
6
Result : 11.38688
*/	
		
							
        
