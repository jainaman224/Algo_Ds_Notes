/*
POWER SET

A power set of a set is the set of all possible subsets of 
a given set S. 
example - {a, b, c} :
Power Set = {}, {a}, {b}, {c}, {a, b}, {a, c},  {a, b}, {b, c}, 
            {a, b, c}

Total elements in a power set of a set with n elements = 2^n
*/

#include<bits/stdc++.h>
using namespace std;

void PowerSet(int a[], int b[], int n, int index) {
    if (index == n) {
        cout << "{";
        for (int i = 0; i < n; i++) {
            if (b[i] == 1) {
                cout << a[i] << " ";
            }
        }
        cout << "}" << endl;
        return;
    }
    PowerSet(a, b, n, index + 1);
    b[index] = 1;
    PowerSet(a, b, n, index + 1);
    b[index] = 0;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = 0;
    }
    PowerSet(a, b, n, 0);
}

/*
INPUT : n = 3
        a = [3, 15, 32]
OUTPUT :
{}
{32 }
{15 }
{15 32 }
{3 }
{3 32 }
{3 15 }
{3 15 32 }
*/
