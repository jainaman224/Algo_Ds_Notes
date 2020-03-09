#sort function

def Binary_Insertion_Sort(lst):
    for i in range(1, len(lst)):
        x = lst[i]                            # here x is a temporary variable
        pos = BinarySearch(lst, x, 0, i) + 1
 
        for j in range(i, pos, -1):
            lst[j] = lst[j - 1]
 
        lst[pos] = x
 

#binary search function for finding the next value

def BinarySearch(array, value, low, high):
    
    if high - low <= 1:
        if value < array[low]:
            return low - 1
        else:
            return low
 
    mid = (low + high)//2
    if array[mid] < value:
        return BinarySearch(array, value, mid, high)
    elif array[mid] > value:
        return BinarySearch(array, value, low, mid)
    else:
        return mid

#main function

array = input('Enter the array of numbers: ').split() #enter the values leaving a space between each
array = [int(x) for x in array]
Binary_Insertion_Sort(array)
print('The array after sorting: ', end='')
print(array)

'''
Example:
Input:
Enter the array of numbers: 90 -20 8 11 3
Output:
The array after sorting: [-20, 3, 8, 11, 90]
'''
