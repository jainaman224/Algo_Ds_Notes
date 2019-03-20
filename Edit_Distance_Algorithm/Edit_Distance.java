 
class Edit_distance
{ 
	static int min(int left, int right, int diagnol) 
	{ 
		if (left <= right && left <= diagnol) return left; 
		if (right <= left && right <= diagnol) return right; 
		else return diagnol; 
	} 

	static int Edit_Distance(String first_str , String second_str , int m , int n) 
	{ 
		// If first string is empty, the only option is to insert all characters of second string into first 
		if (m == 0) return n; 
	
		// If second string is empty, remove all characters of first string 
		if (n == 0) return m; 
	
	 
		if (first_str.charAt(m-1) == second_str.charAt(n-1)) 
		return Edit_Distance(first_str, second_str, m-1, n-1); 
	
		// If last characters are not same, consider all three operations on last character of first string, recursively 
		// compute minimum cost for all three operations and take minimum of three values. 
		return 1 + min ( Edit_Distance(first_str, second_str, m, n-1), Edit_Distance(first_str, second_str, m-1, n), 
				Edit_Distance(first_str, second_str, m-1, n-1)); 
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

