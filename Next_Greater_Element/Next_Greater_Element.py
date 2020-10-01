'''
    Next Greater Element for any element present in the array is the 
    first element occuring to the right of the element which is greater
    in value than the element. For example:
    arr = [5, 10, 14, 6, 12, 20]
    Next greater element for the elements are as following:
    5 -> 10
    10 -> 14
    14 -> 20
    6 -> 12
    12 -> 20
    20 -> NULL
'''

# Function to compute next greater element of elements of array
def nextGreaterElement(arr, size):
    # Create a stack
    st = []

    # Insert first element into stack
    st.append(arr[0]);

    print("Next Greater Element")
    for i in range(1, size) :
        ''' if the array element is greater than the element present
        at the top of stack, then arr[i] is the next greater element
        of element present at the top of stack '''
        while len(st) != 0 and arr[i] > st[0] :
            print(str(st.pop()) + " : " + str(arr[i]))

        # Push the array element to the stack to find its next
        # greatest element
        st.append(arr[i])
    
    # if the element does not have next greater element present
    # in the array, print -1 
    while len(st) != 0 :
        print(str(st.pop()) + " : -1")
    
# Driver code          
arr = [10, 40, 48, 20, 50, 5]
size = len(arr)

# Call to nextGreaterElement function
nextGreaterElement(arr, size)

'''
    Input:
    {10, 40, 48, 20, 50, 5}

    Output:
    Next Greater Element
    10 : 40
    40 : 48
    20 : 50
    48 : 50
    5 : -1
    50 : -1
'''
