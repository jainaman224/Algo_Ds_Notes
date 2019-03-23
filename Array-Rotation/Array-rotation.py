//Program to rotate array Arr[] of size n by d Elements
def leftRotationOneByOne(arr,n):
    temp = arr[0]
    for i in range(n-1):
        arr[i] = arr[i+1]
    arr[n-1] = temp

def leftRotation(arr,d,n):
    for i in range(d):
        leftRotationOneByOne(arr,n)

def printArray(arr,n):
    for i in range(n):
        print(arr[i],end=" ")

arr = [1,2,3,4,5,6,7]
leftRotation(arr,2,7)
printArray(arr,7) 
