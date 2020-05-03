//median of two sorted arrays -
#include<iostream>
#include<cmath>
using namespace std;

float median(int *arr1, int * arr2, int n, int m)
{
    int low1 = 0,
        hi1 = n - 1,
        low2 = 0,
        hi2 = m - 1;
    while (true)
    {
        int m1 = (hi1 - low1) / 2,
            m2 = (hi2 - low2) / 2,
            median1 = arr1[m1],
            median2 = arr2[m2];
        if (hi1 - low1 <= 1 || hi2 - low1 <= 1)
        {
            //calculate the median
            float leftVal = max(arr1[low1], arr2[low2]);
            float rightVal = min(arr1[hi1], arr2[low2]);
            float ans = (abs(n-m) >= 1) ? ceil((leftVal + rightVal)/2) : (leftVal + rightVal)/2;
            return (float) ans;
        }
        if (median1 == median2)
        {
            return median1;
        }
        else if (median2 > median1)
        {   //Shift the lower pointer of array 1 to median 1
            low1 = m1;
            //Shift the Higher pointer of array 2 to median 2
            hi2 = m2;
        }
        else {
            //Shift the Higher pointer of array 1 to median 1
            hi1 = m1;
            //Shift the Lower pointer of array 2 to median 2
            low2 = m2;
        }

    }
}

int main()
{
    int n, m, arr1[100005], arr2[100005];
    cout << "Enter size of Array 1 \n";
    cin >> n;
    cout << "Enter size of Array 2 \n";
    cin >> m;
    cout << "Enter Elements of Array 1 \n";
    for (int i = 0; i < n; i++) cin >> arr1[i];
    cout << "Enter Elements of Array 2 \n";
    for (int i = 0; i < m; i++) cin >> arr2[i];
    cout << "Median of Combined Sorted Array is " << median(arr1, arr2, n, m);
    cout << endl;
    return 0;
}

/* Sample Input
 Enter size of Array 1
    3
 Enter size of Array 2
    3
Enter Elements of Array 1
    1 2 3
Enter Elements of Array 1
    4 5 6

Sample Output
Median of Combined Sorted Array is - 3.5
 */