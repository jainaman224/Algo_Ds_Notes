#include <stdio.h>

//function to find minimum number such that num%divisor[i] gives corresponding remainder[i] 
void minresult( int divisor[], int rem[], int size)
{
    //each number starting from 1 is checked for minimum value
    int res = 1, i = 0;
    do
    {  
        if((res%divisor[i]) == rem[i])
        {
 // When value of i is equal to value of size i.e. all remainder matches with given rem[] array, then res is the minimum value
            i++ ;
        }
        else
        {    //if above condition gives false for any value of i, check for next number.
            res++ ;
            i = 0; 
        }
        
    }while(i < size);
    printf("Answer is: %d", res); //display result.
    
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
    minresult( divisor, rem, size);
    return 0;
}

/*Sample input-output:

Enter size of array:4
Enter value of coprime divisors:2 3 5 7
Enter value of remainders:1 2 3 4
Answer is: 53*/


















