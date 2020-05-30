=begin
        Ternary Search
-------------------------------
Ternary search is a searching technique that is used to search the position of a specific value in an array.
Ternary search is a divide-and-conquer algorithm.
It is mandatory for the array to be sorted (in which you will search for an element).
The array is divided into three parts and then we determine in which part the element exists.
In this search, after each iteration it neglects ⅓ part of the array and repeats the same operations on the remaining ⅔.
Time Complexity: O(log3 n)
Space Complexity: O(1)
=end

def ternarySearch(l, r, key, ar) #function to perform ternary search

    if (r >= l)
        #find mid1 and mid2
        mid1 = l + (r - l) / 3
        mid2 = r - (r - l) / 3
        if ar[mid1] == key #check if key is equal to mid1
            mid1
        elsif ar[mid2] == key #check if key is equal to mid2
            mid2
        #Since key is not present at mid, check in which region it is present
        #then repeat the Search operation in that region 
        elsif key < ar[mid1] 
            ternarySearch(l, mid1 - 1, key, ar)
        elsif (key > ar[mid2]) 
            ternarySearch(mid2 + 1, r, key, ar)
        else 
            ternarySearch(mid1 + 1, mid2 - 1, key, ar) 
        end
    end
end
n= gets.to_i #length of array
arr = []
while n>0
  num = gets.chomp.to_i
  arr.push(num)
  n = n-1
end
number = gets.to_i #number whose index is to be searched
puts "Index of #{number} is #{ternarySearch(0, arr.length - 1, number, arr)}"

=begin
input->
5
21
34
54
67
78
67
output->
Index of 67 is 3
=end
