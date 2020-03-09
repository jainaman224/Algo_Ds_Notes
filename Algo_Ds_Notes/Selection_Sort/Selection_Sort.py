# Function for selection sort
def Selection_Sort(array):
    for i in range(0, len(array) - 1):
        min_index = i

        for j in range(i + 1, len(array)):
            if array[j] < array[min_index]:
                min_index = j

        array[i], array[min_index] = array[min_index], array[i]

# Function to print list
def Print_list(array):
    for i in range(0, len(array)):
        print(array[i], end = " ")

    print()

num = int(input())
array = []
for i in range(0, num):
    array.append(int(input()))
Selection_Sort(array)
Print_list(array)

''' Output

1 2 3 4 4 6 8

'''
