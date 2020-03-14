#Ruby  program to find the maximum and the next maximum number in an array

puts "Enter number of elements in array:"
num =gets.to_i
arr = Array.new(num) 
puts "Enter your array: "

counter=0
while counter<num
    arr[counter]=gets.chomp().to_i
    counter+=1
end

# sorting the array by using sort method
arr= arr.sort 

# After sorting the last element is highest and the second last element is Next Max
puts ("Max: "+ arr[num-1].to_s)
if num > 1
    puts ("Next max: "+ arr[num-2].to_s)
end

# Output: 
# Enter number of elements in array:
# 5
# Enter your array:
# 3
# 4
# 7
# 6
# 9
# Max: 9
# Next max: 7

