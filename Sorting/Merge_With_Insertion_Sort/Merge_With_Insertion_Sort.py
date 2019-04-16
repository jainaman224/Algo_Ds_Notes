def insertion(list, left, right):
    for i in range(left, right + 1):
        key = list[i]
        j = i

        while j > left and list[j-1] > key:
            list[j] = list[j-1]
            j -= 1

        list[j] = key

# Conquer
def conquer_merge(list, left, right, mid):
    #temp = [None] * len(list)
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right:
        if list[i] <= list[j]:
            temp[k] = list[i]
            i += 1
        else:
            temp[k] = list[j]
            j += 1

        k += 1

    while i <= mid:
        temp[k] = list[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = list[j]
        j += 1
        k += 1

    while left <= right:
        list[left] = temp[left]
        left += 1

# Divide list into halves
def divide(list, left, right):
    # If the size of sublist to be sorted is less than or equal to 8.
    # Perform Insertion Sort
    if right - left <= 8:
        insertion(list, left, right)
    # If size of list is greater than 8.
    # Perform Merge_Sort
    else:
        mid = left + (right - left) / 2;
        mid = int(mid)

        divide(list, left, mid)
        divide(list, mid + 1, right)

        conquer_merge(list, left, right, mid)

def Merge_Sort(list):
    global temp
    temp = [0] * len(list)
    divide(list, 0, len(list) - 1)
    del temp

# function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i],end=" ")

    print()

list = [2, 4, 3, 1, 6, 8, 4, 10, 11, 0, 15, 7, 9]

Merge_Sort(list)

Print_list(list)

# Output
# 0 1 2 3 4 4 6 7 8 9 10 11 15
