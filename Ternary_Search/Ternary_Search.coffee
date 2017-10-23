# Function for Ternary Search
Ternary_Search = (array, left, right, desired) ->
    while left <= right
        # Return positon if found
        mid1 = left + Math.floor((right - left) / 3)
        mid2 = mid1 + Math.floor((right - left) / 3)

        return mid1 if array[mid1] is desired

        return mid2 if array[mid2] is desired

        return Ternary_Search array, left, mid1 - 1, desired if array[mid1] > desired

        return Ternary_Search array, mid2 + 1, right, desired if array[mid2] < desired

        return Ternary_Search array, mid1 + 1, mid2 - 1, desired

    -1

array = [1, 2, 3, 4, 5, 6, 7]

# Element to be searched is 4
if Ternary_Search(array, 0, 6, 4) isnt -1
    console.log "Found"
else
    console.log "Not Found"

# Element to be searched is 9
if Ternary_Search(array, 0, 6, 9) isnt -1
    console.log "Found"
else
    console.log "Not Found"


### Output

Found
Not Found

###
