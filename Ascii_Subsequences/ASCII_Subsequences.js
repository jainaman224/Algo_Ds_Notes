/*ASCII SUBSEQUENCES PROBLEM
This problem is same as the "Subsequences" question just instead of two function calls, three function calls will be made :
- One with the same string.
- One with a letter added.
- One with the ascii code of the letter added to the string.
- For example:-
Take as input str, a string. We are concerned with all the possible ASCII-subsequences of str. E.g. "ab" has following ascii-subsequences "", "b", "98", "a", "ab", "a98", "97", "97", "9798"
a. Write a recursive function which returns the count of ASCII-subsequences for a given string. Print the value returned.
b. Write a recursive function which prints all possible ASCII-subsequences for a given string (void is the return type for function).
*/
//*********************//
/*Time Complexity:
O(3^N) where N = String Length.*/
//*******************//

function subseq(s, i, str)
{
	if(i === str.length) 
	{
		console.log(s);
		return;
	}
    
	// The 3 function calls in the same order as explained above.
	subseq(s, i + 1, str); // First function call
	subseq(s + str[i], i + 1, str); // Second function call
	var n = str.charCodeAt(i); 
	subseq(s + n.toString(), i + 1, str); // Third functon call with the ASCII value of the ith element of the string

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
