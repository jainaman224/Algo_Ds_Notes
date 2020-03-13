# Python program to count even and odd numbers in an array

# To count number of even elements
def no_of_even_elem(arr):

    # Initialization
    even_num = 0

    # Finding even numbers in array
    for i in range (0,len(arr)):
        if arr[i] %2 == 0:
            even_num +=1
    return even_num      

#--- main--- function

# initialising variables
arrlength = 0
num  = 0

# creating an empty list 
lst = []

 # number of elements of list 
n = int(input("Enter number of elements : "))
  
for i in range(0, n): 
    elem = int(input()) 
    lst.append(elem) # adding the element 

num = no_of_even_elem(lst)
print "Number of odd elements in array", len(lst) - num
print "Number of even elements in array", num

'''
Sample Testcase

Enter number of elements : 4
2
1
67
43
Number of odd elements in array 3
Number of even elements in array 1
'''
