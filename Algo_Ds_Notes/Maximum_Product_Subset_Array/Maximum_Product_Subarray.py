'''
    MAXIMUM PRODUCT SUBSET OF AN ARRAY

    Given an array of n elements. We need to find the maximum product possible
    with any subset of that array.
'''

neg = 0
pos = 0
zero = 0
prod = 1
max_neg = -10000000

'''
    Approach : Two negative numbers multiply together to form a positive number.
            Hence, the maximum product in case of even frequency of negative 
            numbers will be the product of entire array except zero.
            In case of odd frequency of negative numbers, we exclude the 
            smallest negative number from the product of the array to get our
            answer.
            Also, in case of single negative number and no positive number in 
            the array, the answer would be 0, if even a single 0 is present, 
            else it would be the negative number itself.
'''
def solve(temp, num) :
    if (num == 1) :
        return temp[0]
    if zero == num or (neg == 1 and neg + zero == num and zero > 0) :
        return 0
    if not neg % 2 :
        return prod
    return prod / max_neg

num = 5
temp = [5, -2, 4, -3, -1]
for i in range(0, num) :
    if (temp[i] > 0) :
        pos = pos + 1
    elif (temp[i] == 0) :
        zero = zero + 1
        continue
    else :
        neg = neg + 1
        if (temp[i] > max_neg) :
            max_neg = temp[i]
    prod = prod * temp[i]
ans = solve(temp, num)
print("Maximum Product Subset is :" , int(ans))

'''
    Input: Array : [5, -2, 4, -3, -1]
    Output: Maximum Product Subset is : 120
    Verification: The product of array is -120. Since, there are odd numbers of
                  negative numbers present in the array, we exclude the smallest
                  negative number (-1) from the product to get our desired answer.
                  (-120 / (-1) == 120)
'''
