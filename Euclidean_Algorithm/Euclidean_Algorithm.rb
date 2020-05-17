# Given two numbers, we need to find the greatest common divisor of those two numbers

def gcd(x, y)
    # every number divides 0
    if (x == 0)
        return y
    else 
        return gcd(y % x, x)
    end
end

# Driver Code
puts "Enter first number:"
x = gets.to_i

puts "Enter second number:"
y = gets.to_i

puts "GCD of numbers #{x} and #{y} is #{gcd(x, y)}"

=begin
Enter first number:
462

Enter second number:
780

Output:
GCD of numbers 462 and 780 is 6
=end
