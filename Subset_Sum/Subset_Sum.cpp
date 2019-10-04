/* 
    Subset Sum Problem: Given an array of elements and a sum,
    is it possible to form the given sum using some or all of the
    elements of array i.e using any subset of given array.
    Example: 1, 7, 3, 5, 6 and sum = 14, it is possible to
    obtain the sum 14 by taking the elements 1, 7 and 6 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to compute whether a subset of array exists
// having the given sum
bool subsetSum(ll arr[], ll size, ll sum) 
{
    // A 2D Matrix containing boolean values, true and false
    bool dp[size + 1][sum + 1];

    /* Any entry of dp matrix dp[i][j] tells us that taking 
    the elements 1....i can we make the sum j, this is the 
    optimal substructure of this Dynamic Programming Problem.
    At every step, we have the option of either including the
    element in the subset to form the given sum, or we exclude
    it and keep the previous set chosen in our answer */
    for (ll i = 0; i <= size; i++) 
    {
        for (ll j = 0; j <= sum; j++) 
        {
            // We cannot form a sum j by taking no elements
            if (i == 0)
                dp[0][j] = false;

            // We can always form the sum 0
            if (j == 0)
            // by taking 0 instance of the element
                dp[i][0] = true;
            
            if (i > 0)
            {
                /* when the value of current element is less than the 
                sum j, we have two options, either take it and include
                the element in answer or leave it and take the previous
                best given by dp[i-1][j], when the value of sum j is less
                than the element i, we cannot include this element and
                hence take the previous best */
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
   
    /* The last entry in table gives the answer
    by evaluating all the elements of array to 
    compute the required sum */
    return dp[size][sum];
}

// Driver function
int main() 
{
    ll size;
    cout << "Enter size of array" << endl;
    cin >> size;

    ll arr[size];
    cout << "Enter elements of array" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    ll sum;
    cout << "Enter sum" << endl;
    cin >> sum;

    // Call to SubsetSum function
    bool ans = subsetSum(arr, size, sum);

    // if ans evaluates to false, no such subset present
    // if ans evaluates to true , subset with given sum present
    if (ans == false)
        cout << "No subset adds upto the given sum" << endl;
    else
        cout << "Subset with given sum present" << endl;
        return 0;
}

/*
    Input:
    size = 7
    arr = {2, 3, 5, 1, 6, 8, 7}
    sum = 12

    Output:
    Subset with given sum present
    
    Input:
    size = 4
    arr = {2, 3, 5, 1}
    sum = 12

    Output:
    No subset adds upto the given sum
*/
