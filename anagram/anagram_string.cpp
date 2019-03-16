#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool isAnagram(string a,string b)
{
	int n1,n2,i;
	n1=a.length();
	n2=b.length();
	if(n1!=n2)
		return false;
	else
	{
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(i=0;i<n1;i++)
		{
			if(a[i]!=b[i])
				return false;	
		}
		return true;	
	}
	
}

using namespace std;
int main ()
{
	string a,b;
	//taking input of the first string 
	
	cin>>a;
		//taking input of the second string 
		
	cin>>b;
	if(isAnagram(a,b))
		cout<<"the string you entered is anagram"<<endl;
	else
		cout<<" the string you entered is not anagram"<<endl;
	
	return 0;
}
