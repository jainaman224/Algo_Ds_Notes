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

li = input("Enter elements of the array: ").split(" ")
li = list(map(int, li))

Bubble_Sort(li)

Print_list(li)

# Input
# 6 4 8 2 3 4 1

# Output
# 1 2 3 4 4 6 8
