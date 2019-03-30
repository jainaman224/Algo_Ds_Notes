//CPP program for binary to hexadecimal conversion
#include <iostream>
#include <math.h>
using namespace std;
 
int main()
{
    int hex[1000];
    int i = 1, j = 0, rem, dec = 0, binary_Number;
	cout << " Input a binary number: ";
	cin>> binary_Number;
    while (binary_Number > 0) 
    {
        rem = binary_Number % 2;
        dec = dec + rem * i;
        i = i * 2;
        binary_Number = binary_Number / 10;
    }
    i = 0;
    while (dec != 0)
    {
        hex[i] = dec % 16;
        dec = dec / 16;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] > 9) 
        {
            cout<<(char)(hex[j] + 55);
        } 
         else
        {
            cout<<hex[j];
        }
    }
}

//OUTPUT
// Input a binary number: 1101010
// 6A
