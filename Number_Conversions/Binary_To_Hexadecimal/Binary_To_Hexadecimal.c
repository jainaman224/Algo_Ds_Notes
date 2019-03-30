// C Program to Convert Binary to Hexadecimal 

#include <stdio.h>
int main()

{
    long int binary_value, hexadecimal_value = 0, i = 1, remainder;
    printf("Enter the binary number: ");
    scanf("%ld", &binary_value);
    while (binary_value != 0)
    {
        remainder = binary_value % 10;
        hexadecimal_value = hexadecimal_value + remainder * i;
        i = i * 2;
        binary_value = binary_value / 10;
    }
    printf("%lX", hexadecimal_value);
    return 0;
}

//Output
//Enter the binary number: 1101010
//6A
