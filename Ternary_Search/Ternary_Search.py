# Function for Ternary Search
def Ternary_Search(list, left, right, desired):
    while left <= right:
        # Return positon if found
        mid1 = left + int((right - left) / 3);
        mid2 = mid1 + int((right - left) / 3);

        if list[mid1] == desired:
            return mid1

        if list[mid2] == desired:
            return mid2

        if list[mid1] > desired:
            return Ternary_Search(list, left, mid1 - 1, desired)

        if list[mid2] < desired:
            return Ternary_Search(list, mid2 + 1, right, desired)

        return Ternary_Search(list, mid1 + 1, mid2 - 1, desired)

    return -1

list = [1, 2, 3, 4, 5, 6, 7]

# Element to be searched is 4
if(Ternary_Search(list, 0, 6, 4) != -1):
    print("Found")
else:
    print("Not Found")

# Element to be searched is 9
if(Ternary_Search(list, 0, 6, 9) != -1):
    print("Found")
else:
    print("Not Found")


''' Output

Found
Not Found

'''
