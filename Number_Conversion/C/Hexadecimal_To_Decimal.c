#include<stdio.h> 
#include<string.h> 
 
int main() 
{ 
    char hexa[100];
    scanf("%s", &hexa);
    int lenght = strlen(hexa); 

    int base = 1; 

    int decimal = 0; 

    for (int i = lenght-1; i >= 0; i--) 
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
    printf("%d", decimal);	
} 

/*
Inout:
A
Output:
10
*/

