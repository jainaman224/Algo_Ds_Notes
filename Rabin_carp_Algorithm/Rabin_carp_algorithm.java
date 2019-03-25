

/**This is a Java Program to Implement Rabin Karp Pattern Matching Algorithm. The Rabin–Karp algorithm is a string searching algorithm that uses hashing to find any one of a set of pattern strings in a text.
Here is the source code of the Java Program to Implement Rabin Karp Pattern Matching Algorithm. The Java program is successfully compiled and run on a Windows system. The program output is also shown below.**/
/*Time comlexity:-The average and best case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).*/
/**
 ** Java Program to Implement Rabin Karp Pattern Matching Algorithm
 
**Input and Output:-
**Rabin Karp Algorithm Test:-
 
 
Enter Text
 
abcdefghijklmnopqrstuvwxyz
 
Enter Pattern
 
jklmn
 
Results :
 
Pattern found at position : 9
 **/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Random;
import java.math.BigInteger;
 
public class RabinKarp 
{
    /** String Pattern **/
    private String pat; 
    /** pattern hash value **/    
    private long patHash;    
    /** pattern length **/
    private int patlen;  
    /** Large prime **/         
    private long prime_large; 
    /** radix **/         
    private int radix;   
    /** radix^(patlen-1) % prime_large **/        
    private long RM;          
 
    /** Constructor **/
    public RabinKarp(String txt, String pat) 
    {
        this.pat = pat;      
        radix = 256;
        patlen = pat.length();
        prime_large = longRandomPrime();
        /** precompute radix^(patlen-1) % prime_large for use in removing leading digit **/
        RM = 1;
        for (int i = 1; i <= patlen-1; i++)
           RM = (radix * RM) % prime_large;
        patHash = hash(pat, patlen);
        int pos = search(txt);
        if (pos == -1)
            System.out.println("\nNo Match\n");
        else
            System.out.println("Pattern found at position : "+ pos);
    } 
    /** Compute hash **/
    private long hash(String key, int patlen)
    { 
        long h = 0; 
        for (int j = 0; j < patlen; j++) 
            h = (radix * h + key.charAt(j)) % prime_large; 
        return h; 
    } 
    /** Funtion check **/
    private boolean check(String txt, int i) 
    {
        for (int j = 0; j < patlen; j++) 
            if (pat.charAt(j) != txt.charAt(i + j)) 
                return false; 
        return true;
    }
    /** Funtion to check for exact match**/
    private int search(String txt) 
    {
        int txtlen = txt.length(); 
        if (txtlen < patlen) return txtlen;
        long txtHash = hash(txt, patlen); 
        /** check for match at start **/
        if ((patHash == txtHash) && check(txt, 0))
            return 0;
        /** check for hash match. if hash match then check for exact match**/
        for (int i = patlen; i < txtlen; i++) 
        {
            // Remove leading digit, add trailing digit, check for match. 
            txtHash = (txtHash + prime_large - RM * txt.charAt(i - patlen) % prime_large) % prime_large; 
            txtHash = (txtHash * radix + txt.charAt(i)) % prime_large; 
            // match
            int offset = i - patlen + 1;
            if ((patHash == txtHash) && check(txt, offset))
                return offset;
        }
        /** no match **/
        return -1;
    }
    /** generate a random 31 bit prime **/
    private static long longRandomPrime() 
    {
        BigInteger prime = BigInteger.probablePrime(31, new Random());
        return prime.longValue();
    }
    /** Main Function **/
    public static void main(String[] args) throws IOException
    {    
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Rabin Karp Algorithm Test\n");
        System.out.println("\nEnter Text\n");
        String text = br.readLine();
        System.out.println("\nEnter Pattern\n");
        String pattern = br.readLine();
        System.out.println("\nResults : \n");
        RabinKarp rk = new RabinKarp(text, pattern);        
    }
}
