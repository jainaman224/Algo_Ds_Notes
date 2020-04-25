=begin 
Problem Statement- Given two sequences, find 
the length of longest subsequence present in both of them. 
A subsequence is a sequence that can be derived 
from another sequence by deleting some or 
no elements without changing the order of the remaining elements.
=end

def longest_common_subsequence(arr1, arr2, size1, size2) 
    lcs = Array.new(size1 + 1){Array.new(size2 + 1)}
    
    for i in 0..size1
        for j in 0..size2
            if (i == 0 || j == 0) 
                lcs[i][j] = 0    
            # when the last character of both subsequences match, 
            # increase length of lcs by 1
            elsif (arr1[i - 1] == arr2[j - 1]) 
                lcs[i][j] = lcs[i - 1][j - 1] + 1
            # when the last character is not same, 
            # take maximum obtained by adding
            # one character to one of the subsequences 
            else
                lcs[i][j] = [lcs[i - 1][j], lcs[i][j - 1]].max
            end
        end 
    end
    
    lcs[size1][size2]
end 

# Driver Code
puts "Enter the size of first array:"
size1 = gets.to_i

puts "Enter the first array elements:"
arr1 = gets.split(" ").map(&:to_i)

puts "Enter the size of second array:"
size2 = gets.to_i

puts "Enter the second array elements:"
arr2 = gets.split(" ").map(&:to_i)

len = longest_common_subsequence(arr1, arr2, size1, size2)
puts "Length of Longest Common Subsequence is: #{len}"

=begin
Enter the size of first array:
7
Enter the first array elements:
10 15 20 25 30 35 40
Enter the size of second array:
8
Enter the second array elements:
10 12 23 25 28 30 32 40
Length of Longest Common Subsequence is: 4
=end
