# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
    char element, operator;
    length = strlen(postfix);
    printf("\nInfix Expression: ");
    printf("%c", postfix[0]);
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
            operator = postfix[count];//character is assigned to operator
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
