# A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if
# abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ....

# To calculate the order of the number
def order(num)
    # variable to store of the number
    count = 0
    while (num != 0)
        count = count + 1
        num = num / 10
    end
    return count
end

# Function to check whether the given number is
# Armstrong number or not
def Armstrong(num)
    count = order(num)
    temp = num
    sum = 0
    boolean = false
    while (temp != 0)
        d = temp % 10
        sum = sum + d ** count
        temp = temp / 10
    end
    return num == sum
end

# Driver Program
num = gets.chomp.to_i
print(Armstrong(num))

#True

#num = 134
#print(Armstrong(num))

#False

#num = 370
#print(Armstrong(num))

#True
