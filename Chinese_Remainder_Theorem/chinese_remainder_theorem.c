#include <stdio.h>

//function to find minimum number such that num%divisor[i] gives corresponding remainder[i] 
int minresult( int divisor[], int rem[], int size)
{
    int m = 1, M[size], inv[size], i, k, count, x = 0;
    for(i = 0; i < size; i++)
    {
        m = m * divisor[i];
    }
    for(i = 0; i < size; i++)
    {
        M[i] = m / divisor[i];
    }
    for(i = 0; i < size; i++)
    {   
        count = 0;
        k = 1;
        do
        {
            if(((M[i] % divisor[i]) *  k) % divisor[i] == 1)
            {
                inv[i] = k;
                count++;
            } 
            k++; 
        }while(count == 0);  
    }
    for(i = 0; i < size; i++)
    {
        x = x + (rem[i] * M[i] * inv[i]); //according to CRT
    }
    x = x % m;
    return x; 
}

int main()
{
    int size, i, divisor[100], rem[100];
    //input size of array in variable size
    printf("Enter size of array:");
    scanf("%d", &size);
    //input divisor values and then remainder values
    printf("Enter value of coprime divisors:");
    for(i = 0; i < size; i++ )
    {
        scanf("%d", &divisor[i]);
    }
    printf("Enter value of remainders:");
    for(i = 0; i < size; i++ )
    {
        scanf("%d", &rem[i]);
    }
    //function call to find result.
    printf("Answer is: %d ", minresult( divisor, rem, size));
    return 0;
}

/* Sample input-output:
Enter size of array:3
Enter value of coprime divisors:2 3 5
Enter value of remainders:1 2 4
Answer is: 29
*/
