# Cocktail Sort using python
  
def cocktail_Sort(array): 
    num = len(array) 
    swap = True
    beg = 0
    end = num-1
    while (swap == True): 
  
        # reseting the swapped flag on entering the loop, because it might be true from a previous iteration. 
        swap = False
  
        # Similar to bubble sort
        for i in range (beg, end): 
            if (array[i] > array[i + 1]) : 
                array[i], array[i + 1]= array[i + 1], array[i] 
                swap = True
  
        # if nothing is swapped, then array is sorted. 
        if (swap == False): 
            break
  
        # reset the swapped flag 
        swap = False
  
        # decrement end point by one 
        end = end-1
  
        # same procedure to apply from right to left
        for i in range(end-1, beg-1, -1): 
            if (array[i] > array[i + 1]): 
                array[i], array[i + 1] = array[i + 1], array[i] 
                swap = True
  
        # increment the beg as the smallest number has been placed at its correct position 
        beg = beg + 1



# Driver code
array=[]
n=int(input("Enter size of the array:\n"))
 
for i in range(0,n):
    temp=int(input("Enter number to be added:\n"))
    array.append(temp)
 
cocktail_Sort(array) 
print("Sorted array is:") 
for i in range(len(array)): 
    print (array[i])
