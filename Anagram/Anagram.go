/*
    Anagrams are strings formed by rearranging the
    letters of another string.
    Example: LISTEN and SILENT, as they have the same
    characters just appearing in another order.
*/

package main
import "fmt"

func main() {
    
    var str1 string
    var str2 string

    fmt.Println("Enter 1st string")
    fmt.Scanf("%s", &str1)

    fmt.Println("Enter 2nd string")
    fmt.Scanf("%s", &str2)

    var count1 [256]int
    var count2 [256]int

    // if lengths are not equal, they cannot be anagrams
    if len(str1) != len(str2) {
        fmt.Println("The strings are not anagrams")
        return
    }
    
    // Store the count of every character in string
    for i := 0; i < len(str1); i++ {
        count1[str1[i] - 'a']++
        count2[str2[i] - 'a']++
    }
    
    // If the counts of characters are not equal,
    // they are not anagrams
    for i := 0; i < 256; i++ {
        if count1[i] != count2[i] {
            fmt.Println("The strings are not anagrams")
            return
        }
    }
    fmt.Println("The strings are anagrams")
}

/*
Input:
car
arc

Output:
The strings are anagrams

Input:
cap
tap

Output:
The strings are not anagrams
*/
