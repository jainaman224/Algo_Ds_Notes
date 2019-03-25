
public class Z_Algorithm {

	static void getZarr(String str, int Z[]){

	    int n = str.length(), Left = 0, Right = 0, k;

	    for(int i = 1; i < n; i++)
	    {
	        if(i > Right)
	        {
	            Left = Right = i;

	            while(Right < n && str.charAt(Right - Left) == str.charAt(Right))
	                Right++;

	            Z[i] = Right - Left;
	            Right--;
	        }
	        else
	        {
	            k = i - Left;

	            if(Z[k] < Right - i + 1)
	                Z[i] = Z[k];
	            else
	            {
	                Left = i;

	                while(Right < n && str.charAt(Right - Left) == str.charAt(Right))
	                    Right++;

	                Z[i] = Right - Left;
	                Right--;
	            }
	        }
	    }
	}

	static void search(String text, String pattern){

	    String concat = pattern + "$" + text;
	    int size = concat.length();
	    int Z[] = new int[size];

	    getZarr(concat, Z);

	    for(int i = 0; i < size; i++){
	        if(Z[i] == pattern.length()){
	            int index = i-pattern.length();
	            System.out.println("Pattern found at " + index);
	        }
	    }


	}

	public static void main(String args[]){

		String text = "namanchamanbomanamansanam";
		String pattern = "aman";
		search(text, pattern);
	}
}
/*
Sample Input:
	namanchamanbomanamansanam (text)
	aman					  (pattern)

Sample Output:
	Pattern found at 2
	Pattern found at 8
	Pattern found at 17
*/
