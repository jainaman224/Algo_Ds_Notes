# Function for Linear Search
def Linear_Search(array, desired):
    for i in range(0, len(array)):
        # return positon if found
        if(array[i] == desired):
            return i

    return -1

array = [2, 4, 6, 7, 3, 1, 5]

# Element to be searched is 4
if(Linear_Search(array,4) != -1):
    print("Found")
else:
    print("Not Found")

# Element to be searched is 9
if(Linear_Search(array,9) != -1):
    print("Found")
else:
    print("Not Found")

# Output
# Found
# Not Found
