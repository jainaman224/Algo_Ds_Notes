# This program takes an array as input from the user 
# and prints the occurance of  specific element


puts "Enter size of Array"
size=gets
Arr=Array.new(size.to_i)
puts 'Enter the array elements:'


counter=0
while counter<size.to_i
	Arr[counter]=gets.chomp()
	counter+=1
end

puts 'Enter the element whose occurance is to be checked: '
occurance=gets.chomp()

count_occurance=0
counter=0

while counter<size.to_i
	if occurance==Arr[counter]
		count_occurance+=1
	end
	counter+=1
end

puts "The element " + occurance + " was present "+ count_occurance.to_s + " times in the given array."

# Output

# Enter size of Array
# 10
# Enter the array elements:
# 1
# 2
# 3
# 3
# 4
# 5
# 3
# 2
# 1
# 2
# Enter the element whose occurance is to be checked:
# 3
# The element 3 was present 3 times in the given array.