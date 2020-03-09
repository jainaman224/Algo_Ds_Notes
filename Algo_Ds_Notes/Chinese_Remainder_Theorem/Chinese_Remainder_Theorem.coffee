inverse = (a, m) ->
    m0 = m
    x0 = 0
    x1 = 1

    return 0 if m is 1

    while a > 1
        q = Math.floor a / m
        t = m
        m = a % m
        a = t
        t = x0
        x0 = x1 - q * x0
        x1 = t

    if x1 < 0
        x1 += m0

    x1

findMinimumDividend = (divisor, remainder) ->
    product = 1

    for i in [0...divisor.length]
        product *= divisor[i]

    result = 0

    for i in [0...divisor.length]
        partialProduct = product / divisor[i]
        inverseAns = inverse partialProduct, divisor[i]
        result += remainder[i] * partialProduct * inverseAns

    result % product

divisor = [3, 4, 5, 7, 11]
remainder = [2, 3, 1, 4, 5]

console.log "Minimum value of dividend is " + findMinimumDividend divisor, remainder


### Output

Minimum value of dividend is 3371

###
