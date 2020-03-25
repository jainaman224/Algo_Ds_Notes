def Pascal_Triangle(n):  
    for row in range(1, n + 1):  
        # Initializing the Initial Value of Pascal Value as 1
        pascal_value = 1
        # For printing blank spaces
        for i in range(1, n - row + 1):
            print(' ', end=' ') 
        # For calculating the pascal value 
        for i in range(1, row + 1): 
            # Creating the printable string and printing the string
            s = ' ' + str(pascal_value) + ' '
            print(s, end = " ")  
            # Calculating the new Pascal Value
            pascal_value = int(pascal_value * (row - i) / i) 
        print(end = '\n')  

# Taking the Input from the user  
rows = int(input("Enter the number of rows to be printed: ")) 
# Calling the Function
Pascal_Triangle(rows)

# Input:
# Enter the number of rows to be printed: 5

# Output:
#      1
#     1  1
#    1  2  1
#   1  3  3  1
# 1  4  6  4  1
