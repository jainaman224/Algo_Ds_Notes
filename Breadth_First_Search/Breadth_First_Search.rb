=begin
    Code contributed by Hardev Khandhar for GirlScript Summer of Code 2020
    link: https://github.com/HardevKhandhar
=end

## Breadth First Search algorithm in Ruby.

def breadth_first_search(adj_matrix, source, destination)
  node_array = [source]
  path = []
  puts "\nThe initial NODE ARRAY is #{node_array}."

  loop do
    curr_node = node_array.pop
    path << curr_node
    puts "The next node to be checked is #{curr_node}."
    
    if curr_node.nil?
      puts 'Destination Node Not Found!'
      return false
    
    elsif curr_node == destination
      puts "Destination Node #{curr_node} Found!"
      puts "\nThe path between Source Node #{source} and Destination Node #{destination} is:\n #{path}."
      return true
    
    end

    puts "\nIterating through the following array:\n  #{adj_matrix[curr_node]}"
    puts
    children = (0..adj_matrix.length - 1).to_a.select do |i|
      puts "Checking index #{i} whose value is #{adj_matrix[curr_node][i]}"
      adj_matrix[curr_node][i] == 1
    
    end
    
    puts "\nCHILD ARRAY returned: #{children}"
    node_array = children + node_array
    puts "\nAfter appending CHILD ARRAY, NODE ARRAY is: #{node_array}"
  
  end

end

## Defining Adjacency Matrix by taking user input

puts "Enter Size of Adjacency Matrix: "
size = gets.to_i

adj_matrix = Array.new(size) { [] }

i = 0
counter = 0

while(counter != size)
  i = 0
  puts "\nEnter the values of row #{counter + 1}: "
  while(i != size)
      adj_matrix[counter][i] = gets.to_i
      i += 1
  end
  counter += 1
end

## User input for Source Node and Destination Node

puts "\nEnter Source Node: "
source = gets.to_i

puts "\nEnter Destination Node: "
destination = gets.to_i

## Passing the adjacent matrix, source and destination as arguments to the algorithm.

breadth_first_search(adj_matrix, source, destination)

=begin

Enter Size of Adjacency Matrix: 
 18

Enter the values of row 1: 
 0
 1
 1
 1
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 2: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 1

Enter the values of row 3: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 4: 
 0
 0
 0
 0
 1
 1
 1
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 5: 
 0
 0
 0
 0
 0
 0
 0
 1
 1
 1
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 6: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 1
 1
 1
 0
 0
 0
 0
 0

Enter the values of row 7: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 1
 1
 1
 0
 0

Enter the values of row 8: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 9: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 10: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 11: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 12: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 13: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 14: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 15: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 16: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 1
 0

Enter the values of row 17: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter the values of row 18: 
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0
 0

Enter Source Node: 
 0

Enter Destination Node: 
 17

The initial NODE ARRAY is [0].
The next node to be checked is 0.

Iterating through the following array:
  [0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 1
Checking index 2 whose value is 1
Checking index 3 whose value is 1
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: [1, 2, 3]

After appending CHILD ARRAY, NODE ARRAY is: [1, 2, 3]
The next node to be checked is 3.

Iterating through the following array:
  [0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 1
Checking index 5 whose value is 1
Checking index 6 whose value is 1
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: [4, 5, 6]

After appending CHILD ARRAY, NODE ARRAY is: [4, 5, 6, 1, 2]
The next node to be checked is 2.

Iterating through the following array:
  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: []

After appending CHILD ARRAY, NODE ARRAY is: [4, 5, 6, 1]
The next node to be checked is 1.

Iterating through the following array:
  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 1

CHILD ARRAY returned: [17]

After appending CHILD ARRAY, NODE ARRAY is: [17, 4, 5, 6]
The next node to be checked is 6.

Iterating through the following array:
  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 1
Checking index 14 whose value is 1
Checking index 15 whose value is 1
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: [13, 14, 15]

After appending CHILD ARRAY, NODE ARRAY is: [13, 14, 15, 17, 4, 5]
The next node to be checked is 5.

Iterating through the following array:
  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 0
Checking index 8 whose value is 0
Checking index 9 whose value is 0
Checking index 10 whose value is 1
Checking index 11 whose value is 1
Checking index 12 whose value is 1
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: [10, 11, 12]

After appending CHILD ARRAY, NODE ARRAY is: [10, 11, 12, 13, 14, 15, 17, 4]
The next node to be checked is 4.

Iterating through the following array:
  [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]

Checking index 0 whose value is 0
Checking index 1 whose value is 0
Checking index 2 whose value is 0
Checking index 3 whose value is 0
Checking index 4 whose value is 0
Checking index 5 whose value is 0
Checking index 6 whose value is 0
Checking index 7 whose value is 1
Checking index 8 whose value is 1
Checking index 9 whose value is 1
Checking index 10 whose value is 0
Checking index 11 whose value is 0
Checking index 12 whose value is 0
Checking index 13 whose value is 0
Checking index 14 whose value is 0
Checking index 15 whose value is 0
Checking index 16 whose value is 0
Checking index 17 whose value is 0

CHILD ARRAY returned: [7, 8, 9]

After appending CHILD ARRAY, NODE ARRAY is: [7, 8, 9, 10, 11, 12, 13, 14, 15, 17]
The next node to be checked is 17.
Destination Node 17 Found!

The path between Source Node 0 and Destination Node 17 is:
 [0, 3, 2, 1, 6, 5, 4, 17].

=end
    