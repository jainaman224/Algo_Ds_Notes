#Enter the number below which you need to find prime numbers
#In this case 2..30

n = 2..30
o = []
p = []

puts "Following are the prime numbers smaller than or equal to 30"

#for loop iterates till n
for i in n
    next if o.include? i
    ii = i * 2
    while ii <= n.last do
        o << ii
        ii = ii + i

    end
#Print all the prime numbers less than or equal to the number
p << i unless o.include?(i)
  
    end

puts p.inspect

#Output

#Following are the prime numbers smaller than or equal to 30
#2 3 5 7 11 13 17 19 23 29

#
