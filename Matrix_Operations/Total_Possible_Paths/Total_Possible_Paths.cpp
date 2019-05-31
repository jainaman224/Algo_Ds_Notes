/*
TOTAL PATHS FROM (0, 0) to (m, n)

The task is to calculate total possible moves we can make to reach
(m, n) in a matrix, starting from origin, given that we can only take
1 step towards right or up in a single move.
*/

#include<bits/stdc++.h>
using namespace std;

int totalPaths(int m, int n) {
    int total[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total[i][j] = 0;
        }
    }
    int mx = (m > n) ? (m) : (n);
    for (int i = 0; i < mx; i++) {
        if (i < m) {
            total[i][0] = 1;
        }
        if (i < n) {
            total[0][i] = 1;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            total[i][j] = total[i - 1][j] + total[i][j - 1];
        }
    }
    return total[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << "The total paths are " << totalPaths(m, n);
}

/*
INPUT :
n = 6
m = 5
OUTPUT :
The total paths are 126
*/
