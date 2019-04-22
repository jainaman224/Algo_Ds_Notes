def binary_search(arr, val, start, end): 
    ''' we need to distinugish whether we should insert 
     before or after the left boundary. 
     imagine [0] is the last step of the binary search 
     and we need to decide where to insert -1 '''
    if start == end: 
        if arr[start] > val: 
            return start 
        else: 
            return start+1
  
    ''' this occurs if we are moving beyond left\'s boundary 
     meaning the left boundary is the least position to 
     find a number greater than val '''
    if start > end: 
        return start 
    mid = int((start+end)/2)
    if arr[mid] < val: 
        return binary_search(arr, val, mid+1, end) 
    elif arr[mid] > val: 
        return binary_search(arr, val, start, mid-1) 
    else: 
        return mid 



def insertion_sort(arr): 
    for i in range(1, len(arr)): 
        val = arr[i] 
        j = binary_search(arr, val, 0, i-1) 
        arr = arr[:j] + [val] + arr[j:i] + arr[i+1:] 
    return arr



elements=input("enter the elements to be sorted")
arr=elements.split()
for i in range(0,len(arr)):
    arr[i]=int(arr[i])
print (arr)
print("Sorted array:")
print(insertion_sort(arr))




'''TESTCASES:
(1)-
enter the elements to be sorted18 4 5 6 9
[18, 4, 5, 6, 9]
Sorted array:
[4, 5, 6, 9, 18]

(2)-
enter the elements to be sorted19 7 2 4 8
[19, 7, 2, 4, 8]
Sorted array:
[2, 4, 7, 8, 19]

(3)-
enter the elements to be sorted7 19 4 85 3
[7, 19, 4, 85, 3]
Sorted array:
[3, 4, 7, 19, 85]
'''
