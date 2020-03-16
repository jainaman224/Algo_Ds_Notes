/*ASCII SUBSEQUENCES PROBLEM
This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :
- One with the same string.
- One with a letter added.
- One with the ascii code of the letter added to the string.
*/

function subseq(s, i, str) 
{
    if(i === str.length) 
    {
        console.log(s);
        return;
    }
    
    // The 3 function calls in the same order as explained above.
    // First function call
    subseq(s, i + 1, str); 
    // Second function call
    subseq(s + str[i], i + 1, str); 
    var n = str.charCodeAt(i); 
    // Third function call with the ASCII value of the ith element of the string
    subseq(s + n.toString(), i + 1, str); 
}

( function IIFE() {
    var str = prompt("Enter the string");
    console.log( "Number of Subsequences : ", Math.pow(3, str.length));
    subseq("", 0, str);
    return 0;
})();

/*Sample Input: Enter the string:
ab
Sample Output:
Number of Subsequences : 9

b
98
a
ab
a98
97
97b
9798
*/
