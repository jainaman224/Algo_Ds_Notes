from math import floor


def circle_sort_rec(arr, start, end):
    swaped = False
    if (end - start) < 2:
        if arr[start] > arr[end]:
            swap(arr, start, end)
            swaped = True
        return swaped
    mid = int(floor((start + end)/2))
    for i in range(start, mid+1):
        if i == start+end-i:
            if arr[i] > arr[i+1]:
                swap(arr, i, i+1)
                swaped = True
        else:
            if arr[i] > arr[start+end-i]:
                swap(arr, i, start+end-i)
                swaped = True
    if circle_sort_rec(arr, start, mid):
        swaped = True
    if circle_sort_rec(arr, mid+1, end):
        swaped = True
    return swaped


def circle_sort(arr):
    n = len(arr)
    while circle_sort_rec(arr, 0, n-1):
        pass


def swap(arr, pos1, pos2):
    arr[pos1], arr[pos2] = arr[pos2], arr[pos1]


if __name__ == '__main__':
    elements = input("Enter elements of array : ")
    elements = elements.split(" ")
    arr = [int(x) for x in elements]
    circle_sort(arr)
    arr = [str(x) for x in arr]
    arr = " ".join(arr)
    print(arr)
