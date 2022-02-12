#include<iostream>
using namespace std;

class stack
{
private:
    int top;
public:
    stack()
    {
        top=-1;
    }
     int arr[10];
    void push(int n)
    {
        if(top>=10-1)
        {
            cout<<"stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=n;
            cout<<arr[top];
            cout<<endl;
        }
    }
    int pop()
    {
        if(top<0)
            cout<<"stack empty"<<endl;
        else
            {

                return arr[top--];
            }

    }
};
int main()
{
    stack a;
    cout<<"pushing"<<endl;
    a.push(10);
    a.push(20);
    a.push(30);
    cout<<"popping"<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.pop()<<endl;
   // cout<<a.pop()<<endl;
    return 0;
}
