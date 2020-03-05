/*Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.*/

 bool isPalindrome(int x) {

        int y=x;
        if(x<0)
            return false;


        long int d,rev=0;



        while(y>0)
        {
            d=y%10;
            rev=rev*10 + d;
            y=y/10;
        }

        if(rev==x)
        return true;
        else
            return false;

    }
/*
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.*/
