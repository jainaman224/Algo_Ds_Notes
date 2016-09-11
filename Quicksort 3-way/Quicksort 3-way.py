import sys
import random

# Partitoning in 3 way:
# | element < pivot | element = pivot | element > pivot |
def partition_3way(array, lower_bound, upper_bound):
    pivot = array[lower_bound]
    index_small = lower_bound; # index_small -> pointer of smaller elements
    index_equal = lower_bound; # index_equal -> pointer of equal elements
    for iterator in range(lower_bound + 1, upper_bound + 1):
        if array[iterator] < pivot:
            if index_small == index_equal:
                array[index_small + 1], array[iterator] = array[iterator], array[index_small + 1]
            else:
                array[index_small + 1], array[iterator] = array[iterator], array[index_small + 1]
                array[index_equal + 1], array[iterator] = array[iterator], array[index_equal + 1]
            index_small += 1
            index_equal += 1

        elif array[iterator] == pivot:
            index_equal += 1
            array[iterator], array[index_equal] = array[index_equal], array[iterator]
    array[lower_bound], array[index_small] = array[index_small], array[lower_bound]
    return index_small, index_equal

def randomized_quick_sort(array, lower_bound, upper_bound):
    if lower_bound >= upper_bound:
        return
    ran_index = random.randint(lower_bound, upper_bound)
    array[lower_bound], array[ran_index] = array[ran_index], array[lower_bound]
    # Use partition_3way
    index_small, index_equal = partition_3way(array, lower_bound, upper_bound)
    randomized_quick_sort(array, lower_bound, index_small - 1)
    randomized_quick_sort(array, index_equal + 1, upper_bound)


if __name__ == '__main__':
    input = sys.stdin.read()
    no_of_elements, *array = list(map(int, input.split()))
    randomized_quick_sort(array, 0, no_of_elements - 1)
    for iterator in array:
        print(iterator, end=' ')
