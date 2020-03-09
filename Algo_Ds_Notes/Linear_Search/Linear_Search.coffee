Linear_Search = (array, desired) ->
    for x in array
        return true if x is desired

    false

array = [2, 4, 6, 7, 3, 1, 5]

if Linear_Search array, 4
    console.log "Found"
else
    console.log "Not Found"

if Linear_Search array, 9
    console.log "Found"
else
    console.log "Not Found"

### Output

Found
Not Found

###
