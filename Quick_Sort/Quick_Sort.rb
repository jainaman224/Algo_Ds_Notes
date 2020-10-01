#Conquer
def Partition(array, left, right)
   pivot = array[left]
   index = right
   j = right
   for j in (right).downto(left)
       if array[j] > pivot
           array[index], array[j] = array[j], array[index]
           index -= 1
       end
   end
   array[index], array[left] = array[left], array[index]
   return index
 end

# Divide array into halves
def Quick(array, left, right)
   if left < right
       pivot = Partition(array, left, right)
       Quick(array, left, pivot - 1)
       Quick(array, pivot + 1, right)
   end
end

def Quick_Sort(array)
   Quick(array, 0, array.length - 1)
end
# Function to print array
def Print_Array(array)
    array.each do |val|
      print (val.to_s + " ")
    end
end
array = [2, 4, 3, 1, 6, 8, 4]

Quick_Sort(array)
Print_Array(array)

''' Output
1 2 3 4 4 6 8
'''
