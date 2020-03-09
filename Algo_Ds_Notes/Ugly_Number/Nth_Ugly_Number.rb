# Function that checks whether the Number is ugly or not
def Is_Ugly(x)
    m = 1
    while x != 1
        if x % 2 == 0
            x = x/2
        elsif x % 3 == 0
            x = x/3
        elsif x % 5 == 0
            x = x/5
        else
            m = 0
            break
        end
    end
    return m
end

print("Enter the Nth number")
# User Input of Nth number
n = gets.chomp.to_i
i = 1

# Finds the Nth ugly Number
while n != 1
    if Is_Ugly(i+1) == 1
        n = n-1
    end
    i = i+1
end

# Prints the ugly Number
print(i)

=begin
input:
Enter the Nth number: 10
output:
12
=end
