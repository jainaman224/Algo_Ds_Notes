def exponent(a, x):
    result = 1
    value = a

    while x != 0:
        if x & 1:
            result *= value
        value *= value

        x = int(x / 2)

    return result

base = 3
power = 5

print("Value of " + str(base) + " raise to the power " + str(power) + " is " + str(exponent(base, power)))

''' Output

Value of 3 raise to the power 5 is 243

'''
