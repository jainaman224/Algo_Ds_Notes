import java.util.*;

public class Lucas_Theorem {

    static int nCrModpDP (int n, int r, int p)
    {
        int C[] = new int[r + 1];
        C[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = Math.min(i, r); j > 0; j--)
                C[j] = (C[j] + C[j - 1]) % p;
        }

        return C[r];
    }

    static int nCrModpLucas (int n, int r, int p)
    {
        if (r == 0)
            return 1;
        int ni, ri;

        ni = n % p;
        ri = r % p;
        return (nCrModpLucas(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p;

    }

    public static void main (String args[]) 
    {
        int n, r, p;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        r = sc.nextInt();
        p = sc.nextInt();
        
        System.out.println("Value of nCr % p is " + nCrModpLucas(n, r, p));
    }
}

/*      INPUT - OUTPUT
     sample input
	     n = 1000
	     r = 900
	     p = 13
     output
     	value of nCr %p is 8 
*/
