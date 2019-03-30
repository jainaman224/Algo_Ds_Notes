'''
    PREFIX SUM

    The task is to find the prefix sum of every element of a given array.
    Prefix sum equals to the sum of all element from start to the current element of the array.

'''
def prefix_sum(array, length):
    prefix_array = array
    '''
        We maintain a prefix array where prefix_array[i] = prefix_array[i-1] + array[i].
        As, prefix sum of element i = prefix sum of element i-1 + element i.
    '''
    for i in range(1, length):
        prefix_array[i] = prefix_array[i-1] + array[i]
    print("The prefix array is: ")
    for i in range(0,length):
        print(prefix_array[i], end=' ')

array = [3,2,4,6,7]
length = 5
prefix_sum(array, length)
'''
Input : array = {3,2,4,6,7}
Output: The prefix sum array is: 
        3 5 9 15 22 
'''
