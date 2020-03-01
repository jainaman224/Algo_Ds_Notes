import java.util.Scanner;
import java.util.Stack;

public class BalancedParentheses {

    //a function to check if the top of the stack is equal to the current character
    private static boolean bracketsame(char opening,char closing)
    {
        if(opening == '(' && closing == ')')
            return true;
        else if(opening == '{' && closing == '}')
            return true;
        else if(opening == '[' && closing == ']')
            return true;
        return false;
    }

    public static void main(String[] args) {

        System.out.print("Enter an expression : ");

        Scanner scan= new Scanner(System.in);
        //creating an empty stack

        Stack<Character> stk=new Stack<Character>();
        //clears the stack
        stk.clear();
        //taking input
        String expression=scan.nextLine();

        for(int i=0;i<expression.length();i++){
            //if an opening bracket is encountered then push it to the stack
            if(expression.charAt(i)=='('||expression.charAt(i)=='['||expression.charAt(i)=='{')
                stk.push(expression.charAt(i));
            else if(expression.charAt(i)==')'||expression.charAt(i)==']'||expression.charAt(i)=='}'){
                /*if a closing bracket is encountered and if the stack is empty or the
                 top character of the stack does not balance the current bracket then push
                 the bracket to the stack and break
                */
                if(stk.isEmpty()||!bracketsame(stk.peek(),expression.charAt(i))){
                    stk.push(expression.charAt(i));
                    break;
                }else{
                    //matching pair is found so pop the element from the stack
                    stk.pop();
                }
            }
        }
        if(stk.isEmpty())
            //if stack is empty i.e every bracket has it's matching pair
            System.out.println("YES! The expression is balanced");
        else
            System.out.println("NO! The expression is not balanced");
    }
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