// this is to check whether the equation cooontaing the brackets is balanced or not using the stacks .


#include<iostream>
#include<stack>

using namespace std;
void show(stack<int>s)
{
  while(s.empty()!=true)
  {
  
     cout<<s.top()<<" ";
     s.pop();}
}

int main()
{
 stack<char>s;
 string c="((}))";
 bool is_balanced=true;
 char x;
 for(int i=0;c[i]!='\0';i++)
 {
   if(c[i]=='(' || c[i]=='{' ||c[i]=='[')
   s.push(c[i]);
   
   if(c[i]==')')
   {
     x=s.top();
     if(x!='(')
     {is_balanced=false;
      break;}
      else 
     s.pop();
   
   
   }
   if(c[i]=='}')
   {
     x=s.top();
     if(x!='{')
     {is_balanced=false;
      break;}
     else 
     s.pop();
   
   }
   if(c[i]==']')
   {
     x=s.top();
     if(x!='[')
     {
     is_balanced=false;
     break; 
      }else 
     s.pop();
   
   }
 }
 cout<<is_balanced<<endl;
 if(is_balanced)
 cout<<"the equation is balanced"<<endl;
 else 
 cout<<"the equation is not balanced"<<endl;
}



