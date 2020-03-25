#Ruby  program to Merge two sorted arrays

puts "Enter number of elements in array 1:"
num1 =gets.to_i
a = Array.new(num1) 
puts "Enter your array: "

counter=0
while counter<num1
    a[counter]=gets.chomp().to_i
    counter+=1
end

puts "Enter number of elements in array 2:"
num2 =gets.to_i
b = Array.new(num2) 
puts "Enter your array: "

counter=0
while counter<num2
    b[counter]=gets.chomp().to_i
    counter+=1
end


c=Array.new(num1+num2) 

i=0
j=0
k=0

# Traverse both array 
while i < num1 && j < num2
    if a[i] > b[j]
        c[k] = b[j]
        k = k + 1
        j = j + 1
    else
        c[k] = a[i] 
        k = k + 1
        i = i + 1
    end
end

# copying remaining elements of array a 
while i < num1
    c[k] = a[i]
    k = k + 1
    i = i + 1
end

# copying remaining elements of array b
while j < num2
    c[k] = b[j]
    k = k + 1
    j = j + 1         
end 

print("New merged array: ")

i=0
while i<=k
	puts c[i].to_s + ' '
	i+=1
end

#OUTPUT:
# Enter number of elements in array 1:
# 5
# Enter your array:
# 2
# 6
# 8
# 9
# 11
# Enter number of elements in array 2:
# 3
# Enter your array:
# 4
# 7
# 8
# New merged array: 2
# 4
# 6
# 7
# 8
# 8
# 9
# 11