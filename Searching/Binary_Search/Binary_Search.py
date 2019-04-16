# Function for Binary Search
def Binary_Search(list, desired):
    left = 0
    right = len(list) - 1

    while left <= right:
        # Return positon if found
        middle = left + int((right - left) / 2)

        if list[middle] == desired:
            return middle
        elif desired < list[middle]:
            right = middle - 1
        elif desired > list[middle]:
            left = middle + 1

    return -1

list = [1, 2, 3, 4, 5, 6, 7]

# Element to be searched is 4
print ("Found") if Binary_Search(list, 4) != -1 else ("Not Found")

# Element to be searched is 9
print ("Found") if Binary_Search(list, 9) != -1 else ("Not Found")


''' Output

Found
Not Found

'''
