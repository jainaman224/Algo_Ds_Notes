n= int(input())  #Taking input from user
arr = []      #Empty list
for i in range(n):   #For loop for iterations
    arr.append([])
    arr[i].append(1)
    for j in range(1, i):
        arr[i].append(arr[i - 1][j - 1] + arr[i - 1][j])
    if(n != 0):
        arr[i].append(1)
for i in range(n):
    print(" " * (n - i), end = " ", sep = " ")
    for _ in range(0, i + 1):
        print('{0:6}'.format(arr[i][_]), end = " ", sep = " ")  #Printing the pattern
    print()
