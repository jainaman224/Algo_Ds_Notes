#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    char hexa[100];
    cin>>hexa; 

    int i = 0; 

    while (hexa[i])
    { 
        switch (hexa[i]) 
        { 
            case '0': 
                cout<<"0000"; 
                break; 
            case '1': 
                cout<<"0001"; 
                break; 
            case '2': 
                cout<<"0010"; 
                break; 
            case '3': 
                cout<<"0011"; 
                break; 
            case '4': 
                cout<<"0100"; 
                break; 
            case '5': 
                cout<<"0101"; 
                break; 
            case '6': 
                cout<<"0110"; 
                break; 
            case '7': 
                cout<<"0111"; 
                break; 
            case '8': 
                cout<<"1000"; 
                break; 
            case '9': 
                cout<<"1001"; 
                break; 
            case 'A': 
            case 'a': 
                cout<<"1010"; 
                break;  
            case 'B': 
            case 'b': 
                cout<<"1011"; 
                break; 
            case 'C': 
            case 'c': 
                cout<<"1100"; 
                break; 
            case 'D': 
            case 'd': 
                cout<<"1101"; 
                break; 
            case 'E': 
            case 'e': 
                cout<<"1110"; 
                break; 
            case 'F': 
            case 'f': 
                cout<<"1111"; 
                break; 
        } 
        i++;
    }
    return 0; 
} 

/*
INPUT:
a
Output:
1010
*/
