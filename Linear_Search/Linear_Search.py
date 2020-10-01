# Function for Linear Search
def linearSearch(list, desired):
    for i in range(0, len(list)):
        # return positon if found
        if(list[i] == desired):
            return i

    return -1

num = int(input())
list = []
for i in range(0, num):
    list.append(int(input()))
desired = int(input())
if(linearSearch(list,desired) != -1):
    print("Found")
else:
    print("Number not found")


'''
Input :
num = 5
arr = [1,4,5,6,3]
desired = 3

Output :
Number not found
'''
