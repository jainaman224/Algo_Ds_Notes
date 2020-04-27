/*
Boyer Moore String Matching Algorithm in Kotlin
Author: Arkadip Bhattacharya (@darkmatter18)
 */
import java.util.*

internal object Main {
    private var NO_OF_CHARACTERS = 256
    private fun maxOfAAndB(a: Int, b: Int): Int {
        return a.coerceAtLeast(b)
    }

    private fun badCharacterHeuristic(str: CharArray, size: Int, badcharacter: IntArray) {

        // Initialize all elements of bad character as -1
        var i = 0
        while (i < NO_OF_CHARACTERS) {
            badcharacter[i] = -1
            i++
        }
        // Fill the actual value of last occurrence of a character 
        i = 0
        while (i < size) {
            badcharacter[str[i].toInt()] = i
            i++
        }
    }

    // A pattern searching function 
    private fun search(text: CharArray, pattern: CharArray) {
        val m = pattern.size
        val n = text.size
        val badCharacterHeuristic = IntArray(NO_OF_CHARACTERS)

        // Fill the bad character array by calling the preprocessing function
        badCharacterHeuristic(pattern, m, badCharacterHeuristic)

        // s is shift of the pattern with respect to text
        var s = 0
        while (s <= n - m) {
            var j = m - 1

            // Keep reducing index j of pattern while characters of pattern and text are matching at this shift s
            while (j >= 0 && pattern[j] == text[s + j]) j--

            // If the pattern is present at current shift, then index j will become -1 after the above loop
            s += if (j < 0) {
                println("Patterns occur at shift = $s")

                // Shift the pattern so that the next character in text aligns with the last occurrence of it in pattern. 
                // The condition s+m < n is necessary for the case when pattern occurs at the end of text 
                if (s + m < n) m - badCharacterHeuristic[text[s + m].toInt()] else 1
            } else maxOfAAndB(1, j - badCharacterHeuristic[text[s + j].toInt()])
        }
    }

    /* Driver program*/
    @JvmStatic
    fun main(args: Array<String>) {
        val sc = Scanner(System.`in`)
        var s = sc.nextLine()
        val text = s.toCharArray()
        s = sc.nextLine()
        val pattern = s.toCharArray()
        search(text, pattern)
    }
}

/*
Sample Input:
AABAACAADAABAABA
AABA

Sample Output:
Patterns occur at shift = 0
Patterns occur at shift = 9
Patterns occur at shift = 12
 */
