/*
    MINIMUM PRODUCT SUBSET OF AN ARRAY

    Given an array of n elements. We need to find the minimum product possible
    with any subset of that array.
*/

#include <bits/stdc++.h>
using namespace std;
#define lint long long int

lint neg = 0, pos = 0, zero = 0, prod = 1, max_neg = INT_MIN, min_pos = INT_MAX;

/*
    Approach : Two negative numbers multiply together to form a positive number.
               Hence, the minimum product in case of odd frequency of negative 
               numbers will be the product of entire array except zero.
               In case of even frequency of negative numbers, we exclude the 
               smallest negative number from the product of the array to get our
               answer.
               Also, in case of single negative number and no positive number in 
               the array, the answer would be the negative number itself.
*/
lint solve(lint temp[], lint num) {
    if (num == 1) {
        return temp[0];
    }
    if (zero == num || (neg == 0 && zero > 0)) {
        return 0;
    }
    if (pos == num) {
        return min_pos;
    }
    if (neg % 2 == 0 && neg > 0) {
        prod /= max_neg;
    }
    return prod;
}

int main(){
    lint num = 5;
    lint temp[num] = {5, -2, 4, -3, 1};
    for (lint i = 0; i < num; i++ ) {
        if (temp[i] > 0) {
            pos++;
            min_pos = min(min_pos, temp[i]);
        }
        else if (temp[i] == 0) {
            zero++;
            continue;
        }
        else {
            neg++;
            max_neg = max(max_neg, temp[i]);
        }
        prod = prod * temp[i];
    }
    lint ans = solve(temp, num);
    cout << "Minimum Product Subset is : " << ans;
    return 0;
}

/*
    Input: Array : [5, -2, 4, -3, 1]
    Output: Minimum Product Subset is : -60
    Verification: The product of array is 120. Since, there are even numbers of
                  negative numbers present in the array, we exclude the smallest
                  negative number (-2) from the product to get our desired answer.
                  (120 / (-2) == -60)
*/
