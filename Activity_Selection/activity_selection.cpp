#include<iostream>
using namespace std;
void print_activities(int s[], int f[], int n)
{
    int i, j;
    cout<<"Following activities are selected";
    i=0;
    cout<<"\n"<<i<<"\t";
    for(j=1; j<n; j++)
    {
        if(s[j]>=f[i])
        {
            cout<<j<<"\t";
            i=j;
        }
    }
}
int main()
{
    int s[]={1,3,0,5,8,5},f[]={2,4,6,7,9,9};
    int n=sizeof(s)/sizeof(s[0]);
    print_activities(s,f,n);
    return 0;
}
