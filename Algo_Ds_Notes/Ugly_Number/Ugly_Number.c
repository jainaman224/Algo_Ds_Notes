//Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

# include <stdio.h>
# include <stdbool.h>

int main()
{
    int num ;
    bool x = false ;
 
    printf ( "Input an integer number: " ) ;
    scanf ( "%d" , &num );

    while (num != 1) 
    {  
        if (num % 5 == 0) //To check if number is divisible by 5 or not
        {  
            num /= 5;  
        } 
        else if (num % 3 == 0) //To check if number is divisible by 3 or not 
        {  
            num /= 3;  
        } 
        else if (num % 2 == 0) //To check if number is divisible by 2 or not
        {  
            num /= 2;  
        } 
        else 
        {  
            printf("It is not an ugly number.\n"); 
            x = true; //Flag updated 
            break;  
        }  
    } 
    if ( !x )
    { 
        printf("It is an ugly number.\n");
    }
    return 0;
}

/*Input an integer number: 6
It is an ugly number.*/
