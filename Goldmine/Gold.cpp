#include <bits/stdc++.h>
using namespace std;

int GoldMine(int **arr, int n, int m)
{
    //DP table
    int DP[n][m];

    memset(DP, 0, sizeof(DP));

    for (int i = 0; i < n; i++)
        DP[i][0] = arr[i][0];

    //for every column
    for (int j = 1; j < m; j++)
    {
        //check which option is better accordingly
        for (int i = 0; i < n; i++)
        {
            //choosing max of possible moves
            DP[i][j] = arr[i][j];
            int val = DP[i][j - 1];
            if (i - 1 >= 0)
            {
                if (val < DP[i - 1][j - 1])
                    val = DP[i - 1][j - 1];
            }
            if (i + 1 < n)
            {
                if (val < DP[i + 1][j - 1])
                    val = DP[i + 1][j - 1];
            }
            DP[i][j] += val;
        }
    }
    // find the maximum of the last column
    int gold = DP[0][m - 1];
    for (int i = 1; i < n; i++)
    {
        if (DP[i][m - 1] > gold)
            gold = DP[i][m - 1];
    }

    return gold;
}

int main()
{
    int n, item, m;

    cout << "Enter matrix dimensions, m & n\n";
    cin >> n >> m;

    cout << "Input matrix cells\n";
    int **arr = (int **)(malloc(sizeof(int *) * n));

    //input array
    for (int j = 0; j < n; j++)
    {
        arr[j] = (int *)(malloc(sizeof(int) * m));
        for (int k = 0; k < m; k++)
            cin >> arr[j][k];
    }

    cout << "Max amount of gold that can be collected: " << GoldMine(arr, n, m) << endl;

    return 0;
}

/*Output

Enter matrix dimensions, m & n
3 3
Input matrix cells
5 4 2
1 4 2
1 7 3
Max amount of gold that can be collected: 12*/