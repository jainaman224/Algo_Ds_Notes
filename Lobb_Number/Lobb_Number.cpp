// CPP Program to find Ln, m Lobb Number.
#include <bits/stdc++.h>
#define MAXN 109
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];

    // Calculate value of Binomial Coefficient in
    // bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously stored values
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

// Return the Lm, n Lobb Number.
int lobb(int n, int m)
{
    return ((2 * m + 1) * binomialCoeff(2 * n, m + n)) / (m + n + 1);
}

// Driven Program
int main()
{
    int n, m;
    cout << "Enter n and m\n";
    cin >> n >> m;
    cout << lobb(n, m) << endl;
    return 0;
}

/*Output

Enter n and m
5 3
35*/