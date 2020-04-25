/* Function to create Longest Proper Prefix for given pattern that we want to search in the text*/
function lpsValues( lps, pattern, len_pattern)
{
    //length of longest prefix that is also suffix, will be zero for 1st charater as no prefix ans no suffix
    lps[0] = 0;
    //length of previous longest prefix that is also suffix
    var len_prev = 0;
    //iterator to calculate values lps[1].....lps[len_pattern]
    var i = 1;
    while (i < len_pattern )
    {
        if (pattern.charAt(i) === pattern.charAt( len_prev))
        {
            len_prev = len_prev+1;;
            lps[i] = len_prev;
            i++;
        }
        else // (pat[i] != pat[len]) 
        { 
             
            if (len_prev != 0) 
            { 
                len_prev = lps[len_prev - 1]; 
            } 

            else // if (len == 0) as no prefix found
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}


function KmpPatternSearch(pattern, text)
{
    len_pattern = pattern.length;
    len_text = text.length;
    
    //We find Longest Proper Prefix to decide which chater will be matched next
    var lps = new Array(len_pattern);
    
    lpsValues(lps, pattern, len_pattern);

    //iterator
    var i = j = 0;
    while (i < len_text)
    {
        if (pattern.charAt(j) === text.charAt(i))
        {
            //Pattern ans text matched
            i = i+1;
            j = j+1;
        }
        if (j === len_pattern)
        {  
            return i-j;
            j = lps[j-1];
        }
        else if (j != len_pattern && pattern.charAt(j) != text.charAt(i))
        { 

            if  (j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i = i+1;
            }
        }
    }
}
//Used synchronous readline package to take console input 
var readlineSync = require('readline-sync');
//User input for text to be searched
var a = readlineSync.question('Enter text to be searched: ');
//User input for pattern to be searched in text
var b = readlineSync.question('Enter the pattern to be searched: ');
var index=KmpPatternSearch(b,a);
if (index == undefined)
{
    console.log("Pattern not found.");
}
else
{
    console.log("Pattern observed at index:", index);
}
//Input 1: text :"abcabaabcabac"  pattern:"abaa"
//Output will be 3
//Input 2: text:"aabbcdefgh"   pattern:"fgh"
//Output will be 7
//Input 3: text:"aaaaaa"    pattern:"bb"
//Output: Pattern not found
