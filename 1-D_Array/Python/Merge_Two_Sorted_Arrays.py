#Python program to merge two sorted array a[] and b[] and storing it in c[]

a = []
b = []
c = []
num1 = int(input("Enter number of elements in array 1: "))
print("Enter your sorted array 1: ")
for i in range(0, num1):
    a.insert(i, int(input())
num2 = int(input("Enter number of elements in array 2: "))
print("Enter your sorted array 2: ")
for i in range(0, num2):
    b.insert(i, int(input())

k = 0
j = 0
i = 0

# Traverse both array 
while i < num1 AND j < num2:
    if a[i] > b[j]:
        c[k] = b[j]
        k = k + 1
        j = j + 1
    else:
        c[k] = a[i] 
        k = k + 1
        i = i + 1

# copying remaining elements of array a 
while i < num1:
    c[k] = a[i]
    k = k + 1
    i = i + 1

# copying remaining elements of array b
while j < num2:
    c[k] = b[j]
    k = k + 1
    j = j + 1         

print("New merged array: ")
for i in c:
    print(i)

'''
Enter number of elements in array 1: 5
Enter your sorted array 1: 
3
45
1
2
4
Enter number of elements in array 2: 4
Enter your sorted array 2: 
32
10
5
7
New merged array: 
1
2
3
4
5
7
10
32
45
'''
             
