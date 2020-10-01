#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#include <bits/stdc++.h>

using namespace std;
#define N 51
int arr[N][N], I[N][N];

void multiply(int A[][N], int B[][N], int dim) {
    int result[dim + 1][dim + 1];

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < dim; ++k)
            {
                result[i][j] += (A[i][k] * B[k][j]) % 1000000007;
            }
        }
    }

    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            A[i][j] = result[i][j];
        }
    }
}
void power(int A[][N], int dim, int n) {
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            if (i == j) I[i][j] = 1;
            else       I[i][j] = 0;
        }
    }

    // for (int i = 0; i < dim; ++i)
    // {
    //     multiply(I, A, dim);
    // }

    while (n) {
        if (n % 2) {
            multiply(I, A, dim);
            n--;
        } else {
            multiply(A, A, dim);
            n /= 2;
        }
    }
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            A[i][j] = I[i][j];
        }
    }
}

void printMat(int A[][N], int dim) {
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int dim, n;
        cin >> dim >> n;

        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                cin >> arr[i][j];
            }
        }
        power(arr, dim, n);
        // multiply()
        printMat(arr, dim);
    }

    return 0;
}

