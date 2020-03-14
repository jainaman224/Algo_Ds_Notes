/*Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated 
and only the integer part of the result is returned.*/

class Solution {
public:
    int mySqrt(long int x) {
        long int c = 0, m;
        for(long int i = 1;i <= x;i++)
        {
            m = i*i;
            if(m == x)
            {
                c = i;
                break;
            }
            else if(m > x){
                c = i-1;
                break;
            }
        }
        return c;
    }
};
int stringToInteger(string input) {
    return stoi(input);
}
int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        int ret = Solution().mySqrt(x);
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

/*Sample Input:
Input: 4
Output: 2*/
