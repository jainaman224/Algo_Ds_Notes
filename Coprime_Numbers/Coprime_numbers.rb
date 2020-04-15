=begin
Two integers a and b are said to be coprime if the only positive
integer that divides both of them is 1 i.e their greatest common 
divisor or GCD is 1.

Example: 5 and 7, as gcd(5, 7) = 1
9 and 11, as gcd(9, 11) = 1
=end

def isCoprime(a,b) #function to check if two numbers are coprimes
    if a.gcd(b)==1
       return 1
    else
       return 0
    end
end


a= gets.to_i
b= gets.to_i
answer= isCoprime(a,b)
if answer==1
    puts "The numbers are coprime"
else
    puts "The numbers are not coprime"
end


=begin
Input:
3
5
Output:
The numbers are coprime
Input:
9
45
Output:
The numbers are not coprime
=end