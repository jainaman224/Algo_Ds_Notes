# Function to find the maximum index
def max_index(arr , n)
    mi = 0
    for i in 0..n-1
        if arr[i]>arr[mi]
            mi = i
        end
    end
    return mi+1
end

#Function to flip the give array
def flip(arr , m)
    start = 0
    last = m-1
    while start<last
        a = arr[start]
        arr[start] = arr[last]
        arr[last] = a
        start = start+1
        last = last-1
    end
    return arr
end

# Function to sort the given input
def pancake_sort(arr , len)
    n = len
    m = len
    perm_arr = arr
    while m>1
        mi = max_index(perm_arr , m)
        if mi != m-1
            # Flips the array from index 0 till the max index
            temp_arr = flip(perm_arr , mi)
            # Flips the array from index 0 till the length of the array
            perm_arr = flip(temp_arr , m)
        end
        m = m-1
    end
    for i in 0..n-1
        print(perm_arr[i].to_s + " ")
    end
end

input = [2,7,8,1,4,1]
len = input.length()

# Driver program
pancake_sort(input , len)

=begin
input = [2,7,8,1,4,1]
output = 1 1 2 4 7 8
=end
