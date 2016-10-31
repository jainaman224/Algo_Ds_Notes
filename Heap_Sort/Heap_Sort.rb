def heap_sort(array)
  (1..array.length - 1).each do |i|
    child = i
    while child > 0
      parent = (child - 1) / 2
      if array[parent] < array[child]
        array[parent], array[child] = array[child], array[parent]
        child = parent
      else
        break
      end
    end
  end

  i = array.length - 1

  while i > 0
    array[0], array[i] = array[i], array[0]
    i -= 1

    parent = 0

    while parent * 2 + 1 <= i
      child = parent * 2 + 1

      if ((child < i) && (array[child] < array[child + 1]))
        child += 1
      end

      if array[parent] < array[child]
        array[parent], array[child] = array[child], array[parent]
        parent = child
      else
        break
      end
    end
  end

  array
end

array = [2, 4, 3, 1, 6, 8, 4]
array = heap_sort(array)

print array
puts

# Output
# [1, 2, 3, 4, 4, 6, 8]
