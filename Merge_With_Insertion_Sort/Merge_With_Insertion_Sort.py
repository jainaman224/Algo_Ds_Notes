def insertion(array, left, right):
    for i in range(left, right + 1):
        key = array[i]
        j = i

        while j > left and array[j-1] > key:
            array[j] = array[j-1]
            j -= 1

        array[j] = key

# Conquer
def conquer_merge(array, left, right, mid):
    #temp = [None] * len(array)
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if array[i] <= array[j]:
            temp[k] = array[i]
            i += 1
        else:
            temp[k] = array[j]
            j += 1

        k += 1

    while i <= mid:
        temp[k] = array[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = array[j]
        j += 1
        k += 1

    while left <= right:
        array[left] = temp[left]
        left += 1

# Divide array into halves
def divide(array, left, right):
    # If the size of subarray to be sorted is less than or equal to 8.
    # Perform Insertion Sort
    if right - left <= 8:
        insertion(array, left, right)
    # If size of array is greater than 8.
    # Perform Merge_Sort
    else:
        mid = left + (right - left) / 2;
        mid = int(mid)

        divide(array, left, mid)
        divide(array, mid + 1, right)

        conquer_merge(array, left, right, mid)

def Merge_Sort(array):
    global temp
    temp = [0] * len(array)
    divide(array, 0, len(array) - 1)
    del temp

# function to print array
def Print_Array(array):
    for i in range(0, len(array)):
        print(array[i],end=" ")

    print()

array = [2, 4, 3, 1, 6, 8, 4, 10, 11, 0, 15, 7, 9]

Merge_Sort(array)

Print_Array(array)

# Output
# 0 1 2 3 4 4 6 7 8 9 10 11 15
