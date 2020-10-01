/*A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if
abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... */

#include <stdio.h>
#include <math.h>

//To calculate the order of the number
int order(int num)
{
    int count;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

//Function to check if the number is armstrong or not
int armstrong(int num, int count)
{
    int sum = 0;
    while (num > 0)
    {
        //d is the remainder 
        d = num % 10;
        //To calculate sum
        sum += pow(d, count);        
        num /= 10;
    }
    return sum;
}

int main()
{
    int num, d;
    printf("Enter the number: ");
    scanf("%d", &num);
    
    int count = order(num);     

    int sum = armstrong(num, count);

    if (sum == n)
        printf("Armstrong number");
    else
        printf("Not an armstrong number");  

    return 0; 
}

/*Enter the number: 153
Armstrong number*/
