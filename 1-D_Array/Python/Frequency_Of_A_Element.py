# Python program to find the frequency of an element

num = int(input("Enter number of elements in the array"))
arr = []
f = 0
for i in range(0, num):
    arr.insert(i, int(input()))

#Finding frequency of an element
n = int(input("Enter the number whose occurence is to be found: "))
print("Frequency is : ", arr.count(n))

'''

Enter number of elements in the array5
1
1
2
2
3
Enter the number whose occurence is to be found: 3
Frequency is
1
'''
