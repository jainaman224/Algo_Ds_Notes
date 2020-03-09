/*
SIMPLE INTEREST

Simple Interest in Accounting is calculated as :

S.I. = (p * r * t) / 100
where p = principal amount
      r = rate of interest
      t = time
*/

#include<stdio.h>

int main() {
    float p, r, t;
    printf("Enter Principal: ");
    scanf("%f", &p);
    printf("Enter Rate: ");
    scanf("%f", &r);
    printf("Enter Time: ");
    scanf("%f", &t);
    printf("Simple Interest is: %0.2f", (p * r * t) / 100);
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : Simple Interest is: 160.00
*/
