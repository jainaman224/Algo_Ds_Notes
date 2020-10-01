Merge_Sort = (array) ->
    if array.length <= 1
        return array

    mid = Math.floor(array.length / 2)

    # Divide array into two halves
    left = Merge_Sort(array.slice 0, mid)
    right = Merge_Sort(array.slice mid)

    result = []
    p1 = p2 = 0

    # Conquer and merge array
    while true
        if p1 >= left.length
            if p2 >= right.length
                return result
            result.push right[p2]
            p2 += 1
        else if p2 >= right.length or left[p1] < right[p2]
            result.push left[p1]
            p1 += 1
        else
            result.push right[p2]
            p2 += 1

array = [2, 4, 3, 1, 6, 8, 4]

console.log Merge_Sort array


### Output

[ 1, 2, 3, 4, 4, 6, 8 ]

###
