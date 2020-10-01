def interpolation(list, search_item):
    high = len(list) - 1
    low = 0

    while low <= high and search_item >= list[low] and search_item <= list[high]:
        rise = high - low
        run = list[high] - list[low]
        x = search_item - list[low]
        pos = low + int(rise / run) * x;

        if list[pos] == search_item:
            return pos
        elif search_item < list[pos]:
            high = pos - 1
        else:
            low = pos + 1

    return -1

list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
search_item = 8
index = interpolation(list, search_item)

if index == -1:
    print("Element not found")
else:
    print("Found at position " + str(index))


''' Output

Found at position 7

'''
