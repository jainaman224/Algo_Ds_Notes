# include <iostream>
# include <cstring>
using namespace std;

char stack[20];
int top = -1;

char pop()
{
    return stack[top--];//Pop the top value from the stack.
}

void push(char ch)
{
    stack[++top] = ch;//Push it onto the stack.
}

int operand(char x)//Checking if it is operator or letter
{
    if(x == '+' || x == '-' || x == '*'|| x == '/')
        return 1;
    return 0;
}

void postfix_to_infix(char postfix[])
{
    int length;
    char element,operators;
    length = strlen(postfix);
    cout << "\nInfix Expression: ";
    cout << postfix[0];
    for(int count = 1; count < length; count++)
    {   
        // If the character is not an operand.
        if(!operand(postfix[count]))
        {
            push(postfix[count]); //If the character is letter , push it in the stack
        }
        else
        {
            element = pop(); //pop the element present in the stack
            operators = postfix[count]; //character is assigned to operator
            cout << operators << element ;
        }
    }    
}

int main()
{
    char postfix[20];
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    postfix_to_infix(postfix);      
    return 0;
}

/*Enter Postfix Expression: ab*c+
Infix Expression: a*b+c */
