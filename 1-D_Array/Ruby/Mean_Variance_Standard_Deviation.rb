#Ruby  program to Merge two sorted arrays

puts "Enter number of elements in array :"
num1 =gets.to_i
a = Array.new(num1) 
puts "Enter your array: "

counter=0
while counter<num1
    a[counter]=gets.chomp().to_i
    counter+=1
end

mean = 0.0

a.each { |element| mean +=element }

mean =mean/num1;

sum = 0.0

a.each { |element| sum = sum + (element - mean) ** 2}
    

# Variance is the average of the squared differences from the Mean
v = sum / num1
# Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
sd = v ** (1/ 2.0)

puts ("Mean = " + mean.to_s)
puts ("Variance = "+ v.to_s)
puts ("Standard Deviation = " + sd.to_s)


# OUTPUT :
# Enter number of elements in array :
# 5
# Enter your array:
# 1
# 2
# 3
# 4
# 5
# Mean = 3.0
# Variance = 2.0
# Standard Deviation = 1.4142135623730951