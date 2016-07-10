gcdFunction = (x, y) ->
    if x is 0
        y
    else
        gcdFunction y % x, x

x = 462
y = 780

console.log "GCD of numbers " + x + " and " + y + " is " + gcdFunction x, y


### Output

GCD of numbers 462 and 780 is 6

###
