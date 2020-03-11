#Digit count of given number

puts "Enter the number : "
num = gets.chomp.to_i

temp = num
count = 0

if temp == 0
    count = 1 
end

if temp < 0
    temp = temp * -1
end

#Loop to determine the number of digits
while (temp > 0)
    count += 1
    temp = temp / 10
end

puts "The given number #{num} has #{count} digits in it"

#SAMPLE INPUT AND OUTPUT
=begin
#SAMPLE 1
Enter the number : 1235
The given number 1235 has 4 digits
#SAMPLE 2
Enter the number : -87
The given number -87 has 2 digits
=end

