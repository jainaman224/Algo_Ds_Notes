/*
    Minimum_Inversions:
    Given a binary array a[] of size num.
    The task is to find the minimum number of
    inversions required so that no two adjacent elements are same.
*/
#include <bits/stdc++.h>
using namespace std;
/*
    Function to return the minimum inversions required so that no
    two adjacent elements are same
*/
int min_changes(int a[], int n)
{
/*
    There are only two possibilities to make
    the array {1, 0, 1, 0, 1, 0, 1, …} or {0, 1, 0, 1, 0, 1, 0, …}.
    Let ans_a and ans_b be the count of
    changes required to get these arrays respectively.
    Now, the final answer will be min(ans_a, ans_b).
*/
    int ans_a = 0, ans_b = 0;

    // Find all the changes required

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (a[i] == 0)
            {
                ans_a ++;
            }
            else
            {
                ans_b ++;
            }
        }
        else
        {
            if (a[i] == 0)
            {
                ans_b ++;
            }
            else
            {
                ans_a ++;
            }
        }
    }

    return min(ans_a, ans_b);
}


int main()
{
    int num;
    cout << "Enter number of elements in your array: " ;
    cin >> num;
    int a[num];
    cout << "Enter your array: " ;
    for (int i = 0; i < num; i++)
    {
    cin >> a[i];
    }

    cout << "Minimum changes required : " << min_changes(a, num);

    return 0;

}
/*
   Input : num = 8
   Array = [1, 0, 1, 1, 0, 1, 1, 1]
   Output :
   Minimum changes required : 4
*/

