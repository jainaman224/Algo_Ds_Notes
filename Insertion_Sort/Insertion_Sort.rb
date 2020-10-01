#Function for insertion sort
def insertionSort (array)
  for i in 1 .. array.length - 1
    temp = array[i]                 #Store key value
    j = i - 1
    while j > 0 and array[j] > temp #Comparing with key and swapping accordingly
      array[j+1] = array[j]
      j = j - 1
    end
    array[j+1] = temp               #Final swap
  end
end

#Hardcoded array
array = [0,9,1,4,2]

#Pre sort array
print(array)

puts("\nAfter Sorting:\n")

insertionSort(array)

#Sorted Array
print(array)

#Output
#[0, 9, 1, 4, 2]
#[0, 1, 2, 4, 9]
