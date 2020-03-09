# Rain_Water_Trapping 
def trappedWater(a, size) : 
  
    # left[i] stores height of tallest bar to the to left of it including itself
    left = [0] * size 
  
    # Right [i] stores height of tallest bar to  the to right of it including itself
    right = [0] * size
  
    # Initialize result 
    waterVolume = 0
  
    #  filling left (list/array) 
    left[0] = a[0] 
    for i in range( 1, size): 
        left[i] = max(left[i-1], a[i]) 
  
    #  filling right (list/array) 
    right[size - 1] = a[size - 1] 
    for i in range(size - 2, - 1, - 1): 
        right[i] = max(right[i + 1], a[i]); 
  
    # Calculating volume of the accumulated water element by element 
    
    for i in range(0, size): 
        waterVolume += min(left[i],right[i]) - a[i] 
  
    return waterVolume 
    
# main program
arr =[]
n = int(input())                    #input the number of towers
for i in range(n):
    arr.append(int(input()))        #storing length of each tower in array

print("Maximum water that can be accumulated is ", trappedWater(arr, len(arr))) 
  
#Input:
#12
#0
#1
#0
#2
#1
#0
#1
#3
#2
#1
#2
#1
#Output:
#The maximum water trapped is 6

