

 # pancake sort method
  
# Reverseing the array arr */ 
def flip_array(a, pos): 
    start = 0
    while start < pos: 
        temp = a[start] 
        a[start] = a[pos] 
        a[pos] = temp 
        start += 1
        pos -= 1
  
 
#function to return the index of  maximum element in the array
def find_Max_index(a, n): 
    i = 0
    for j in range(0,n): 
        if a[j] > a[i]: 
            i = j
    return i 
  
 
#pancake sort function to sort the main array by fliping 
def pancake_sort(a, n): 
      
    size = n 
    while size > 1: 
        # Find index of the maximum 
       
        i = find_Max_index(a, size) 
  
        # Move the maximum element to end of current array 
        
       
        if i != size-1: 
            
            #move maximum number to beginning  
            flip_array(a, i) 
  
            
            # reversing  array 
            flip_array(a, size-1) 
        size -= 1
 
# print an array of size n  
def print_array(a, n): 
    for i in range(0,n): 
        print ("%d"%( a[i]),end=" ") 
  
# Driver program  
a = [] 
p=0
n =int(input('input the length of array \n')) 
print('input array element \n')
for i in range(0,n) :
    p= int(input()) 
    a.append(p)
pancake_sort(a, n); 
print ("Sorted Array ") 
print_array(a,n)


#   input:
#           5
#           11
#           10
#           86
#           65
#   output:
#           input the length of array 
#           input array element 
#           Sorted Array 
#           7 10 11 65 86
#
