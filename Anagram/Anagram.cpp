#include <iostream>
#include<string>

using namespace std;

int main()
{
	
	string s1,s2;
	int count2[256],count1[256],i,flag=0;//we are creating here two integer arrays two count occurrence of two char in string position wise because we have ascii values from 0-255 that is of size 265 

	//taking input of both the strings
	cin>>s1;
	cin>>s2;
	
	for(i=0;s1[i]&&s2[i];i++)
	{
	    count1[s1[i]]++;
	    count2[s2[i]]++;
	    
	    
	}
    if(s1[i]||s2[i])//means if any of the strings will have remaining character than or condition will be true and flag will be raised to 1;
	    flag=1;
	    
	for(i=0;i<256;i++)
	{
	    if(count1[i]!=count2[i])
	        flag=1;
	}
	
	if(flag==0)
	    cout<<"Given strings are anagrams "<<endl;
	else
	    cout<<"Given strings are not anagram"<<endl;
	
	return 0;
}
