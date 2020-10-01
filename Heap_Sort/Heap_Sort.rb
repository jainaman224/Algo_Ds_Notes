# NOTE: This kind of dynamic method addition to in-built classes is called
#       MONKEY PATCHING(that's right) and its beautiful when done carefully
#       This implementation does not factor in that safety.
#
#       Many suggest against monkey patching because it could turn into a
#       nightmare in production due to the lack of concrete standard documentation
#
# REFERENCE THIS FOR TIPS
# http://www.justinweiss.com/articles/3-ways-to-monkey-patch-without-making-a-mess/
# HAPPY MONKEY PATCHING!

# Public: In-Built Integer class override
#         Extended Integer class methods to get the feel of how much a pseudo code
#         can be related to interpreted code
#         Methods are invoked on an integer
#
# Examples
#
#   10.parent
#   => 5
#   10.left
#   => 20
#   10.right
#   => 21
class Integer
  def parent
    ( self / 2 ).floor
  end

  def left
    ( 2 * self )
  end

  def right
    ( 2 * self ) + 1
  end

  def half
    ( self / 2 ).floor
  end
end

# Public: In-Built Array class override
#         Extended array class to add a method heap_size to be as close to the
#         textbook as possible
#
# Examples
#
#   [1, 2, 3, 4].heap_size
#   => nil
#   [1, 2, 3, 4].heap_size = 10
#   [1, 2, 3, 4].heap_size
#   => 10
class Array
  attr_accessor :heap_size
end

# Public: Ensures the max-heap property is being maintained from the index provided
#         Recursive, Max-Heap property A[parent] >= A[left] as well as A[right]
#
# ARGS:
# arr - Input array
# i   - Index at which the Max-Heap property is to be applied
#
# RETURN: nil
#
# COMPLEXITY: Θ(lgn)
#
# Examples
#    arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
#    max_heapify(arr, 5)
#
# Modifies the provided array.
def max_heapify(arr, i)
  arr.heap_size ||= arr.length

  l = i.left
  r = i.right

  largest = (l <= arr.heap_size-1 && arr[l] > arr[i]) ? l : i
  largest = r if (r <= arr.heap_size-1 && arr[r] > arr[largest])
  if largest != i
    arr[i], arr[largest] = arr[largest], arr[i]
    max_heapify(arr, largest)
  end
end

# Public: Ensures the min-heap property is being maintained from the index provided
#         Recursive, Min-Heap property A[parent] <= A[left] as well as A[right]
#
# ARGS:
# arr - Input array
# i   - Index at which the Min-Heap property is to be applied
#
# RETURN: nil
#
# COMPLEXITY: Θ(lgn)
#
# Examples
#    arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
#    min_heapify(arr, 5)
#
# Modifies the provided array.
def min_heapify(arr, i)
  arr.heap_size ||= arr.length

  l = i.left
  r = i.right

  smallest = (l <= arr.heap_size-1 && arr[l] < arr[i]) ? l : i
  smallest = r if (l <= arr.heap_size-1 && arr[l] < arr[smallest])
  if smallest != i
    arr[i], arr[smallest] = arr[smallest], arr[i]
    min_heapify(arr, smallest)
  end
end

# Public: Re-order the input array to adhere to the Max-Heap property at all indices
#
# ARGS:
# arr - Input array
#
# RETURN: nil
#
# Examples
#    arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
#    build_max_heap(arr)
#
# Modifies the provided array.
def build_max_heap(arr)
  arr.heap_size = arr.length
  (0..arr.length.half).reverse_each do |i|
    max_heapify(arr, i)
  end
end

# Public: Sorts the array by adhering to the Max-Heap property and simulataneously
#         decreasing the heap size
#
# ARGS:
# arr - Input array
#
# RETURN: Array
#
# Examples
#    arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
#    heap_sort(arr)
#    => [1, 2, 3, 4, 5, 6, 7, 8, 9]
#
# Modifies the provided array.
def heap_sort(arr)
  build_max_heap(arr)
  (1..(arr.length-1)).reverse_each do |i|
    arr[0], arr[i] = arr[i], arr[0]
    arr.heap_size -= 1
    max_heapify(arr, 0)
  end
  arr
end

def unit_test_heap_sort
  arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
  ok = (heap_sort(arr) == [1, 2, 3, 4, 5, 6, 7, 8, 9])
  if ok
    p "HEAP SORT - OK"
  else
    raise "RESULT AND EXPECTED ARRAY DOES NOT MATCH"
  end
end

unit_test_heap_sort
