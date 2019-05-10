# function for insertion sort
def Insertion_Sort(list):
    for i in range(1, len(list)):
        temp = list[i]
        j = i - 1
        while j >= 0 and list[j] > temp:
            list[j + 1] = list[j]
            j -= 1

        list[j + 1] = temp

# function to print list
def Print_list(list):
    for i in range(0, len(list)):
        print(list[i],end=" ")
    print()

num = int(input())
list = []
for i in range(0, num):
    list.append(int(input()))
Insertion_Sort(list)
Print_list(list)

'''
Input :
num = 6
array = [1, 6, 3, 3, 5, 2]

Output :
[1, 2, 3, 3, 5, 6]
'''
