// Function for Naive_String_Matching
fun match(text: String, pattern: String) {
    for (i in 0 until (text.length - pattern.length + 1)) {
        for (j in 0 until pattern.length) {
            if (text[i + j] != pattern[j]) {
                break
            }
            if (j + 1 == pattern.length) {
                println("Pattern Found at ${i + 1}")
            }
        }
    }
}

// Driver Function for Naive_String_Matching
fun main() {
    // Taking input of text(String)
    val text = readLine()!!
    // Taking input of pattern(String)
    val pattern = readLine()!!
    match(text, pattern)
}

// Input:- Text-> asdf;asdf;asdf;
//         Pattern-> asdf
// Output:- Pattern Found at 1
//          Pattern Found at 6
//          Pattern Found at 11
