/*
Knuth Morris Pratt String Searching Algorithm
Given a text txt[0..n-1] and a pattern pat[0..m-1], the algo will find all occurrences of pat[] in txt[]
*/

import java.util.*

internal class KMP {
    fun kmpSearch(pat: String, txt: String) {
        val m = pat.length
        val n = txt.length
        // longest_prefix_suffix array
        val lps = IntArray(m)
        
        // index for pat[]
        var j = 0
        
        //calculate lps[] array
        computeLPSArray(pat, m, lps)
        
        //index for txt[]
        var i = 0
        while (i < n) {
            if (pat[j] == txt[i]) {
                j++
                i++
            }
            if (j == m) {
                println("Found pattern at index" + (i - j))
                j = lps[j - 1]
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0) j = lps[j - 1] else i += 1
            }
        }
    }

    // length of the previous longest prefix suffix
    private fun computeLPSArray(pat: String, M: Int, lps: IntArray) {
        var len = 0
        var i = 1

        //lps[0] is always 0
        lps[0] = 0

        //calculate lps[i] for i=1 to M-1
        while (i < M)
        {
            if (pat[i] == pat[len]) {
                len++
                lps[i] = len
                i++
            } 
            else {
                if (len != 0) len = lps[len - 1] else {
                    lps[i] = len
                    i++
                }
            }
        }
    }

    companion object {
        //Driver program to test above function
        @JvmStatic
        fun main(args: Array<String>) {
            val sc = Scanner(System.`in`)
            val txt = sc.nextLine()
            val pat = sc.nextLine()
            KMP().kmpSearch(pat, txt)
        }
    }
}

/*
Sample Input
namanchamanbomanamansanam
aman

Sample Output:
Patterns occur at shift = 1
Patterns occur at shift = 7
Patterns occur at shift = 16
 */
