# Function for Binary Search
def BinarySearch(arr, low, high, num):
    if(high >= low):
        middle = (high + low) // 2
        #if the num is less than the middle number
        if(num < arr[middle]):
            return BinarySearch(arr, low, middle-1, num) 
        #if the num is more than the middle number
        elif(num > arr[middle]):
            return BinarySearch(arr, middle+1, high, num) 
        else:
            return middle
    else:
        return -1

arr = []
n = int(input("Enter number of elements you want in the array: "))
print("Note: Enter " + str(n) + " numbers in SORTED ORDER")

for i in range(n):
    element = int(input("Enter element " + str(i+1) + " : "))
    arr.append(element)
    
desired = int(input("Enter Element you want to Search: "))
index = BinarySearch(arr, 0, len(arr)-1, desired)

if(index != -1):
    print(" ----Number Found at index: " + str(index+1) + " ----")
else:
    print("----Number Not Found! Try again----")



'''
Input:
num = 7
array = {1, 2, 3, 4, 5, 6, 7}
desired = 4

Output:
----Number Found at index: 4 ----

Input:
num = 5
array = {1, 3, 5, 7, 9}
desired = 2

Output:
----Number Not Found! Try again----
'''
