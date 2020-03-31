# Python implementation of Shaker Sort

def Shaker_Sort(arr) :
    n = len(arr)
    # Getting the length of the list 
    begin = 0
    end = n - 1
    swapped = True
    # If swapped is False then we have to stop sorting as list is aldready sorted
    while swapped == True :
        # Continue until it is False
        for i in range (begin, end, 1):
            if arr[i] > arr[i + 1]:
                # Left element is greater than that of right in list
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                # Swapping the elements of the list
                swapped = True
        if swapped == False:
            break
            # If list is sorted then have to break the loop
        swapped = False
        # Now apply bubble sort in opposite direction as list is not sorted
        # Leave the lost element iterated from above loop as it is in correct place
        for i in range (end - 1, begin - 1, - 1) :
            if arr[i] > arr[i + 1] :
                # Left element is greater than that of right in list
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                # Swapping elements of the list
                swapped = True
        # Now the smallest element will be in it's correct place in the list
        begin = begin + 1

# Driver Code
arr = list(map(int,input("Enter Array : ").stript().split(',')))
Shaker_Sort(arr)
# Call to Shaker_Sort function
print (" After Shaker_Sort the Array : ")
for i in range (0, len(arr), 1) :
    print (arr[i], end = " ")

# Sample input arr = [2, 10, 8, 1, 4, 1]
# Output 1 1 2 4 8 10