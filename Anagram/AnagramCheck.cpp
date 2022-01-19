#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(string s1,string s2)
{
    int sum1=0,sum2=0;
    for(int i=0;i<s1.length();i++)
    {
        sum1+=s1[i];
    }
    for(int i=0;i<s2.length();i++)
    {
        sum2+=s2[i];
    }
    if(sum1==sum2)
        return true;
    else
        return false;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(checkAnagram(s1,s2))
        cout<<"Anagram";
    else
        cout<<"Not Anagram";
    return 0;
}
