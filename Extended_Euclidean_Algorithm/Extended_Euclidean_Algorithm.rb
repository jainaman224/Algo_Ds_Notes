=begin
Extended Euclidean Algorithm 
==============================
GCD of two numbers is the largest number that divides both of them.
A simple way to find GCD is to factorize both numbers and multiply common factors.
  
GCD(a,b) = ax + by
If we can find the value of  x and y then we can easily find the 
value of GCD(a,b) by replacing (x,y) with their respective values.
=end

def extended_gcd(a, b, x, y) #Function for extended Euclidean Algorithm  
  
  #Base Case 
  return b if a == 0

  x1, y1 = 1, 1 #To store results of recursive call 
  gcd = extended_gcd(b % a, a, x1, y1)
  #Update x and y using results of recursive call  
  x = y1 - (b / a) * x1
  y = x1
  return gcd
end

x , y = 1, 1
a = gets.to_i
b = gets.to_i
puts "GCD of numbers #{a} and #{b} is #{extended_gcd(a, b, x, y)}"

=begin
INPUT:
27
81
OUTPUT:
GCD of numbers 27 and 81 is 27
=end
