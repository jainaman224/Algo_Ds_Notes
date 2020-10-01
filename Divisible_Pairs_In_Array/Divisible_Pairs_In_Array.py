'''
        DIVISIBLE PAIRS IN AN ARRAY

        The problem is to find all pairs of numbers in an array, such that
        one of those numbers divides the other.
'''
    
print("Enter the size of array : ")
num = int(input())
a = []
print("Enter array elements")
for i in range(0, num):
    a.append(int(input()))
print("The following are the divisible pairs :")
for i in range(0, num):
    for j in range(i + 1, num):
        if (a[i] % a[j] == 0 or a[j] % a[i] == 0):
            print(a[i], a[j])

'''
Input :
num = 4
Array = [1, 4, 5, 20]

Output : 

The following are the divisible pairs :
1 4
1 5
1 20
4 20
5 20
'''
