# Function that sort the given input
def counting_sort(input , n)
    max = input.max # Maximum value in the array
    min = input.min # Minimum value in the array
    arr = []
    # Initializing the array elements as zero
    for i in min..max
        arr.push(0)
    end
   # Store count of each indivisual value
    for i in input
        arr[i-min] = arr[i-min] + 1
    end
    # Changing the array so that it contains the actual position of input values in the output array
    for i in 0..max-min-1
        arr[i+1] = arr[i+1] + arr[i]
    end
    output = []
    for i in 0..n-1
        output.push(0)
    end
    # Filling output array using input array and arr
    for i in input
        output[arr[i-min]-1] = i
        arr[i-min] = arr[i-min] - 1
    end
    for i in output
        print(i.to_s + " ")
    end
end
input = [1,5,2,7,3,4,4,1,5]
n = input.length()
# Driver program
counting_sort(input , n)
=begin
input = [1,5,2,7,3,4,4,1,5]
output= 1 1 2 3 4 4 5 5 7
=end
