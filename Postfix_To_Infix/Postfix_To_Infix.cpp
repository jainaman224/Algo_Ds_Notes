# include <iostream>
# include <cstring>
using namespace std;

char stack[20];
int top = -1;

//Pop the top value from the stack.
char pop()
{
    return stack[top--];
}

//Push it onto the stack.
void push(char ch)
{
    stack[++top] = ch;
}

//Checking if it is operator or letter
bool operand(char x)
{
    if(x == '+' || x == '-' || x == '*'|| x == '/')
        return true;
    return false;
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
            //If the character is letter , push it in the stack
            push(postfix[count]); 
        }
        else
        {
            //pop the element present in the stack
            element = pop(); 
            //character is assigned to operator
            operators = postfix[count]; 
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
