/*
PYTHAGOREAN QUADRUPLES

Four numbers - a, b , c and d are said to be pythagorean quadruples if following
formula holds :

a^2 + b^2 + c^2 = d^2
*/

#include<stdio.h>

int main() {
    int a, b, c, d;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);
    printf("Enter d: ");
    scanf("%d", &d);
    int sq_a = a * a;
    int sq_b = b * b;
    int sq_c = c * c;
    int sq_d = d * d;
    if (sq_a + sq_b + sq_d == sq_c || sq_a + sq_c + sq_d == sq_b 
    || sq_b + sq_c + sq_d == sq_a || sq_a + sq_b + sq_c == sq_d) {
        printf("It is a pythagorean quadruple");
    }
    else {
        printf("It is not a pythagorean quadruple");
    }
}

/*
    INPUT : a = 3 b = 6 c = 2 d = 7
    OUTPUT: It is a pythagorean quadruple
    VERIFICATION : 3^2 + 6^2 + 2^2 = 9 + 36 + 4 = 49
                   7^2 = 49
*/
