/*Boyer Moore Algorithm for Pattern Search*/
package main

import "fmt"

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

//Using Bad Character Heuristic method
func preprocess(str string, length int, chars []int) {

    for i,_:=range(chars) {chars[i] = 1}

    //The last occurrence of the char
    for k := 0; k < length; k++ {
        chars[int(str[k])] = k;
    }
}

func boyreMoore(text string, pattern string) {
    var lenStr int = len(text)
    var lenPattern int = len(pattern)

    chars := make([]int, 128)

    preprocess(pattern, lenPattern, chars)

    //shift of the pattern with respect to text
    var shift int = 0

    for shift <= lenStr - lenPattern {
        match := lenPattern - 1

        for (match >= 0 && pattern[match] == text[shift + match]) {
            match = match - 1
        }
        
        // If pattern found, match = -1
        if match < 0 {
            fmt.Printf("Pattern found at : %d\n", shift)
            
            // Shift the pattern so that the next character in text 
            //aligns with the last occurrence of it in pattern.
            if shift + lenPattern < lenStr {
                shift = shift + lenPattern - chars[text[shift + lenPattern]]
            } else {
                shift = 1
            }
        } else {
            shift = shift + max(1, match - chars[text[shift + match]]);
        }
    }
}

func main() {
    var text string
    var pattern string
    fmt.Println("Enter the text : ")
    fmt.Scan(&text)
    fmt.Println("Enter the pattern to search : ")
    fmt.Scan(&pattern)

    boyreMoore(text, pattern)

}

/*Input :
* Enter the text :
* therethenthat
* Enter the pattern :
* the
* Pattern found at : 0
* Pattern found at : 8
*/
