# function to left rotate the array by d elements
def rotate(arr, n, d):
    
    # it brings down d to the minimum number of rotations we need to make in case d > n
    d = d % n
    
    # initialize temp array of size d
    temp = [0] * d
    
    # copy the first d elements to temp array
    for i in range(d): 
        temp[i] = arr[i]
    
    # left moves the rest of the elements in original array by d elements
    for i in range(n-d): 
        arr[i] = arr[i+d]
    
    # assigns the remaining elements from temp array to original array
    for i in range(d): 
        arr[i+n-d] = temp[i]
    
arr = [1, 2, 3, 4, 5, 6, 7] 
print(arr)
rotate(arr, 7, 2) 
print(arr)
  
# Sample Input - 
# [1,2,3,4,5,6,7]
# Sample Output - 
# [3,4,5,6,7,1,2]
