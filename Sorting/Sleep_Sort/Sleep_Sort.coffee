After = (s, f) -> setTimeout f, s*1000

Sleep_Sort = (array) ->
    for n in array
        do (n) -> After n, -> console.log n

do ->
    array = [2, 4, 3, 1, 6, 8, 4]
    Sleep_Sort array

### Output

1
2
3
4
4
6
8

###
