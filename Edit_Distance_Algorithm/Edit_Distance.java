 
class Edit_distance
{ 
	static int min(int one, int two, int three) 
	{ 
		if (one <= two && one <= three) return one; 
		if (two <= one && two <= three) return two; 
		else return three; 
	} 

	static int Edit_Distance(String a , String b , int m , int n) 
	{ 
		// If first string is empty, the only option is to insert all characters of second string into first 
	if (m == 0) return n; 
	
	// If second string is empty, remove all characters of first string 
	if (n == 0) return m; 
	
	 
	if (a.charAt(m-1) == b.charAt(n-1)) 
		return Edit_Distance(a, b, m-1, n-1); 
	
	// If last characters are not same, consider all three operations on last character of first string, recursively 
	// compute minimum cost for all three operations and take minimum of three values. 
	return 1 + min ( Edit_Distance(a, b, m, n-1),  // Insert 
					Edit_Distance(a, b, m-1, n),   // Remove 
					Edit_Distance(a, b, m-1, n-1)   // Replace					 
				); 
	} 

	public static void main(String args[]) 
	{ 
		String a = "kanchan"; 
		String b = "thareja"; 

		System.out.println( Edit_Distance( a , b , a.length(), b.length()) ); 
	} 
} 

// OUTPUT :
//   6
