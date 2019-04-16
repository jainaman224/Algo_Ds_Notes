exponent = (a, x) ->
    result = 1
    value = a

    while x isnt 0
        if x & 1
            result *= value
        value *= value

        x = Math.floor(x / 2)

    result

base = 3
power = 5

console.log "Value of " + base + " raise to the power " + power + " is " + exponent base, power


### Output

Value of 3 raise to the power 5 is 243

###
