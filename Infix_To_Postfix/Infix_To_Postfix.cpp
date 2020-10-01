#include<bits/stdc++.h>
using namespace std;

int precedence_of_operator(char optr)
{
    /* 
    order of precedence of operators :
    +---+----------------+---------+
    | 6 | multiplicative | *, %, / |
    | 5 | additive       | +, -    |
    | 4 | bitwise AND    | &       |
    | 3 | bitwise XOR    | ^       |
    | 2 | bitwise OR     | |       |
    | 1 | assignment     | =       |
    +---+----------------+---------+	 
    */
    if(optr == '*' || optr == '%' || optr == '/')
	return 6;
    if(optr == '+' || optr == '-')
	return 5;
    if(optr == '&')
	return 4;
    if(optr == '^')
	return 3;
    if(optr == '|')
	return 2;
    if(optr == '=')
	return 1;
    return 0; // return 0 if given character is not an operator
}

string infix_to_postfix(string input)
{
    string output = ""; // store postfix expression of given infix expression
    stack<char> optr; // stack that stores all operators
    int i = 0;
    while(input[i] != '\0')
    {
	if(input[i] == '(') // if next char of input string is '(' 
	    optr.push('('); // push '(' in stack
	else if(input[i] == ')') // if next char of string is ')'
	{
	    char temp = optr.top();
    	    while(temp != '(')
	    {
		output += temp; // append all operator in output that presents in the pranthesis
		optr.pop();
		temp = optr.top();
	    }
			optr.pop(); // pop '(' from stack
	}
	else
	{
	    int precedence_of_curr_char = precedence_of_operator(input[i]); // get precedence of next char of string
	    if(precedence_of_curr_char != 0) // if next char is an operator
	    {
		if(optr.size() == 0) // if size of stack is zero
		    optr.push(input[i]); // push this operator in the stack
		else if(optr.top() == '(') // if previous char in stack in opening parenthesis
		    optr.push(input[i]); // then also push this operator in the stack
		else
		{
		    char prev_operator = optr.top(); // previous char in stack
		    if(precedence_of_operator(prev_operator)<precedence_of_curr_char)
		    optr.push(input[i]);
		    else
		    {
			while(optr.size() != 0)
		        {
			    if(optr.top() == '(')
				break;
			    output += optr.top(); // append all operator in output string that presents in the stack or in parenthesis
			    optr.pop();
			}
			optr.push(input[i]);
		    }
		}
	    }
	    else // if next character of input string is an operand
	    {
		output += input[i]; // append that operand in the output string
	    }
	}
	i++; // increase the index of string
    }
    // if we had traversed through complete string
    // then append all operator in output string that presents in the stack 
    while(optr.size() != 0)
    {
	output += optr.top();
	optr.pop();
    }
    return output;
}

int main()
{
    string input;
    getline(cin, input);
    string output = infix_to_postfix(input);
    cout << output << endl;
    return 0;
}

/*
sample input 1 : a+b*c
	  output 1 : abc*+
sample input 2 : a+b*(c^d-e)^(f+g*h)-i
	  output 2 : abcde-^*+fgh*+i-^
*/

/*
this code is contributed by raghav dalmia
https://github.com/raghav-dalmia
*/
