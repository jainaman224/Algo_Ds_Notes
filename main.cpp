#include <iostream>
#include <string>
#include <stack>


using namespace std;

bool isOperand(char c)
{
    if(c>='0' && c<='9') return true;
    if(c>='a' && c<='z') return true;
    if(c>='A' && c<='Z') return true;
    return false;
}

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='$') return true;
    return false;
}

bool isRightAssociative(char c)
{
    if(c=='$') return true;
    return false;
}

int getOpWeight(char op)
{
    int weight = -1;
    switch(op)
    {
        case '+': weight = 1;
                    break;
        case '-': weight = 1;
                    break;
        case '*': weight = 2;
                    break;
        case '/': weight = 2;
                    break;
        case '$': weight = 3;
                    break;
    }
    return weight;
}

bool hasHigherPrecedance(char c, char d)
{
    if(getOpWeight(c) == getOpWeight(d)){
        if(isRightAssociative(c)) return false;
        else return true;
    }
    return getOpWeight(c)>getOpWeight(d) ? true: false;
}

string postfix(string str)
{
    stack<char> S;
    string result = "";
    for(int i=0;i<str.length();i++){
        if(str[i]==' ' || str[i]==',') continue;
        else if(isOperand(str[i])){
            result += str[i];
        }
        else if(isOperator(str[i])){
            while(!S.empty() && (hasHigherPrecedance(S.top(),str[i]))){
                result += S.top(); S.pop();
            }
            S.push(str[i]);
        }
        else if(str[i]=='('){
            S.push(str[i]);
        }
        else if(str[i]==')'){
            while(!S.empty() && S.top()!='('){
                    result += S.top(); S.pop();
            }
            S.pop();
        }

    }
    while(!S.empty()){
        result += S.top(); S.pop();
    }
    return result;
}

int main()
{
    string exp;
    cout << "Enter the infix expression: ";
    getline(cin,exp);
    cout << endl << "Postfix expression: " << postfix(exp);
    return 0;
}
