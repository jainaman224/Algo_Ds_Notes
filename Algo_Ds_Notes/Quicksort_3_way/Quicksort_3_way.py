import sys
import random

# Partitoning in 3 way:
# | element < pivot | element = pivot | element > pivot |
def partition_3way(list, lower_bound, upper_bound):
    pivot = list[lower_bound]
    index_small = lower_bound; # index_small -> pointer of smaller elements
    index_equal = lower_bound; # index_equal -> pointer of equal elements
    for iterator in range(lower_bound + 1, upper_bound + 1):
        if list[iterator] < pivot:
            if index_small == index_equal:
                list[index_small + 1], list[iterator] = list[iterator], list[index_small + 1]
            else:
                list[index_small + 1], list[iterator] = list[iterator], list[index_small + 1]
                list[index_equal + 1], list[iterator] = list[iterator], list[index_equal + 1]
            index_small += 1
            index_equal += 1

        elif list[iterator] == pivot:
            index_equal += 1
            list[iterator], list[index_equal] = list[index_equal], list[iterator]
    list[lower_bound], list[index_small] = list[index_small], list[lower_bound]
    return index_small, index_equal

def randomized_quick_sort(list, lower_bound, upper_bound):
    if lower_bound >= upper_bound:
        return
    ran_index = random.randint(lower_bound, upper_bound)
    list[lower_bound], list[ran_index] = list[ran_index], list[lower_bound]
    # Use partition_3way
    index_small, index_equal = partition_3way(list, lower_bound, upper_bound)
    randomized_quick_sort(list, lower_bound, index_small - 1)
    randomized_quick_sort(list, index_equal + 1, upper_bound)


if __name__ == '__main__':
    input = sys.stdin.read()
    no_of_elements, *list = list(map(int, input.split()))
    randomized_quick_sort(list, 0, no_of_elements - 1)
    for iterator in list:
        print(iterator, end=' ')
