import java.util.Scanner;

public class Ascii_Subsequences {
	public static void main(String args[]) {
		// Your Code Here
		Scanner obj = new Scanner(System.in);
		String str = obj.next();
		int ans = find(str, "");
		System.out.println();
		System.out.println(ans);
	}

	public static int find(String str, String ans) {
		if (str.length() == 0) {
			System.out.print(ans + " ");
			return 1;
		}

		char ch = str.charAt(0);
		int x = find(str.substring(1), ans);
		int y = find(str.substring(1), ans + ch);
		int z = find(str.substring(1), ans + (int) ch);

		return x + y + z;
	}
}
