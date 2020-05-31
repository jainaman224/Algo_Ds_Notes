# Karatsuba Algorithm In Ruby 

= begin

    The Karatsuba Algorithm is a fast multiplication algorithm. 
    It was discovered by Anatoly Karatsuba in 1960. It reduces 
    the multiplication of two n-digit numbers to at most single 
    digit multiplications in general. It is therefore faster 
    than classical multiplication operation.

= end

def karatsuba(num1, num2) 

    num1, num2 = num1.to_s, num2.to_s
    num1_mid_point = (num1.length / 2)
    num2_mid_point = (num2.length / 2)

    a = num1[0...num1_mid_point].to_i
    b = num1[num1_mid_point..-1].to_i
    c = num2[0...num2_mid_point].to_i
    d = num2[num2_mid_point..-1].to_i   

    # Step 1: Computing the products of a * c 
    a_c = a * c

    # Step 2: Computing the products of a * c 
    b_d = b * d

    # Step 3: Computing the products of (a+b) and (c+d)
    sum_product = ((a + b) * (c + d))

    # Step 4: Subtracting first two products from Step 3
    sub_products = sum_product - (a_c + b_d)

    # Step 5: Padding summation
    result = (a_c * (10 ** num1.length)) + b_d + (sub_products * (10 ** num1_mid_point))

end

puts "Enter The First Number: "
x = gets.to_i

puts "Enter The Second Number: "
y = gets.to_i
puts

answer = karatsuba(x, y)
puts "Result: ", answer
puts

# Sample Input and Output

= begin

Enter The First Number: 121547
Enter The Second Number: 1855324

Result: 23133311228

--------------------------------------------------

Enter The First Number: -8859460
Enter The Second Number: 1154486

Result: -10206279662440

= end
