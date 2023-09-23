//This Code is used to find factorial.

#include <iostream>

using namespace std;
int main() 
{
    int t, n, a[200000], i, j, k, l, m;
    cout << "ENTER THE NUMBER\n";
    cin >> n;
    m = 1;
    a[0] = 1;

    // Code to find the factorial
    for (j = 2; j <= n; j++) 
    {
        l = 0;
        for (k = 0; k < m; k++) 
        {
            a[k] = a[k] * j + l;
            l = a[k] / 10;
            a[k] = a[k] % 10;
        }

        // Code to break a number having more than one digit into array of single
        // digits
        while (l) 
        {
            a[k] = l % 10;
            k++;
            m++;
            l = l / 10;
        }
    }
    printf("Answer is : ");
    for (i = m - 1; i >= 0; i--)
        cout << a[i];
    return 0;
}

/*ENTER THE NUMBER
5
Answer is : 120*/
