#Function for Selection_Sort
def Selection_Sort (array)
  for i in (0 .. array.length - 2)
    min_index = i
    for j in (i + 1 .. array.length - 1)
      if (array[j] < array[min_index])
        min_index = j
      end
    end
    if i != min_index     #Swap if required
      temp = array[min_index]
      array[min_index] = array[i]
      array[i] = temp
    end
  end
end

array = [0,9,2,1,3,5] #Hard-coded Array

puts("Array before sorting: ")

print(array)

puts("\nArray after sorting: ")

Selection_Sort(array)

print(array)

#OutPut

#Array before sorting:
#[0, 9, 2, 1, 3, 5]
#Array after sorting:
#[0, 1, 2, 3, 5, 9]
