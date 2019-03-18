# Python Code for CombSort 
# Function to sort arr[] using Comb Sort 
def combSort(arr, n): 
    # Initialize gap value by array length
    gap = n 
    flag = 1
    while gap > 1 or flag == 1: 
        # Update gap value by using shrink factor 1.3
        gap = int((gap*10) / 13)
        # if gap is less than 1, set gap to 1
        gap= max(1, gap)
        flag = 0
        # Compare all elements with the obtained gap value
        for i in range(0, n-gap): 
			# swap arr[i] and arr[i+gap] if arr[i] is greater
            if arr[i] > arr[i + gap]: 
                arr[i], arr[i + gap]=arr[i + gap], arr[i] 
                flag = 1
                
# Driver Code
arr = [-10, 50, 20, 0, 15, -25, 30]
n= len(arr)
# Call to combSort function
combSort(arr, n) 
# Printing Sorted Array 
print ("Array after Sorting:") 
for i in range(n): 
    print (arr[i],end=' ')

# Output
# Array after sorting:
# -25 -10 0 15 20 30 50
