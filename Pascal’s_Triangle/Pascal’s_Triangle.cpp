#include <stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 

int factorial(int n) 
{
   int f;
   for(f = 1; n > 1; n--)
      f *= n;
   return f;
}

int main() 
{
   int n, i, j;
   cout<<"Enter the numbers of rows ";
   cin>>n;
   for(i = 0; i < n; i++) 
   {
      for(j = 0; j < n-i; j++)
         cout<<"  ";
      for(j = 0; j <= i; j++)
        cout<<" "<<factorial(i)/(factorial(j)*factorial(i-j))<<"  ";
      cout<<"\n";
   }
   return 0;
}

//INPUT:Enter the numbers of rows 6
//OUTPUT:
//               1
//             1   1
//           1   2   1
//         1   3   3   1
//       1   4   6   4   1
//     1   5  10  10   5   1
