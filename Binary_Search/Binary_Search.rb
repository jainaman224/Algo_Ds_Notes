
# Binary Search function

def binarySearch(array, searchVariable, size)

  left = 0
  right = size - 1

  while left <= right

    middle = left + (right - left) / 2

    if(array[middle] == searchVariable)
      return middle

    elsif(searchVariable < array[middle])
      right = middle - 1;

    else
      left = middle + 1;

    end

  end

  return -1

end

# Hard Coded array
array = [1, 2, 3, 4, 5]

# Searching for 1 in the array
if binarySearch(array, 1, array.length()) != -1
  puts("Element found.")
else
  puts("Element not found.")
end
# Gives Output Element found.

# Searching for 0 in the array
if binarySearch(array, 0, array.length()) != -1
  puts("Element found.")
else
  puts("Element not found.")
end
# Gives output Element not found.
