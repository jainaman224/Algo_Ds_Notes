# Finding greatest common divisor using Euclidean Algorithm
gcdFunction = (a, b) ->
    return b if a is 0

    gcdFunction b % a, a

power = (x, y, m) ->
    return 1 if y is 0

    p = power(x, Math.floor(y / 2), m) % m
    p = (p * p) % m

    if y % 2 is 0
        p
    else
        (x * p) % m

modInverse = (a, m) ->
    gcd = gcdFunction a, m

    if gcd isnt 1
        -1
    else
        power a, m - 2, m


a = 3
m = 11

ans = modInverse a, m

if ans is -1
    console.log "Inverse doesn't exist"
else
    console.log "Modular multiplicative inverse is " + ans


### Output

Modular multiplicative inverse is 4

###
