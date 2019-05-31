=begin
BITONIC POINT
Given an array. The task is to find the bitonic point of the array.
The bitonic point in an array is the index before which all the numbers
are in increasing order and after which, all are in decreasing order.
=end

def bitonic(arr, left_end, right_end)
    if left_end <= right_end
        mid_point = (left_end + right_end) / 2
        if arr[mid_point - 1] < arr[mid_point] && arr[mid_point] > arr[mid_point + 1]
            return mid_point
        end
        # We assume that sequence is bitonic. We go to
        # right subarray if middle point is part of
        # increasing subsequence. Else we go to left
        # subarray.
        if arr[mid_point] < arr[mid_point + 1]
            return bitonic(arr, mid_point + 1, right_end)
        else
            return bitonic(arr, left_end, mid_point - 1)
        end
    end
    return -1
end

print("Enter the number of elements : ")
n = gets.chomp.to_i
arr = []
for i in 0..n-1
    arr.push(gets.chomp.to_i)
end
length = arr.length()

# Driver Function
point = bitonic(arr, 1, length - 2)
if point != -1
    print("The bitonic index is " + point.to_s)
else
    print("There is no bitonic point")
end

# output
# Enter the number of elements : 6
# 1
# 3
# 5
# 9
# 4
# 2
# The bitonic index is 3
