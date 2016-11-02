# Internal: Computes the sum of the left, right halves and their index where max is reached
#
# ARGS:
# arr  - Array where the sub-array has to be found
# low  - Index of the first element in arr
# mid  - Index of the middle element in arr
# high - Index of the last element in arr
#
# Return: Array (Triplet)
#
# Examples
#   find_max_crossing_subarray([-2, -3, 4, -1, -2, 1, 5, -3], 0, 3, 7)
#   => [2, 6, 7]
def find_max_crossing_subarray(arr, low, mid, high)
  sum = max_left = 0
  left_sum = -Float::INFINITY
  max_left = 0
  (low..mid).reverse_each do |i|
    sum += arr[i]
    if sum > left_sum
      left_sum = sum
      max_left = i
    end
  end

  sum = max_right = 0
  right_sum = -Float::INFINITY
  (mid+1..high).each do |j|
    sum += arr[j]
    if sum > right_sum
      right_sum = sum
      max_right = j
    end
  end

  [max_left, max_right, left_sum+right_sum]
end

# Internal: Computes the maximum sub array which returns maximum sum over a range
#           Recursive strategy
#
# ARGS:
# arr  - Array where the sub-array has to be found
# low  - Index of the first element in arr
# high - Index of the last element in arr
#
# Return: Array (Triplet)
#
# Examples
#   find_max_subarray([-2, -3, 4, -1, -2, 1, 5, -3], 0, 7)
#   find_max_subarray([-2, -3, 4, -1, -2, 1, 5, -3])
#   => [2, 6, 7]
def find_max_subarray(arr, low=0, high=arr.length-1)
  low ||= 0
  high ||= arr.length-1

  return [low, high, arr[low]] if low == high
  mid = (low+high)/2
  left_subarray = find_max_subarray(arr, low, mid)
  right_subarray = find_max_subarray(arr, mid+1, high)
  cross_subarray = find_max_crossing_subarray(arr, low, mid, high)

  return left_subarray if left_subarray[2] > right_subarray[2] && left_subarray[2] > cross_subarray[2]
  return right_subarray if right_subarray[2] > left_subarray[2] && right_subarray[2] > cross_subarray[2]
  return cross_subarray
end

def unit_test_find_max_subarray
  arr = [-2, -3, 4, -1, -2, 1, 5, -3]
  ok = (find_max_subarray(arr) == [2, 6, 7])
  if ok
     p "FIND MAX SUB ARRAY - OK"
  else
     raise "RESULT ARRAY AND EXPECTED ARRAY DO NOT MATCH"
  end
end

unit_test_find_max_subarray
