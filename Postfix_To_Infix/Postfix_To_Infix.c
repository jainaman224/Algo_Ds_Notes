# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

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
    char element, operator;
    length = strlen(postfix);
    printf("\nInfix Expression: ");
    printf("%c", postfix[0]);
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
            operator = postfix[count];
            printf(" %c %c", operator, element);            
        }
    }    
}

int main()
{
    char postfix[20];
    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);
    postfix_to_infix(postfix);      
    return 0;
}    

/*
Enter Postfix Expression: ab*c+
Infix Expression: a * b + c*/
