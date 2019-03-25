//Program to rotate array Arr[] of size n by d Elements
def leftRotation(arr,n):
    temp = arr[0]
    for i in range(n-1):
        arr[i] = arr[i+1]
    arr[n-1] = temp

def Rotate(arr,d,n):
    for i in range(d):
        leftRotation(arr,n)
    for i in range(n):
        print(arr[i],end=" ")

arr = [1,2,3,4,5,6,7]
Rotate(arr,2,7)

/*
Input array: {1, 2, 3, 4, 5, 6, 7 }
Expected Output
3 4 5 6 7 1 2 
*/
