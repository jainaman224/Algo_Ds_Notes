# Function for selection sort
def Selection_Sort(list):
    for i in range(0, len(list) - 1):
        min_index = i

        for j in range(i + 1, len(list)):
            if list[j] < list[min_index]:
                min_index = j

        list[i], list[min_index] = list[min_index], list[i]

# Function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i], end = " ")

    print()

list = [2, 4, 3, 1, 6, 8, 4]

Selection_Sort(list)

Print_list(list)


''' Output

1 2 3 4 4 6 8

'''
