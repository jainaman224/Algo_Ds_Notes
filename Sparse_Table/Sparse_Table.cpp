#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std; 


int main() 
{  
  int n;
  cout<< "Enter the number of elements :\n";
	cin>>n;
  int arr[n];
	cout<<"Enter the elements:\n";
  for (int i=0;i<n;i++)
    { 
      cin>>arr[i];
    }


    //Building the sparse table
    int sparsetable[n][n]; 
    for (int i = 0; i < n; i++) // Transferring value from array to sparse table
    sparsetable[i][0] = arr[i]; 
  
  for (int j = 1; (1 << j) <= n; j++) 
    { 
        // Compute minimum value for all intervals with size 2^j 
        for (int i = 0; (i + (1 << j) - 1) < n; i++)
            { 
                 if (sparsetable[i][j - 1] < sparsetable[i + (1 << (j - 1))][j - 1]) 
                      sparsetable[i][j] = sparsetable[i][j - 1]; 
                 else
                      sparsetable[i][j] =  sparsetable[i + (1 << (j - 1))][j - 1]; 
            } 
     } 
   
    

	  //Range Min Query 
    //To find min between L (query start) to R (query end) where 0 <= L <= R <= n-1
    cout<<"Enter the query start ";
    int L, R;
    cin >>L;
    cout<<"Enter the query end ";
    cin>>R;
    
    int j = (int)log2(R - L + 1); 
    cout<<"The element is : ";
    if (sparsetable[L][j] <= sparsetable[R - (1 << j) + 1][j]) 
        cout<< sparsetable[L][j]; 
    else
        cout<<sparsetable[R - (1 << j) + 1][j];
     

    return 0; 
} 
//INPUT:Enter the number of elements :
//9
//Enter the elements:
//1
//2
//3
//4
//5
//6
//7
//8
//9
//Enter the query start 2
//Enter the query end 7
//OUTPUT:The element is : 3 
