

class AWQ{ 
	
	static int NO_OF_CHARS = 256; 
	

	static int max (int a, int b) { return (a > b)? a: b; } 

	static void badCharHeuristic( char []str, int size,int badchar[]) 
	{ 
	int i; 

	// Initialize all occurrences as -1 
	for (i = 0; i < NO_OF_CHARS; i++) 
		badchar[i] = -1; 

	// Fill the actual value of last occurrence 
	// of a character 
	for (i = 0; i < size; i++) 
		badchar[(int) str[i]] = i; 
	} 


	static void search( char txt[], char pat[]) 
	{ 
	int m = pat.length; 
	int n = txt.length; 

	int badchar[] = new int[NO_OF_CHARS]; 


	badCharHeuristic(pat, m, badchar); 

	int s = 0; // s is shift of the pattern with 
				// respect to text 
	while(s <= (n - m)) 
	{ 
		int j = m-1; 


		while(j >= 0 && pat[j] == txt[s+j]) 
			j--; 


		if (j < 0) 
		{ 
			System.out.println("Patterns occur at shift = " + s); 


			s += (s+m < n)? m-badchar[txt[s+m]] : 1; 

		} 

		else
		
			s += max(1, j - badchar[txt[s+j]]); 
	} 
	} 

	
	public static void main(String []args) { 
		
		char txt[] = "ABAAABCD".toCharArray(); 
		char pat[] = "ABC".toCharArray(); 
		search(txt, pat); 
	} 
} 
