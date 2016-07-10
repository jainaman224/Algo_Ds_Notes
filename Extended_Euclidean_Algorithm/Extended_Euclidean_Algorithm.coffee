gcdFunction = (a, b, x, y) ->
    if a is 0
        x = 0
        y = 1
        return b

    x1 = 0
    y1 = 0
    gcd = gcdFunction b % a, a, x1, y1

    x = y1 - Math.floor (b / a) * x1
    y = x1

    gcd

a = 98
b = 21
x = 0
y = 0

console.log "GCD of numbers " + a + " and " + b + " is " + gcdFunction a, b, x, y


### Output

GCD of numbers 98 and 21 is 7

###
