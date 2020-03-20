/* Girlscript Summer Of Code
Regula Falsi Method in C++
In mathematics, the false position method or regula falsi is a very old method
for solving an equation in one unknown,that, in modified form, is still in use.
In simple terms, the method is the trial and error technique of using test
("false") values for the variable andthen adjusting the test value according
to the outcome. This is sometimes also referred to as "guess and check".
Versions of the method predate the advent of algebra and the use of equations*/

#include<iostream>
#include<cmath>
// approximation error
#define error 0.001
using namespace std;

float polynomial(float x)    
{   
    // f(x) = x^3 -2*x -5
    return ( ( x * x * x ) - 3 * x - 5);
}

int main()
{
    float x1, x2, x3, f1, f2, f3 = INT_MAX;
    int i = 1;
    cout << "\nFor the interval (x1,x2) where the root is to be searched- \n";
    cout << "Enter x1 and x2 : " << endl;
    cin >> x1 >> x2;
    
    while(abs(f3) > error)
    {   
        f1 = polynomial(x1);
        f2 = polynomial(x2);
        x3 = x1 - (x2 - x1) / (f2 - f1) * f1 ;
        f3 = polynomial(x3);

        if (f1 * f3 > 0)
        {
            x2 = x3;
        }
        else 
        {
            x1 = x3;
        }
        cout << "\nThe no. of iteration : " << i << " root is : " << x3 << endl;
        i++;
    }
    cout << "\nThe approximated root of the polynomial that lies in the given interval is : ";
    cout << x3 << endl;
    return 0;
}

/*
OUTPUT
For the interval (x1,x2) where the root is to be searched-
Enter x1 and x2 :
2 3

The no. of iteration : 1 root is : 2.1875

The no. of iteration : 2 root is : 2.29527

The no. of iteration : 3 root is : 2.27819

The no. of iteration : 4 root is : 2.27906

The approximated root of the polynomial that lies in the given interval is : 2.27906
*/