def  no_of_even_elem(arr):

    #Initialization
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

#input array from user

lst = []    # creating an empty list 
  
n = int(input("Enter number of elements : ")) # number of elemetns of list 
  
for i in range(0, n): 
    elem = int(input()) 
  
    lst.append(elem) # adding the element 

num = no_of_even_elem(lst)
print "Number of odd elements in array", len(lst)- num
print "Number of even elements in array", num
