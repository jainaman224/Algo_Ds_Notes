/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. 
Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int a[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string s[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string ans = "";
        int i = 12;
        while(num > 0)
        {
            int d = num / a[i];
            num = num % a[i];
            while(d--)
            {
                ans = ans + s[i];
            } 
            i--;
        }
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        string ret = Solution().intToRoman(num);
        string out = (ret);
        cout << out << endl;
    }
    return 0;
} 
/*
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
*/ 
