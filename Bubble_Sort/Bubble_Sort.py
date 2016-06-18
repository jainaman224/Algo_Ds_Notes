# function for bubble sort
def Bubble_Sort(array):
    for i in range(0, len(array) - 1):
        for j in range(0, len(array) - i - 1):
            # do swapping
            if(array[j] > array[j + 1]):
                array[j], array[j + 1] = array[j + 1], array[j]

# function to print array
def Print_Array(array):
    for i in range(0, len(array)):
        print(array[i],end=" ")
    
    print()

array = [2, 4, 3, 1, 6, 8, 4]

Bubble_Sort(array)

Print_Array(array)

# Output
# 1 2 3 4 4 6 8
