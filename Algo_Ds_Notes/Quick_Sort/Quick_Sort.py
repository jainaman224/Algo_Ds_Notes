# Conquer
def Parition(list, left, right):
    pivot = list[left]
    index = right

    for j in range(right, left - 1, -1):
        if list[j] > pivot:
            list[index], list[j] = list[j], list[index]
            index -= 1

    list[index], list[left] = list[left], list[index]
    return index

# Divide list into halves
def Quick(list, left, right):
    if left < right:
        pivot = Parition(list, left, right)

        Quick(list, left, pivot - 1)
        Quick(list, pivot + 1, right)

def Quick_Sort(list):
    Quick(list, 0, len(list) - 1)

# Function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i], end = " ")

    print()

list = [2, 4, 3, 1, 6, 8, 4]

Quick_Sort(list)

Print_list(list)


''' Output

1 2 3 4 4 6 8

'''
