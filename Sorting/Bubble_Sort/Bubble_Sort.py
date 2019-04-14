# function for bubble sort
def Bubble_Sort(list):
    for i in range(0, len(list) - 1):
        for j in range(0, len(list) - i - 1):
            # do swapping
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]

# function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i], end = " ")

    print()

list = [2, 4, 3, 1, 6, 8, 4]

Bubble_Sort(list)

Print_list(list)

# Output
# 1 2 3 4 4 6 8
