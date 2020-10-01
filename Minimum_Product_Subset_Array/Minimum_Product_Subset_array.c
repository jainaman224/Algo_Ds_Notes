/*
    MINIMUM PRODUCT SUBSET OF AN ARRAY

    Given an array of n elements. We need to find the minimum product possible
    with any subset of that array.
*/

#include <stdio.h>
#include <math.h>

int neg = 0, pos = 0, zero = 0, prod = 1, max_neg = -10000000, min_pos = 10000000;

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
int solve(int temp[], int num) {
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
    int num = 5;
    int temp[] = {5, -2, 4, -3, 1};
    for (int i = 0; i < num; i++ ) {
        if (temp[i] > 0) {
            pos++;
            if (temp[i] < min_pos) {
                min_pos = temp[i];
            }
        }
        else if (temp[i] == 0) {
            zero++;
            continue;
        }
        else {
            neg++;
            if (temp[i] > max_neg) {
                max_neg = temp[i];
            }
        }
        prod = prod * temp[i];
    }
    int ans = solve(temp, num);
    printf("Minimum Product Subset is : %d", ans);
    return 0;
}

/*
    Input: Array : [5, -2, 4, -3, 1]
    Output: Minimum Product Subset is : -60
    Verification: The product of array is 120. Since, there are even numbers of
                  negative numbers present in the array, we exclude the smallest
                  negative number (-2) from the product to get our desired
   answer. (120 / (-2) == -60)
*/
