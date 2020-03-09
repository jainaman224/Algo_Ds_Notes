# Function for selection sort
Selection_Sort = (array) ->
    for i in [0...array.length - 1]
        min_index = i

        for j in [i + 1...array.length]
            if array[j] < array[min_index]
                min_index = j

        [array[i], array[min_index]] = [array[min_index], array[i]]
    array

array = [2, 4, 3, 1, 6, 8, 4]

console.log Selection_Sort array


### Output

[ 1, 2, 3, 4, 4, 6, 8 ]

###
