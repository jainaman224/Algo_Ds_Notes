/*
    Compound Interest = P(1 + R/100)^T
    
    P is principle amount
    R is the rate and
    T is the time span
*/

#include<stdio.h>
#include<math.h>

int main() {
    float p, r, t;
    printf("Enter Principal: ");
    scanf("%f", &p);
    printf("Enter Rate: ");
    scanf("%f", &r);
    printf("Enter Time: ");
    scanf("%f", &t);
    printf("%0.2f", p * (pow((1 + r / 100), t)));
}

/*
INPUT : p = 1000, r = 8, t = 2
OUTPUT : 1166.40
*/
