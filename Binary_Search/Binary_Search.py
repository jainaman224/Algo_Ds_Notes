# Function for Binary Search
def binarySearch(array, desired):
    left = 0
    right = len(array) - 1

    while left <= right:
        # Return positon if found
        middle = left + int((right - left) / 2)

        if array[middle] == desired:
            return middle
        elif desired < array[middle]:
            right = middle - 1
        elif desired > array[middle]:
            left = middle + 1

    return -1

num = int(input())
array = []
for i in range(0, num):
    array.append(int(input()))

desired = int(input())

print ("Found") if binarySearch(array, desired) != -1 else ("Not Found")

'''
Input:
num = 7
array = {1, 2, 3, 4, 5, 6, 7}
desired = 4

Output:
Found

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
Not Found
'''
