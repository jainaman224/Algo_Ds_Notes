/*
This program checks whether the two input strings are anagrams or not.
*/


#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s1, s2;
    int count[256] = {0}, i, flag = 0;
    cin >> s1;
    cin >> s2;

    for(i = 0; i < s1.length(); i++)
    {   
        /*
         For each character in s1, increment count in 
         the corresponding count array
        */ 
        count[s1[i]]++;
    }

    for(i = 0; i < s2.length(); i++)
    {
        /*
         For each character in s2, decrement count in 
         the corresponding count array
        */ 
        count[s2[i]]--;
    }
    
    for(i=0; i < 256; i++)
    {
      // See if there is any non-zero value in count array 
      if(count[i] != 0)
          flag = 1;
    }

    if(!flag)
        cout << "Given strings are anagrams " << endl;
    else
        cout << "Given strings are not anagrams" << endl;

    return 0;
}



/*
  INPUT:
  s1="abc"
  s2="cba"
  OUTPUT:
    Given strings are anagrams
  
  INPUT:
    s1="abc"
    s2="azs"
  OUTPUT:
    Given strings are not anagrams
*/

