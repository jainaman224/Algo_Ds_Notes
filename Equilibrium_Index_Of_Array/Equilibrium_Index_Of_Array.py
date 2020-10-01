'''
    EQUILIBRIUM INDEX OF AN ARRAY

    An equilibrium index is an index of an array, where the commulative sum 
    of all elements below it is equal to the commulative sum of all elements
    above it in that array.

'''

def eq_index(a, num):
    total = 0
    sum_left = 0
    for i in range(0, num):
        total = total + a[i]
    for i in range(0, num):
        total = total - a[i]
        if (sum_left == total):
            return i
        sum_left = sum_left + a[i]
    return -1

print("Enter length of array")
num = int(input())
print("Enter array elements :")
a = []
for i in range(0, num):
    a.append(int(input()))
print("The equilibrium index is :", eq_index(a, num))

'''
    Input : num = 4
            Array : [12, 2, 6, 6]
    Output : The equilibrium index is : 1
'''
