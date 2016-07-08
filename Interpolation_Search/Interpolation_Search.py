def interpolation(array, search_item):
    high = len(array) - 1
    low = 0

    while low <= high and search_item >= array[low] and search_item <= array[high]:
        rise = high - low
        run = array[high] - array[low]
        x = search_item - array[low]
        pos = low + int(rise / run) * x;

        if array[pos] == search_item:
            return pos
        elif search_item < array[pos]:
            high = pos - 1
        else:
            low = pos + 1

    return -1

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
search_item = 8
index = interpolation(a, search_item)

if index == -1:
    print("Element not found")
else:
    print("Found at position " + str(index))


''' Output

Found at position 7

'''
