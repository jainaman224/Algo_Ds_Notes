#include <stdio.h>
#include <string.h>

//our expression can contain maximum of 100 characters
#define MAX 100

int top = -1;
int stk[MAX];

void push(char c)
{
	//checking overflow condition
	if(top == (MAX -1))
		printf("Stack Overflow\n");
	else
	{
		top += 1;
		stk[top] = c;
	}
}

char pop()
{
	//checking underflow conditions
	if(top == -1)
		printf("\nStack Overflow");
	else
		return(stk[top--]);
}

int main()
{
	char exp[MAX],temp;
	int i,flag = 1;
	printf("Enter an expression : ");
	gets(exp);
	for(i = 0;i<strlen(exp);i++)
	{
		//if an opening bracket is encountered push it to the stack
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			push(exp[i]);
		if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		//if expression starts with a closing bracket then it's definitely not balanced
			if(top==-1)
				flag = 0;
			else
			{
				temp = pop();
				//if the top element of the stack is not a matching pair of the current bracket then it's not balanced
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag = 0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag = 0;
				if(exp[i]==']' && (temp=='{' || temp=='('))
					flag = 0;
			}
	}
	//if the stack is not empty i.e a bracket is left which doesn't have its matching pair
	if(top>=0)
		flag = 0;
	if(flag==1)
		printf("YES! The brackets are balanced\n");
	else 
		printf("NO! The brackets are not balanced\n");
		
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
