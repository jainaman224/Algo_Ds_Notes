# Conquer
Parition = (array, left, right) ->
    pivot = array[left]
    index = right

    for j in [right...left - 1] by -1
        if array[j] > pivot
            [array[index], array[j]] = [array[j], array[index]]
            index -= 1

    [array[index], array[left]] = [array[left], array[index]]
    index

# Divide array into halves
Quick = (array, left, right) ->
    if left < right
        pivot = Parition array, left, right

        Quick array, left, pivot - 1
        Quick array, pivot + 1, right

Quick_Sort = (array) ->
    Quick array, 0, array.length - 1


array = [2, 4, 3, 1, 6, 8, 4]

Quick_Sort array

console.log array


### Output

[ 1, 2, 3, 4, 4, 6, 8 ]

###
