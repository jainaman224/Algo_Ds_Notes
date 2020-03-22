 /* Take as input str, a string. We are concerned with all the possible ascii-subsequences of str.
    Also we have to print the count of such subsequences.
    Sample input : ab
    Sample output :
     b 98 a ab a98 97 97b 9798
     9 */

import java.util.Scanner;

public class Ascii_Subsequences {
    public static void main(String args[]) {
	Scanner obj = new Scanner(System.in);
	String str = obj.next();
	int ans = find(str, "");
	// This function will return count of such subsequences and also print them
	System.out.println();
	System.out.println(ans); //this is to print the count
    }

    public static int find(String str, String ans) {
        if (str.length() == 0) {
	    System.out.print(ans + " ");
	    return 1; // This will develop the count of such subsequences
	}

	char ch = str.charAt(0);
	int x = find(str.substring(1), ans); // when ans is passed as it is
	int y = find(str.substring(1), ans + ch); // when ch is added to the ans
	int z = find(str.substring(1), ans + (int) ch);
	// when ch's ascii code is added to the ans

	return x + y + z; 
        // The count for this frame will be sum of x, y, z
   }
}

// Sample input : ab
// Sample output :
// b 98 a ab a98 97 97b 9798
// 9 
