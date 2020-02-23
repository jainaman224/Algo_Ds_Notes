//Postfix Evaluation
#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct stack
{
    char A[100];
    int Top;
};

void push(struct stack *ps, char x)
{
    if(ps -> Top == 99)
       printf("\nStack is Full\n");
    else
   {
       ps -> Top = ps -> Top + 1;
       ps -> A[ps -> Top] = x;
   }
}

int evaluate(int op1, int op2, char c)
{
    if(c == '+')
       return op1 + op2;
    else if(c == '-')
       return op1 - op2;
    else if(c == '*')
       return op1 * op2;
    else if(c == '/')
       return op1 / op2;
}

void print(struct stack s)
{
    int i;
    for(i = 0 ; i <= s.Top ; i++)
       printf("%d\t", s.A[i]);
}

int pop(struct stack *ps)
{
    int x;
    if(ps -> Top == -1)
       printf("Stack is empty!Element cant be deleted\n");
    else
    {
       x = ps -> A[ps -> Top];
       ps -> Top = ps -> Top - 1;
       return x;
    }
}

int main()
{
     int op1, op2, x, i;
     char optr;
     struct stack s;
     s.Top = -1;
     printf("Enter the postfix exp to be evaluated \n");
     gets(s.A);
     for(i = 0; i < strlen(s.A); i++)
     {
         if(isdigit(s.A[i]))
            push(&s, s.A[i] - '0');
         else if(s.A[i] == '+' || s.A[i] == '-' || s.A[i] == '*' || s.A[i] == '/')
         {
            op1 = pop(&s);
            op2 = pop(&s);
            optr = s.A[i];
            x = evaluate(op2, op1, optr);
            push(&s, x);
         }
      }

      printf("The result is :  ");
      print(s);
      printf("\n");   
}

/*Input - Output Sample
Enter the postfix exp to be evaluated 
2 3 1 * + 9 -
The result is :  -4
*/
