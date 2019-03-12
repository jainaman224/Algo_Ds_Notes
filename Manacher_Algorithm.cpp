#include <stdio.h> 
#include <string.h> 
#include<bits/stdc++.h>
using namespace std; 

int min(int a, int b) 
{ 
    int res = a; 
    if(b < a) 
        res = b; 
    return res; 
} 
int main() 
{ 	
	char text[100]; 
    cout<<"Enter the string:\n";
    cin>>text; 
    int N = strlen(text); 
    N = 2*N + 1; //count the next position
    int L[N]; //array to store longest palindrome length
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int j; //currentLeftPosition 
    int plength = 0; //maximum length of palindrome
    int x = 0; //maxLPSCenterPosition
    int start = -1; 
    int end = -1; 
    int diff = -1; 
     
    for (i = 2; i < N; i++)  
    { 
        
        j  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        
        if (diff > 0) 
            L[i] = min(L[j], diff); 
  
        
        while (((i + L[i]) < N && (i - L[i]) > 0) &&( ((i + L[i] + 1) % 2 == 0) ||(text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        	{ 
            	L[i]++; 
        	} 
  
        if(L[i] > plength)   
        { 
            plength = L[i]; 
            x = i; 
        } 
  
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        
    } 
    
    start = (x- plength)/2; 
    end = start + plength - 1; 
    cout<<"LPS of string is : ";
    
    for(i=start; i<=end; i++) 
        cout<< text[i]; 
    cout<<"\n"; 
    
  
    return 0; 
} 
