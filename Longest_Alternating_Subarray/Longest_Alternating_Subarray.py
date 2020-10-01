'''
        LENGTH OF LONGEST ALTERNATING SUBARRAY

        Given an array of non-zero integers. We need to find the maximum 
        possible length of a subarray such that it has alternating positive
        and negative elements.
'''
    
print("Enter the size of array : ")
num = int(input())
a = []
print("Enter array elements")
for i in range(0, num):
    a.append(int(input()))
result = 1
count = 1
print("The length of longest alternating subarray is : ", end = '')
for i in range(1, num):
    if (a[i] * a[i - 1] < 0):
        count = count + 1
        if (count > result):
            result = count
    else:
        count = 1
print(result)

'''
Input :
num = 4
Array = [-1, -4, -5, 20]

Output :

The length of longest alternating subarray is : 2
'''
