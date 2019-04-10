/* Given a text txt[0..n-1] and a pattern pat[0..m-1], we need to find all occurrences of pat[] in txt[] */
/* Assume: n>m */
class KMP
{
    void KMPSearch(String pat, String txt)
    {
        int M = pat.length();
        int N = txt.length();
        int lps[] = new int[M]; // longest_prefix_suffix array
        int j = 0; // index for pat[]

        computeLPSArray(pat, M, lps); //calculate lps[] array

        int i = 0; //index for txt[]
        while(i < N)
        {
            if (pat.charAt(j) == txt.charAt(i))
            {
                j++;
                i++;
            }

            if (j == M)
            {
                System.out.println("Found pattern at index"+(i-j));
                j = lps[j - 1];
            }
            else if (i < N && pat.charAt(j) != txt.charAt(i))
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }

    void computeLPSArray(String pat, int M, int lps[]) // length of the previous longest prefix suffix
    {
        int len = 0;
        int i = 1;
        lps[0] = 0; //lps[0] is always 0

        while(i < M) //calculate lps[i] for i=1 to M-1
        {
            if (pat.charAt(i) == pat.charAt(len))
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }

    //Driver program to test above function
    public static void main(String args[])
    {
        String txt = "namanchamanbomanamansanam";
        String pat = "aman";
        new KMP().KMPSearch(pat, txt);
    }
}

/* Output

Pattern found at 1
Pattern found at 7
Pattern found at 16
*/

