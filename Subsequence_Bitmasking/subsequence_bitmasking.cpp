//Subsequence of a String using bitmasking
#include<iostream>
#include<string>
using namespace std;
void subsequence_bitmasking(string s)
{
    //Calculate length of string 
    int len = s.length();

    //Number of subsequence are always 1>>length
    
    for(int i=0;i<(1<<len);i++)
    {
        int m=0;
        string ans="";
        int j=i;
        while(j)
        {
            if(j&1)
            {
                ans+=s[m];
            }
            m++;
            j = j>>1;
        }
        cout<<ans<<" ";
    }
}
int main()
{
    string str;
    cout<<"Enter string"<<endl;
    cin>>str;
    subsequence_bitmasking(str);
    return 0;
}