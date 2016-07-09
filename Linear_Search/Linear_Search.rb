#Method for Linear Search
def LinearSearch (array, searchedValue)
  array.each do |value|
    if value == searchedValue
      return "Value found."
    end
  end
  return "Value not found."
end

#Hardcoded Array
array = [9,1,2,0,3]

print(array)

#Searching for 0
puts("\nSearching for 0 in the array: ")
print(LinearSearch(array,0))

#Searching for 4
puts("\nSearching for 4 in the array: ")
print(LinearSearch(array,4))


#Output
#[9, 1, 2, 0, 3]
#Searching for 0 in the array: Value found.
#Searching for 4 in the array: Value not found.
