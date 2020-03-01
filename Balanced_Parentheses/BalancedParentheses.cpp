//The following code is the implementation of balanced parentheses using stacks
#include <bits/stdc++.h>

using namespace std;

//this function checks whether the character in the string is opening bracket or not
bool isOpen(char c)
{
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

//this function checks whether the brackets balance each other or not
bool isBalanced(char popped, char now)
{
    if(popped == '(' && now ==')')
        return true;
    if(popped == '[' && now ==']')
        return true;
    if(popped == '{' && now =='}')
        return true;
    return false;
}

int main()
{
	string str;
	cout<<"Enter an expression : ";
    cin>>str;
	//create an empty stack
    stack<char> s;
    int no = 0;
    for(int i = 0; i < str.length(); i++)
    {
        char now = str[i];
        //if opening brackets are encountered push it to the stack
        if(isOpen(now))
            s.push(now);
        else
        {
            char popped;
            if(s.size() > 0)//if stack is not empty 
            {
                popped = s.top();
                s.pop();
            }
            //if the stack is empty and we get a closing bracket then it is definitely not balanced
            else
            {
                no = 1;
                break;
            }
            //if the top element of the stack is the corresponding opening bracket of the current closing bracket then continue else break from loop
            if(isBalanced(popped, now))
                continue;
            else
            {
                no = 1;
                break;
            }
        }
    }
    //if there is any element left after all the push and pop operations 
    //then the brackets are not balanced
    if(s.size() != 0)
        no = 1;
    if(no)
        cout<<"NO! The brackets are not balanced\n";
    else
    {
        cout<<"YES! The brackets are balanced\n";
    }
    return 0;
}

/*Sample input:
Enter an expression
()(){[]}
Sample output:
YES! The brackets are balanced

Sample input:
Enter an expression
)()[]{{[]}}
Sample output:
NO! The brackets are not balanced
*/


    
