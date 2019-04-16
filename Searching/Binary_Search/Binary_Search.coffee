Binary_Search = (array, desired) ->
    left = 0
    right = array.length - 1

    while left <= right
        middle = left + (right - left) / 2

        return middle if array[middle] is desired

        if desired < array[middle]
            right = middle - 1
        else
            left = middle + 1

    -1


array = [1, 2, 3, 4, 5, 6, 7]

index = Binary_Search array, 4

if index isnt -1
    console.log "Found"
else
    console.log "Not Found"

index = Binary_Search array, 9

if index isnt -1
    console.log "Found"
else
    console.log "Not Found"


### Output

Found
Not Found

###
