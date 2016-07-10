Max_Element = (array) ->
    max = array[0]

    for i in [1...array.length]
        if array[i] > max
            max = array[i]

    max

Counting_Sort = (array, exp) ->
    size = array.length
    output = Array(size).fill(0)
    count = Array(10).fill(0)

    for i in [0...size]
        count[Math.floor(array[i] / exp) % 10] += 1

    for i in [1...10]
        count[i] += count[i - 1]

    # Both a and b are inclusive when we use [a..b]
    for i in [size - 1..0] by -1
        output[count[Math.floor(array[i] / exp) % 10] - 1] = array[i]
        count[Math.floor(array[i] / exp) % 10] -= 1

    for i in [0...size]
        array[i] = output[i]

Radix_Sort = (array) ->
    maximum = Max_Element array

    exp = 1
    while Math.floor(maximum / exp) > 0
        Counting_Sort array, exp
        exp *= 10

    0 # Return 0

array = [170, 45, 75, 90, 802, 24, 2, 66]

Radix_Sort array
console.log array


### Output

[ 2, 24, 45, 66, 75, 90, 170, 802 ]

###
