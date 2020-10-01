$temp = []
# Conquer
def conquer_merge(array, left, right, mid)
    #temp = [None] * len(array)
    i = left
    j = mid + 1
    k = left

    while i <= mid and j <= right
        if array[i] <= array[j]
            $temp[k] = array[i]
            i += 1
        else
            $temp[k] = array[j]
            j += 1
        end
        k += 1
    end
    while i <= mid
        $temp[k] = array[i]
        i += 1
        k += 1
    end
    while j <= right
        $temp[k] = array[j]
        j += 1
        k += 1
    end
    while left <= right
        array[left] = $temp[left]
        left += 1
    end
end

# Divide array into halves
def divide(array, left, right)
    if left < right
        mid = (left + (right - left) / 2).to_i

        divide(array, left, mid)
        divide(array, mid + 1, right)

        conquer_merge(array, left, right, mid)
    end
end

def Merge_Sort(array)
    $temp = [0] * array.length
    divide(array, 0, array.length - 1)
    $temp.clear
end

array = [2, 4, 3, 1, 6, 8, 4] #Hard Coded Array

Merge_Sort(array)

print(array)

# Output
# 1 2 3 4 4 6 8
