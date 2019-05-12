'''
    LEADERS OF AN ARRAY

    The task is to find all leaders in an array, where
    a leader is an array element which is greater than all the elements
    on its right side
'''
    
print("Enter the size of array : ")
num = int(input())
a = []
print("Enter array elements")
for i in range(0, num):
    a.append(int(input()))
maximum = a[num - 1]
print("The following are the leaders of array : ")
print(a[num - 1], " ", end = '')
for i in range(num - 2, -1, -1):
    if (a[i] > maximum):
        print(a[i], " ", end = '')
    
'''
Input : num = 5
        Array = [13, 4, 12, 1, 5]
Output :
        The following are the leaders of array : 
        5 12 13
'''
