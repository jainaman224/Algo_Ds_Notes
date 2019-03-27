
def counting_sort(input , n)
  max = input.max
  min = input.min
  arr = []
  for i in min..max
    arr.push(0)
  end
  for i in input
    arr[i-min]=arr[i-min]+1
  end
  for i in 0..max-min-1
    arr[i+1]=arr[i+1]+arr[i]
  end
  output = []
  for i in 0..n-1
    output.push(0)
  end
  for i in input
    output[arr[i-min]-1]=i
    arr[i-min]=arr[i-min]-1
  end
  for i in output
    print(i.to_s + " ")
  end
end

input = [1,5,2,7,3,4,4,1,5]
n = input.length()


counting_sort(input,n)


=begin
input = [1,5,2,7,3,4,4,1,5]
output= 1 1 2 3 4 4 5 5 7
=end
