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
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        
        
        int a[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        
        string s[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        string ans="";
        
        while(num>0)
        {
            if(num>=1000)
            {
                ans=ans+ s[12];
                 num=num-1000;
                        
            }
             else if(num>=900)
             {  
                ans=ans+ s[11];
                  num=num-900;
             }
             else if(num>=500)
             {
                ans=ans+ s[10]; 
                 num=num-500;
             }
             else if(num>=400)
             {
                ans=ans+ s[9];
              num=num-400;
             }
             else if(num>=100)
             {
                ans=ans+ s[8];
                 num=num-100;
             }
             else if(num>=90)
             {
               ans=ans+ s[7];
                 num=num-90;
             }
            else if(num>=50)
             {
               ans=ans+ s[6];
                 num=num-50;
             }
            else if(num>=40)
             {
               ans=ans+ s[5];
                 num=num-40;
             }
            else if(num>=10)
             {
               ans=ans+ s[4];
                 num=num-10;
             }
            else if(num>=9)
             {
               ans=ans+ s[3];
                 num=num-9;
             }
                else if(num>=5)
             {
               ans=ans+ s[2];
                 num=num-5;
             }
            else if(num>=4)
             {
               ans=ans+ s[1];
                 num=num-4;
             }
            else if(num>=1)
             {
               ans=ans+ s[0];
                 num=num-1;
             }
            
        }
        cout<<ans;
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