# Python program for implementation of QuickSort.

# The main function that implements QuickSort
# This function takes the last element as the pivot, places
# the pivot element at its correct position in sorted
# array, and places all smaller (smaller than pivot)
# to the left of the pivot and all greater elements to the right
# of pivot

# array[] --&gt; Array to be sorted,
# start  --&gt; Starting index,
# end  --&gt; Ending index

# Function to do Quicksort
def quicksort(array,start=0,end=None):
    if end is None:
        end=len(array)-1
    if end-start&lt;1:
        return array
    else:
        current=start
        pivot =end
        while 1:
            if current==pivot:
                break
            elif array[current]&gt;array[pivot]:
                array[pivot],array[current],array[pivot-1]=array[current],array[pivot-1],array[pivot]
                pivot-=1
            else:
                current+=1
    quicksort(array,start,pivot-1)
    quicksort(array,pivot+1,end)
    return array

# Driver code to test above
arr = [10, 7, 8, 9, 1, 5]
print (quicksort(arr))

