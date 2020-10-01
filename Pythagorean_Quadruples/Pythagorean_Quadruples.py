'''
PYTHAGOREAN QUADRUPLES

Four numbers - a, b , c and d are said to be pythagorean quadruples if following
formula holds :

a^2 + b^2 + c^2 = d^2
'''

a = int(input(("Enter a: ")))
b = int(input(("Enter b: ")))
c = int(input(("Enter c: ")))
d = int(input(("Enter d: ")))
sq_a = a * a
sq_b = b * b
sq_c = c * c
sq_d = d * d
if sq_a + sq_b + sq_d == sq_c or sq_a + sq_c + sq_d == sq_b \
   or sq_b + sq_c + sq_d == sq_a or sq_a + sq_b + sq_c == sq_d:
    print("It is a pythagorean quadruple")
else:
    print("It is not a pythagorean quadruple")

'''
    INPUT : a = 3 b = 6 c = 2 d = 7
    OUTPUT: It is a pythagorean quadruple
    VERIFICATION : 3^2 + 6^2 + 2^2 = 9 + 36 + 4 = 49
                   7^2 = 49
'''
