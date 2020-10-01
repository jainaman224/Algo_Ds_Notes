#include<bits/stdc++.h>
using namespace std;
int josephus(int no,int h)
{
    if(no==1)
        return 1;
    else
        return (josephus(no - 1,h)+ h-1) % no + 1;
}
int main()
{
    int a = 20;
    int b = 5;
    cout<<"The chosen place is "<<josephus(a,b);
    return 0;
}
