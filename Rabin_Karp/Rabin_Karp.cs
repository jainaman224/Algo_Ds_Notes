// Following program is a C# implementation 
// of Rabin Karp Algorithm.
using System; 
public class Rabin_Karp
{ 
	// x is the number of characters in the input alphabet 
	public readonly static int x = 256; 
	
	/* pat -> pattern 
		txt -> text 
		z -> A prime number 
	*/
	static void search(String pat, String txt, int z) 
	{ 
		int M = pat.Length; 
		int N = txt.Length; 
		int i, j; 
		int p = 0; // hash value for pattern 
		int t = 0; // hash value for txt 
		int h = 1; 
	
		// The value of h would be "pow(x, M-1)%z" 
		for (i = 0; i < M-1; i++) 
			h = (h*x)%z; 
	
		// Calculate the hash value of pattern and first 
		// window of text 
		for (i = 0; i < M; i++) 
		{ 
			p = (x*p + pat[i])%z; 
			t = (x*t + txt[i])%z; 
		} 
	
 
		for (i = 0; i <= N - M; i++) 
		{ 
	
			// Check the hash values of present window of text 
			// and pattern. If the hash values match, only then 
			// check for characters one by one 
			if ( p == t ) 
			{ 
				/* Check for characters one by one */
				for (j = 0; j < M; j++) 
				{ 
					if (txt[i+j] != pat[j]) 
						break; 
				} 
	
				// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
				if (j == M) 
					Console.WriteLine("Pattern found at index " + i); 
			} 
	
			// Calculate hash value for next window of text: Remove leading digit, add trailing digit 
			if ( i < N-M ) 
			{ 
				t = (x*(t - txt[i]*h) + txt[i+M])%z; 
	
				// We might get negative value of t hence converting it to positive			
				if (t < 0) 
				t = (t + q); 
			} 
		} 
	} 
	
	/* Driver program */
	public static void Main() 
	{ 
		String txt = Console.ReadLine(); 
		String pat = Console.ReadLine(); 
		int z = 101; // A prime number 
		search(pat, txt, z); 
	} 
} 


//Input 
//txt : ABAAABCDBBABCDDEBCABC
//pat: ABC

//Output
//Pattern found at index 4
//Pattern found at index 10
//Pattern found at index 18
