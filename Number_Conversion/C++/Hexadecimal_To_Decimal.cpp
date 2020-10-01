
#include<iostream> 
#include<string.h> 
using namespace std; 
 
int main() 
{ 
    char hexa[100];
    cin>>hexa;
    int lenght = strlen(hexa); 

    int base = 1; 

    int decimal = 0; 

    for (int i = lenght - 1; i >= 0; i--) 
    { 
        if (hexa[i] >= '0' && hexa[i] <= '9') 
        { 
            decimal += (hexa[i] - 48) * base; 
            base = base * 16; 
        } 
        else if (hexa[i] >= 'A' && hexa[i] <= 'F') 
        { 
            decimal += (hexa[i] - 55) * base; 
            base = base * 16; 
        }
        else if (hexa[i] >= 'a' && hexa[i] <= 'f') 
        { 
            decimal += (hexa[i] - 87) * base; 
            base = base * 16; 
        } 
    }
    cout<<decimal;	
} 

/*
Inout:
A
Output:
10
*/
