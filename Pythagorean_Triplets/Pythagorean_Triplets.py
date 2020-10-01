'''
PYTHAGOREAN TRIPLETS

Three numbers - a, b and c are said to be pythagorean triplets if following
formula holds :

a^2 + b^2 = c^2
'''

a = int(input(("Enter a: ")))
b = int(input(("Enter b: ")))
c = int(input(("Enter c: ")))
sq_a = a * a
sq_b = b * b
sq_c = c * c
if (sq_a + sq_b == sq_c or sq_a + sq_c == sq_b or sq_b + sq_c == sq_a):
    print("It is a pythagorean triplet")
else:
    print("It is not a pythagorean triplet")

'''
    INPUT : a = 8 b = 6 c = 10
    OUTPUT: It is a pythagorean triplet
    VERIFICATION : 6^2 + 8^2 = 36 + 64 = 100
                   10^2 = 100
'''
