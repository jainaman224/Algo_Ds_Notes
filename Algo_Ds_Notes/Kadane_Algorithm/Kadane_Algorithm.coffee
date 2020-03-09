kadane = (input) ->
    current_max = 0
    max_so_far = 0

    for i in [0...input.length]
        current_max += input[i]
        if current_max < 0
            current_max = 0

        if max_so_far < current_max
            max_so_far = current_max

    max_so_far

input = [-2, 1, -6, 4, -1, 2, 1, -5, 4]

flag = 0
largest_in_negative = input[0]

for i in [0...input.length]
    if input[i] >= 0
        flag = 1
        break
    else if input[i] > largest_in_negative
        largest_in_negative = input[i]

if flag is 1
    max_subarray_sum = kadane input
else
    max_subarray_sum = largest_in_negative

console.log "Maximum Subarray Sum is " + max_subarray_sum


### Output

Maximum Subarray Sum is 6

###
