#Kadane's algorithm with Ruby

def kadane(array)
  current_max = max_so_far = array[0]

  for i in 1 .. array.length - 1
    current_max += array[i]
    if current_max < 0
      current_max = 0
    end
    if max_so_far < current_max
      max_so_far = current_max
    end
  end

  return max_so_far
end

array = [-2, 1, -6, 4, -1, 2, 1, -5, 4]

max_subarray_sum = kadane(array)

print(max_subarray_sum)

# Output
# 6
