#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h> 
using namespace std; 
  
int block; 
struct Query 
{ 
    int start;
    int end; 
}; 
  

bool compare(Query a, Query b) ;
void queryResults(int arr[], int size, Query q[], int no) ; 
  
int main() 
{   
  int size,i; 
  cout<<"Enter the size of the array ";
  cin>>size;
  int arr[size];
  cout<<"Enter the elements ";
  for ( i=0;i<size;i++)
     cin>>arr[i] ; 
  int no;
  cout<<"Enter the numbers of query ";
  cin>>no;
     
  Query q[no];
  for (i=0 ;i<no;i++)
   {
      cout<<"Enter the start of the query ";
      cin>>q[i].start;
      cout<<"Enter the end of the query ";
      cin >>q[i].end;
   } 
   
  queryResults(arr, size, q, no); 
  return 0; 
} 

bool compare(Query a, Query b) 
{ 
   if (a.start/block != b.start/block) 
      return a.start/block <b.start/block; 
   return a.end < b.end; 
}

void queryResults(int arr[], int size, Query q[], int no) 
{ 
   block = (int)sqrt(size); 
   sort(q, q + no, compare); 
   int currentstart = 0, currentend = 0; 
   int currentsum = 0; 
   for (int i=0; i<no; i++) 
     { 
        int start = q[i].start, end = q[i].end; 
        while (currentstart < start) 
        { 
            currentsum -= arr[currentstart]; 
            currentstart++; 
        } 
        while (currentstart > start) 
        { 
            currentsum += arr[currentstart-1]; 
            currentstart--; 
        } 
        while (currentend <= end-1) 
        { 
            currentsum += arr[currentend]; 
            currentend++; 
        } 
        while (currentend > end) 
        { 
            currentsum -= arr[currentend-1]; 
            currentend--; 
        } 
        cout << "Sum of [" << start << ", " << end 
             << "] is "  << currentsum << endl; 
    } 
}
//INPUT:Enter the size of the array 5
//Enter the elements 1
//2
//3
//4
//5
//Enter the numbers of query 2
//Enter the start of the query 0
//Enter the end of the query 3
//Enter the start of the query 2
//Enter the end of the query 4
//Sum of [0, 3] is 6
//Sum of [2, 4] is 7
