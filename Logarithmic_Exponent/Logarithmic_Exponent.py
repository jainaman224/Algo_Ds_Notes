def exponent(a, x):
    result = 1
    value = a
    while x != 0:
        if x & 1:
            result *= value
        value *= value
        x = int(x / 2)
    return result

base = int(input())
power = int(input())
print("Value of " + str(base) + " raise to the power " + str(power) + " is " + str(exponent(base, power)))

''' 
Input :
base = 2, power = 32
Output:
Value of 2 raised to the power 32 is 4294967296
'''
