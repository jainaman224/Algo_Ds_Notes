
def binSearch( arr, left, right, x): 
    
    if right >= left: 
        mid = left + ( right-left ) / 2
          
        # If the element is present at the middle itself 
        if arr[mid] == x: 
            return mid 
          
        # If the element is smaller than mid,then it can only be present in the left subarray 
        if arr[mid] > x: 
            return binSearch(arr, left, mid - 1, x) 
          
        # Else he element can only be present in the right 
        return binSearch(arr, mid + 1, right, x) 
        
    return -1



def exponentialSearch(arr, n, x): 

    # IF x is present at first  location itself 
    if arr[0] == x: 
        return 0
          
    # Find range for binary search j by repeated doubling 
    i = 1
    while i < n and arr[i] <= x: 
        i = i * 2
      
    # Call binary search for the found range 
    return binSearch( arr, i / 2,  
                         min(i, n), x) 
      
  
# Driver Code 
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x) 
x = int(input())       
final = exponentialSearch(arr, n, x) 
if final == -1: 
    print ("Element not found in thye array")
else: 
    print ("index %d" %(final)) 

'''
INPUT:
n = 5
arr[] = {2, 3, 14, 20, 40}
x = 20
OUPUT:
index 3
'''
