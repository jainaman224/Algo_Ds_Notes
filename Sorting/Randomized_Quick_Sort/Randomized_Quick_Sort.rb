# Internal: Divides the array into two segments by selecting last element as the key
#
# array - Array of integer elements
# p     - start index of array
# r     - end index of array (array_length-1)
#
# COMPLEXITY: Θ(n)
#
# Examples
#   partition([1, 3, 8, 7, 9, 6, 2, 4, 5], 0, 8)
#   => 4
#
# Returns a sorted array.
def partition(arr, p, r)
	key = arr[r]
	i = p-1
	(p..r-1).each do |j|
		if arr[j] <= key
			i += 1
			arr[i], arr[j] = arr[j], arr[i]
			# TODO: Show each step more clearly
			# p "SWAPPING #{arr[i]} with #{arr[j]}"
			# sleep(1.0)
		end
	end
	arr[i+1], arr[r] = arr[r], arr[i+1]
	i+1
end

# Internal: Divides the array into two segments by selecting random index element as the key
#
# arr - Array of integer elements
# p   - start index of array
# r   - end index of array (array_length-1)
#
# COMPLEXITY: Θ(n)
#
# Examples
#   randomized_partition([1, 3, 8, 7, 9, 6, 2, 4, 5], 0, 8)
#   => 4 (could be this, cannot be predicted due to the randomness)
#
# Returns a sorted array.
def randomized_partition(arr, p, r)
	i = rand(p..r)
	arr[r], arr[i] = arr[i], arr[r]
	partition(arr, p, r)
end


# Internal: Sorts the elements of the array using RANDOMIZED QUICK sort algorithm
# 					Divide and Conquer strategy
# Dependancy: randomized_partition
#
# arr - Array of integer elements
# p   - start index of array
# r   - end index of array (array_length-1)
#
# COMPLEXITY: Θ(nlogn)
# TODO: Update the code to handle any kind of datatype
#       Make it a more sleek
#
# Examples
#   randomized_quick_sort([5, 3, 8, 7, 9, 6, 2, 4, 1], 0, 8)
#   randomized_quick_sort([5, 3, 8, 7, 9, 6, 2, 4, 1])
#   => [1, 2, 3, 4, 5, 6, 7, 8, 9]
#
# Returns a sorted array.
def randomized_quick_sort(arr, p=0, r=arr.length-1)
	if p < r
		q = randomized_partition(arr, p, r)
		randomized_quick_sort(arr, p, q-1)
		randomized_quick_sort(arr, q+1, r)
	end
	arr
end

def unit_test_randomized_quick_sort
  arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
  ok = (randomized_quick_sort(arr) == [1, 2, 3, 4, 5, 6, 7, 8, 9])
  if ok
    p "RANDOMIZED QUICK SORT - OK"
  else
    raise "RESULT AND EXPECTED ARRAY DOES NOT MATCH"
  end
end

unit_test_randomized_quick_sort
