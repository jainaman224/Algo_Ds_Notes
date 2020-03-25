#include<iostream>
#include<cmath>
using namespace std;
// approximation limit
#define error 0.0001

//function of the polynomial is inputted here say f(x) = x*x - 2*x + 1
float polynomial(float x)
{
    return x * x - 4 * x + 3;
}

float mid(float q, float w)
{
    return (q + w) / 2;
}

int main()
{
    int i;
    float lower_bound, upper_bound, a, b;

    cout << "For the interval (a, b) where the root may lie : " << endl;
    cout << "Enter the value of a :- " << endl;
    cin >> lower_bound;

    a = lower_bound;

    cout << "Enter the value of b :- " << endl;
    cin >> upper_bound;

    b = upper_bound;

    if(polynomial(lower_bound) * polynomial(upper_bound) > 0)
    {
        cout << "Invalid interval" << endl;
    }
    else
    {   
        // repeat until the required accuracy is obtained
        while(abs(polynomial(mid(lower_bound, upper_bound))) > error)
        {
            cout << "\nIteration_no = " << i << " , First_no = " << lower_bound 
            << " , Second_no = " << upper_bound << " middle = " 
            << mid(lower_bound, upper_bound) ;
            cout << " , f(middle) = " << polynomial(mid(lower_bound, upper_bound))
            << " , f(first_no)*f(middle) = " 
            << polynomial(lower_bound)*polynomial(mid(lower_bound, upper_bound)) << endl;
            // sign changes in the first interval => root lies in the 1st interval
            if(polynomial(lower_bound) * polynomial(mid(lower_bound, upper_bound)) < 0)
            {
                upper_bound = mid(lower_bound, upper_bound);
            }
            else
            {
                lower_bound = mid(lower_bound, upper_bound);
            }
            i++;
        }
        cout << "\nIteration_no = " << i << " , First_no = " << lower_bound 
        << " , Second_no = " << upper_bound << " middle = " << mid(lower_bound, upper_bound) ;
        cout << " , f(middle) = " << polynomial(mid(lower_bound, upper_bound)) 
        << " , f(first_no)*f(middle) = " 
        << polynomial(lower_bound)*polynomial(mid(lower_bound, upper_bound)) << endl;
        cout << "\nThe approximated root of the given polynomial within the specified interval ("
        << a << " , " << b << ") = " ;
        cout << mid(upper_bound, lower_bound) << endl;
    }
    return 0;
}

/* OUTPUT
For the interval (a, b) where the root may lie : 
Enter the value of a :-
2.1
Enter the value of b :-
4.1

Iteration_no = 0 , First_no = 2.1 , Second_no = 4.1 middle = 3.1 , f(middle) = 0.21 ,
f(first_no)*f(middle) = -0.2079

Iteration_no = 1 , First_no = 2.1 , Second_no = 3.1 middle = 2.6 , f(middle) = -0.64 ,
f(first_no)*f(middle) = 0.6336

Iteration_no = 2 , First_no = 2.6 , Second_no = 3.1 middle = 2.85 , f(middle) = -0.2775 ,
f(first_no)*f(middle) = 0.1776

Iteration_no = 3 , First_no = 2.85 , Second_no = 3.1 middle = 2.975 , f(middle) = -0.0493755 ,
f(first_no)*f(middle) = 0.0137017

Iteration_no = 4 , First_no = 2.975 , Second_no = 3.1 middle = 3.0375 , f(middle) = 0.0764065 ,
f(first_no)*f(middle) = -0.00377261

Iteration_no = 5 , First_no = 2.975 , Second_no = 3.0375 middle = 3.00625 , f(middle) = 0.0125389 ,
f(first_no)*f(middle) = -0.000619115

Iteration_no = 6 , First_no = 2.975 , Second_no = 3.00625 middle = 2.99062 , f(middle) = -0.0186625 ,
f(first_no)*f(middle) = 0.000921469

Iteration_no = 7 , First_no = 2.99062 , Second_no = 3.00625 middle = 2.99844 , f(middle) = -0.00312233 ,
f(first_no)*f(middle) = 5.82703e-005

Iteration_no = 8 , First_no = 2.99844 , Second_no = 3.00625 middle = 3.00234 , f(middle) = 0.00469303 ,
f(first_no)*f(middle) = -1.46532e-005

Iteration_no = 9 , First_no = 2.99844 , Second_no = 3.00234 middle = 3.00039 , f(middle) = 0.000781059 ,
f(first_no)*f(middle) = -2.43872e-006

Iteration_no = 10 , First_no = 2.99844 , Second_no = 3.00039 middle = 2.99941 , f(middle) = -0.00117207 ,
f(first_no)*f(middle) = 3.65958e-006

Iteration_no = 11 , First_no = 2.99941 , Second_no = 3.00039 middle = 2.9999 , f(middle) = -0.000195503 ,
f(first_no)*f(middle) = 2.29143e-007

Iteration_no = 12 , First_no = 2.9999 , Second_no = 3.00039 middle = 3.00015 , f(middle) = 0.000292778 ,
f(first_no)*f(middle) = -5.7239e-008

Iteration_no = 13 , First_no = 2.9999 , Second_no = 3.00015 middle = 3.00002 , f(middle) = 4.86374e-005 ,
f(first_no)*f(middle) = -9.50877e-009

The approximated root of the given polynomial within the specified interval (2.1, 4.1) = 3.00002
*/