/*The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern)
of the pattern and improves the worst case complexity to O(n). The basic idea behind KMP’s algorithm is: whenever we detect a mismatch
(after some matches), we already know some of the characters in the text of the next window. This information is used to avoid 
matching the characters that will anyway match.*/
import 'dart:io';

List prefix_function (String pattern)
{
    var m = pattern.length;
    var pi = [];
    pi.add(-1);
    var k = -1;
    for (var j = 1; j < m; j++)
    {
        while (k > -1 && pattern[k + 1] != pattern[j])
        {
            k = pi[k];
        }
        if (pattern[k + 1] == pattern[j])
        {
            k = k + 1;
        }
        pi.insert(j,k);
    }
    return pi;
}

void KMP_matcher (String text, String pattern)
{
    var n = text.length;
    var m = pattern.length;
    var pi = [];
    pi = prefix_function(pattern);
    
    var j = -1; //number of chars matched
    for (var i = 0; i < n; i++)
    {
        while (j >= 0 && pattern[j+1] != text[i])
        {
            j = pi[j]; //next char doesnot match
        }
        if (pattern[j+1] == text[i])
        {
            j = j + 1;
        }
        if (j == m - 1)
        {
            var result = i - m + 2;
            print ("Pattern found at position: $result");
            j = pi[j];
        }
    }
}

main()
{
    print ("Enter Text:");
    String text = stdin.readLineSync();
    print ("Enter Pattern:");
    String pattern = stdin.readLineSync();
    KMP_matcher (text, pattern);
    return 0;
}

/*
Enter Text:
gfmghdmgmgcc
Enter Pattern:
mg
Pattern found at position: 3
Pattern found at position: 7
Pattern found at position: 9 */

