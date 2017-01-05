# Function for Linear Search
def Linear_Search(list, desired):
    for i in range(0, len(list)):
        # return positon if found
        if(list[i] == desired):
            return i

    return -1

list = [2, 4, 6, 7, 3, 1, 5]

# Element to be searched is 4
if(Linear_Search(list,4) != -1):
    print("Found")
else:
    print("Not Found")

# Element to be searched is 9
if(Linear_Search(list,9) != -1):
    print("Found")
else:
    print("Not Found")

# Output
# Found
# Not Found
