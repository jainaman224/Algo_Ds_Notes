// Program to approximate number of people in Birthday Paradox problem

#include <cmath>
#include <iostream>
using namespace std;

// Returns approximate number of people for a given probability
int find(double p)
{
    return ceil(sqrt(2*365*log(1/(1-p))));
}

int main()
{
    printf("%d",find(0.70));
}

/* Output
3o
*/
