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
    int center = 1; //centerPosition  
    int right = 2; //centerRightPosition 
    int currentright = 0; //currentRightPosition 
    int currentleft; //currentLeftPosition 
    int plength = 0; //maximum length of palindrome
    int x = 0; //maxLPSCenterPosition
    int start = -1; 
    int end = -1; 
    int diff = -1; 
     
    for (currentright = 2; currentright < N; currentright++)  
    { 
        
        currentleft  = 2*center-currentright; 
        L[currentright] = 0; 
        diff = right - currentright; 
        
        if (diff > 0) 
            L[currentright] = min(L[currentleft], diff); 
  
        
        while (((currentright + L[currentright]) < N && (currentright - L[currentright]) > 0) &&( ((currentright + L[currentright] + 1) % 2 == 0) ||(text[(currentright + L[currentright] + 1)/2] == text[(currentright- L[currentright] - 1)/2] ))) 
        	{ 
            	L[currentright]++; 
        	} 
  
        if(L[currentright] > plength)   
        { 
            plength = L[currentright]; 
            x = currentright; 
        } 
  
        if (currentright + L[currentright] > right)  
        { 
            center = currentright; 
            right = currentright + L[currentright]; 
        } 
        
    } 
    
    start = (x- plength)/2; 
    end = start + plength - 1; 
    cout<<"LPS of string is : ";
    
    for(currentright=start; currentright<=end; currentright++) 
        cout<< text[currentright]; 
    cout<<"\n"; 
    
  
    return 0; 
} 
