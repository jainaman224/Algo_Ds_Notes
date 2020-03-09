search = (text, pattern) ->
    lengthText = text.length
    lengthPattern = pattern.length

    for i in [0...lengthText - lengthPattern]
        j = 0

        while j < lengthPattern
            break if text[i + j] isnt pattern[j]

            j += 1

        if j is lengthPattern
            console.log "Pattern found at " + (i + 1)

    0 # Return 0

text = "namanchamanbomanamansanam"
pattern = "aman"
search text, pattern


### Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

###
