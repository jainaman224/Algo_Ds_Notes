# Pancake Sorting Algorithm in Python3

from array import *


def flip(arr, i):                   # To reverse the array from position 0 to position i
    start = 0
    while start < i:
        temp = arr[start]
        arr[start] = arr[i]
        arr[i] = temp
        start = start + 1
        i = i - 1


def findMax(arr, n):                    # Returns index of the maximum element in arr[0 to n-1]
    maxi = 0
    for i in range(0,n):
        if arr[i] > arr[maxi]:
            maxi = i
    return maxi


def pancakeSort(arr, n):                # Function to perform Pancake Sorting using flip operations
    curr_size = n
    while curr_size > 1:
        maxi = findMax(arr, curr_size)
        if maxi != curr_size-1:
            flip(arr, maxi)
            flip(arr, curr_size-1)
        curr_size -= 1


def printArray(arr, n):                 # Function to print the array
    for i in range(0,n):
        print ("%d"%( arr[i]),end=" ")


# Main function
size = int(input("Enter Array Size : "))
arr = array("i",[])
for i in range (size):
    st = int(input("Enter number : "))
    arr.append(st)
pancakeSort(arr, size)
print ("Sorted Array : ")
printArray(arr,size)



#   Sample I/O :

#   Enter Array Size : 5
#   Enter Number : 23
#   Enter Number : 34
#   Enter Number : 14
#   Enter Number : 78
#   Enter Number : 89
#   Sorted Array : 
#   14 23 34 78 89
