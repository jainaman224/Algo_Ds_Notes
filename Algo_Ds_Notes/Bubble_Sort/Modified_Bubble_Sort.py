# function for bubble sort
def Bubble_Sort(list):
    for i in range(0, len(list) - 1):
        flag = 0   # flag for tracking the swap so that if transversal over entire array is needed or not 
        for j in range(0, len(list) - i - 1):
            # do swapping
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]
                flag = 1   
        if flag == 0:   # if this is true , then it means that no swapping has been done in either the first pass or any other pass , break out of loop
            break

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
