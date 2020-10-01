/* Girlscript Summer Of Code
Regula Falsi Method in c
In mathematics, the false position method or regula falsi is a very old method for solving an equation in one unknown,
that, in modified form, is still in use. In simple terms, the method is the trial and
error technique of using test ("false") values for the variable and then adjusting the test value according
to the outcome. This is sometimes also referred to as "guess and check".
Versions of the method predate the advent of algebra and the use of equations.*/

#include<stdio.h>
#include<math.h>

float f(float x) {
    return ((x * x * x) - (2 * x) - 5);
}

int main() {
    float x1, x2, x3, f1, f2, f3;
    int i;
    printf("Enter x1 and x2:");
    scanf("%f %f", &x1, &x2);
    do {
        f1 = f(x1);
        f2 = f(x2);
        x3 = x1 - (x2 - x1) / (f2 - f1) * f1;
        f3 = f(x3);
        if (f1 * f3 > 0) {
            x2 = x3;
        }
        else {
            x1 = x3;
        }
        i++;
        printf("Number of iteration %d\t root is %f\n", i, x3);
    } while (fabs(f3) > 0.001);
}

//Enter x1 and x2:2
//3
//Number of iteration 21985	 root is 2.058824
//Number of iteration 21986	 root is 2.096559
//Number of iteration 21987	 root is 2.094511
