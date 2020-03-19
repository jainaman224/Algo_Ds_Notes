# A function which is used to sort the given list using Gnome sort 
def gnome_sort(arr, n): 
    index = 0
    # Checking the Condition
    while index < n:
        # Intially Index is set to Zero then It will be incremented to 1 
        if index == 0: 
            index = index + 1
        # Checking the values between the array elements
        if arr[index] >= arr[index - 1]: 
            index = index + 1
        else: 
            arr[index], arr[index-1] = arr[index-1], arr[index] 
            index = index - 1
  
    return arr 
  
# Test Code 
n = int(input("Enter the size of an Array: "))
arr = list()
for i in range(n):
    val = int(input())
    arr.append(val)
# Function Call
result = gnome_sort(arr,n)
print(result)

'''
    Sample Driver Code:
    INPUT: 
    Enter the size of an Array: 5
    3
    2
    1
    -5
    7

    OUTPUT:
    -5
    1
    2
    3
    7

'''
