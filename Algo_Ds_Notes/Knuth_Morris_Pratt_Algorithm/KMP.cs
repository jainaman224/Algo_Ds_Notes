using System;

namespace KMP_matching
{
    class Program
    {
        public static void calculateLps(string pattern, int[] lps)
        {
            int length = 0; // Length of the previous longest prefix suffix
            int i;

            lps[0] = 0;
            i = 1;

            // The loop calculates lps[i] for i = 1 to size - 1
            while(i < pattern.Length)
            {
                if(pattern[i] == pattern[length])
                {
                    length++;
                    lps[i] = length;
                    i++;
                }
                else // If (pattern[i] != pattern[len])
                {
                    if(length != 0)
                        length = lps[length - 1];
                    else
                    {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        public static void KMPSearch(string pattern, string text)
        {
            int sizePattern = pattern.Length;
            int sizeText = text.Length;

            int[] lps = new int[sizePattern];
            int j  = 0;

            calculateLps(pattern, lps);

            int i = 0;

            while(i < sizeText)
            {
                if (pattern[j] == text[i])
                {
                    j++;
                    i++;
                }

                if(j == sizePattern)
                {
                    Console.WriteLine("Pattern found at " + Convert.ToString(i - j + 1));
                    j = lps[j - 1];
                }
                else if (i < sizeText && pattern[j] != text[i])
                {
                    if(j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
                }
            }
        }

        public static void Main(String[] args)
        {
            string text = "namanchamanbomanamansanam";
            string pattern = "aman";
            KMPSearch(pattern, text);
            Console.ReadLine();
        }
    }
}


/* Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

*/
