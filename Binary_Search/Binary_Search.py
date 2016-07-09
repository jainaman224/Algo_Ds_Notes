# Function for Binary Search
def Binary_Search(array, desired):
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

array = [1, 2, 3, 4, 5, 6, 7]

# Element to be searched is 4
if Binary_Search(array, 4) != -1:
    print("Found")
else:
    print("Not Found")

# Element to be searched is 9
if Binary_Search(array, 9) != -1:
    print("Found")
else:
    print("Not Found")


''' Output

Found
Not Found

'''
