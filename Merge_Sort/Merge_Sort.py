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
    if left < right:
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

array = [2, 4, 3, 1, 6, 8, 4]

Merge_Sort(array)

Print_Array(array)

# Output
# 1 2 3 4 4 6 8
