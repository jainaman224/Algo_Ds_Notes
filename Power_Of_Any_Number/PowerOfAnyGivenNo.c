#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPowerOfGivenNo(int number, int base) {
    if(number == 0)
    {
        //0 power anything is 0
        if(base == 0)
            return true;

        //0 is not the power of any number
        return false;
    }

    //explicitly check for 1 because log(1) = 0
    if(base == 1)
    {
        if(number == 1)
            return true;
        else
            return false;
    }

    // -8 cannot be power of 2 but can be power of -2
    if( number < 0 && base > 0)
        return false;

    //converting to positive
    number = abs(number);
    base = abs(base);

    float logValue = (float) ( log(number)/log(base)) ;
    return logValue == floor(logValue);
}


// driver program
int main()
{
    int number, base;
    printf( "Enter a no.: " ) ;
    scanf( "%d", &number );
    printf( "Check for which no.? " ) ;
    scanf( "%d", &base);
    if( isPowerOfGivenNo(number, base) )
        printf( "Yes %d is a power of %d", number, base );
    else
         printf( "No %d is not a power of %d", number, base );

    return 0;
}

/* SAMPLE INPUT OUTPUT
 * Input :
 	Enter a no. : -8
	Check for which no. ? -2

 * Output :
	Yes -8 is a power of -2
 * */
