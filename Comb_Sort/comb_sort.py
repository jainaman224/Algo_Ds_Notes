# Python Code for CombSort 
# function to update gap value
def updateGap(gap):
    # Shrink gap by Shrink factor 
    gap = int((gap * 10)/13)
    if gap < 1: 
        return 1
    return gap

# Function to sort arr[] using Comb Sort 
def combSort(arr, n): 
    # Initialize gap value by array length
    gap = n 
    swapped = True
    while gap != 1 or swapped == True: 
        # Update gap value
        gap = updateGap(gap) 
        swapped = False
        # Compare all elements with the obtained gap value
        for i in range(0, n-gap): 
            if arr[i] > arr[i + gap]: 
                arr[i], arr[i + gap]=arr[i + gap], arr[i] 
                swapped = True
                
# Driver Code
arr = [3, -6, 20, 66, 25, -52, 0, 11, 42]
n= len(arr)
# Call to combSort function
combSort(arr, n) 
# Printing Sorted Array 
print ("Sorted array") 
for i in range(n): 
    print (arr[i],end=' ')
