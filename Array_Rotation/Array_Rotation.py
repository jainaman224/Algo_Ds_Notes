#Program to rotate array Arr[] of size n by d Elements
#Rotate the arr to left by 1 
def leftRotationby1(arr,n):
    temp = arr[0]
    for i in range(n-1):
        arr[i] = arr[i+1]
    arr[n-1] = temp

#Rotate the arr to right by 1 
def rightRotationby1(arr,n):
    temp = arr[n-1]
    for i in range(n-1,0,-1):
        arr[i] = arr[i-1]
    arr[0] = temp

#Rotate the arr to left by d i.e, leftRotationby1 runs d times
def RotateLeftbyd(arr,d,n):
    for i in range(d):
        leftRotationby1(arr,n)
    for i in range(n):
        print(arr[i],end=" ")
    print()

#Rotate the arr to right by d i.e, rightRotationby1 runs d times
def RotateRightbyd(arr,d,n):
    for i in range(d):
        rightRotationby1(arr,n)
    for i in range(n):
        print(arr[i],end=" ")
    print()

#Driver Code
arr = [1,2,3,4,5,6,7,8]
RotateLeftbyd(arr,2,7)
RotateRightbyd(arr,4,7)

'''
Input: [1,2,3,4,5,6,7,8]
output: 3 4 5 6 7 8 1 2
        5 6 7 8 1 2 3 4
'''