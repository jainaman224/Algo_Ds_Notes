def counting_sort(input_arr, exp)
  count_arr = Array.new(10, 0)
  result = Array.new(input_arr.size)

  m = 10 ** (exp+1)
  n = 10 ** exp

  input_arr.each do |item|
    count_arr[(item % m) / n] += 1
  end

  for i in 1...10
    count_arr[i] = count_arr[i-1] + count_arr[i]
  end

  i = input_arr.size - 1
  until i < 0 do
    item = input_arr[i]
    count_arr[(item % m) / n] -= 1
    result[count_arr[(item % m) / n]] = item
    i -= 1
  end

  result
end

def radix_sort(arr)
  maximum = arr.max
  exp = 0

  until maximum == 0 do
    exp += 1
    maximum = maximum / 10
  end

  for i in 0...exp do
    arr = counting_sort(arr, i)
  end

  arr
end

array = [170, 45, 75, 90, 802, 24, 2, 66]
array = radix_sort(array)

print array
puts

# Output
# [2, 24, 45, 66, 75, 90, 170, 802]
