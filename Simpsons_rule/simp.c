// Simpson's rule  in c
//this is used to find integration 
//It is used when it is very difficult to solve the given integral mathematically.
//This rule gives approximation easily without actually knowing the integration rules.

#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x);
float f(float x) {
    return (x);
}

int main() {
    int a, b, n, i;
    float s1 = 0, s2 = 0, sum, h;
    printf("Enter the value of upper limit = ");
    scanf("%d", &b);
    printf("Enter the value of lower limit = ");
    scanf("%d", &a);
    printf("Enter the number of intervals = ");
    scanf("%d", &n);
    h = fabs(b - a) / n;
    if (n % 2 == 0) {
        for (i = 1; i <= n - 1; i++) {
            if (i % 2 == 0) {
                s1 = s1 + f(a + i * h);
            } 
            else {
                s2 = s2 + f(a + i * h);
            }
        }
        sum = (h / 3) * (f(a) + f(b) + 4 * s2 + 2 * s1);
        printf("the value is=%f", sum);
    } 
    else {
        printf("Not appliciable! Interval must be even number");
    }
    getch();
}

 //output
//Enter the value of upper limit = 12
//Enter the value of lower limit = 0
//Enter the number of intervals = 4
//the value is=72.00000
