/*
PYTHAGOREAN TRIPLETS

Three numbers - a, b and c are said to be pythagorean triplets if following
formula holds :

a^2 + b^2 = c^2
*/

#include<stdio.h>

int main() {
    int a, b, c;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Enter c: ");
    scanf("%d", &c);
    int sq_a = a * a;
    int sq_b = b * b;
    int sq_c = c * c;
    if (sq_a + sq_b == sq_c || sq_a + sq_c == sq_b || sq_b + sq_c == sq_a) {
        printf("It is a pythagorean triplet");
    }
    else {
        printf("It is not a pythagorean triplet");
    }
}

/*
    INPUT : a = 8 b = 6 c = 10
    OUTPUT: It is a pythagorean triplet
    VERIFICATION : 6^2 + 8^2 = 36 + 64 = 100
                   10^2 = 100
*/
