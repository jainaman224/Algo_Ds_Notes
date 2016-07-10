// A Dynamic programming solution for Rod Cutting problem 

#include <iostream>
#include <limits.h>
#include <stdio.h>
using namespace std;

//a fxn for calculating max of two nos.
int max(int a,int b)
{   
	return (a>b)?a:b;
}
// returns the max obtainable cost
int CutRod(int cost[],int n)
{   int val[n+1],i,j;
     val[0]=0;
    
     for (i=1;i<=n;i++)
     { int max_value=INT_MIN;
       for(j=0;j<i;j++)
        max_value=max(max_value,cost[j]+val[i-j-1]);
        val[i]=max_value;
     }
     return val[n];
     
}

// driver fxn
int main() {
	int arr[]={3,5,8,9,10,17,17,20};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum value is "<<CutRod(arr,size)<<endl;
	getchar();
	return 0;
}



/*OUTPUT
Maximum value is 24 */