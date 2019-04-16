getZarr = (str, Z) ->
    n = str.length
    Left = 0
    Right = 0

    for i in [1...n]
        if i > Right
            Left = i
            Right = i

            while Right < n and str[Right - Left] is str[Right]
                Right += 1

            Z[i] = Right - Left
            Right -= 1
        else
            k = i - Left

            if Z[k] < Right - i + 1
                Z[i] = Z[k]
            else
                Left = i

                while Right < n and str[Right - Left] is str[Right]
                    Right += 1

                Z[i] = Right - Left
                Right -= 1

    0 # Return 0


search = (text, pattern) ->
    concat = pattern + "$" + text
    size = concat.length
    Z = Array(size).fill(0)

    getZarr concat, Z

    for i in [0...size]
        if Z[i] is pattern.length
            console.log "Pattern found at " + (i - pattern.length)

    0 # Return 0

text = "namanchamanbomanamansanam"
pattern = "aman"

search text, pattern

### Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

###
