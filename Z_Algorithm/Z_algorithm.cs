// A C# program that implements Z algorithm for pattern searching

using System; 

class Z_algorithm
{ 
// prints all occurrences of  pattern in text using Z algo 
public static void search(string text,string pattern) 
{  
	string concat = pattern + "$" + text; 

	int l = concat.Length; 
	int[] Z = new int[l];  
	getZarr(concat, Z); 

	//search for matching expression
	for (int i = 0; i < l; ++i) 
	{  
		if (Z[i] == pattern.Length) 
		{ 
			Console.WriteLine("Pattern found at index " + 
							(i - pattern.Length - 1)); 
		} 
	} 
} 

private static void getZarr(string str, int[] Z) 
{ 

	int n = str.Length;
	int L = 0, R = 0; 

	for (int i = 1; i < n; ++i) 
	{  
		if (i > R) 
		{ 
			L = R = i;
			while (R < n && str[R - L] == str[R]) 
			{ 
				R++; 
			} 

			Z[i] = R - L; 
			R--; 

		} 
		else
		{ 
			int k = i -L
			if (Z[k] < R - i + 1) 
			{ 
				Z[i] = Z[k]; 
			} 
			else
			{  
				L = i; 
				while (R < n && str[R - L] == str[R]) 
				{ 
					R++; 
				} 

				Z[i] = R - L; 
				R--; 
			} 
		} 
	} 
} 

public static void Main(string[] args) 
{ 
	string text = "For sandwiches, we have cheese and ham, cheese and pickle, Ham and mustard, and what claims to be pate de fois gras , Marmite and mango chutney?!"; 
	string pattern = "and"; 

	search(text, pattern); 
}
}
