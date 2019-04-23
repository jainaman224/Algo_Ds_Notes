# include <stdio.h> 

int top = -1;
int size = 10;
int stack[10];

// Function to push the value in stack array
void push(int value)
{
    if(top == size - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// Function to pop the top value in stack array
void pop()
{
    if(top == -1)
        printf("Stack Underflow \n ");
    else
        --top;
}  

// Function to find peek 
int peek(int stack[])
{
    if(top == -1)
    {
        printf("\nSTACK IS EMPTY");
        return -1;
    }
    else
        return (stack[top]);
}

// Function to print the stack array
void print()
{
    int temp = top - 1;

    printf("Top of stack is: %d \n", peek(stack));
        
    if(temp > -1);
        printf("Other: ");
    while(temp > -1)
        printf("%d", stack[temp--]);
    printf("\n");
}

int main() 
{
    int choice, value; 
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.Quit\n");
    
    do 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter value to be pushed: \n");
                    scanf("%d", &value);
                    push(value);
                    break;
                    
            case 2: pop();
                    break;
                    
            case 3: print();
                    break;
                    
            case 4: printf("Exit \n");
                    break;
                    
            default: printf("Invalid Choice \n");            
        }  
    } while(choice != 4);
    return 0;
}

/*1.Push
2.Pop
3.Display
4.Quit
Enter your choice : 1
Enter value to be pushed:
10
Enter your choice : 1
Enter value to be pushed:
20
Enter your choice : 1
Enter value to be pushed:
30
Enter your choice : 1
Enter value to be pushed:
40
Enter your choice : 2
Enter your choice : 3
Top of stack is : 30
Other : 20  10
Enter your choice : 4
Exit*/
