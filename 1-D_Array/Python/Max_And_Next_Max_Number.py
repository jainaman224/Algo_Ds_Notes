#Python program to find the maximum and the next maximum number in an array

num = int(input("Enter number of elements in array: "))
arr = []
print("Enter your array: ")
for i in range(0, num):
    arr.insert(i, int(input()))

# max is for maximum number and 
# smax for next(second) maximum number

# Assigning max and smax with arr[0] and arr[1] depending
# on the condition max > smax

if arr[0] > arr[1]:
    max = arr[0]
    smax = arr[1]
else:
    max = arr[1]
    smax = arr[0]

# Comparing rest of the element in the array
for i in range(2, num):
    if arr[i] > smax:
        if arr[i] > max:
            smax = max				
            max = arr[i]
        else:
            smax = arr[i]

print("Max: ", max)
print("Next max: ", smax)

'''
Enter number of elements in array: 5
Enter your array:
1
5
6
3
4
Max:  6
Next max:  5
'''
