# function for insertion sort
def Insertion_Sort(array):
    for i in range(1, len(array)):
        temp = array[i]
        j = i - 1
        while array[j] > temp and j >= 0:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = temp

# function to print array
def Print_Array(array):
    for i in range(0, len(array)):
        print(array[i],end=" ")
    print()

array = [2, 4, 3, 1, 6, 8, 4]

Insertion_Sort(array)

Print_Array(array)

# Output
# 1 2 3 4 4 6 8
