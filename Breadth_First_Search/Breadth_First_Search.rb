=begin
    Code contributed by Hardev Khandhar for GirlScript Summer of Code 2020
    link: https://github.com/HardevKhandhar
=end

## Breadth First Search algorithm in Ruby.

def breadth_first_search(adj_matrix, source, destination)
    node_array = [source]
    path = []
    ## puts "\nThe initial NODE ARRAY is #{node_array}."
    
    loop do
        curr_node = node_array.pop
        path << curr_node
        ## puts "The next node to be checked is #{curr_node}."

        if curr_node.nil?
            puts 'Destination Node Not Found!'
            return false

        elsif curr_node == destination
            puts "\nDestination Node #{curr_node} Found!"
            puts "\nThe path between Source Node #{source} and Destination Node #{destination} is:\n #{path}."
            return true

        end

        ## puts "\nIterating through the following array:\n  #{adj_matrix[curr_node]}"
        children = (0..adj_matrix.length - 1).to_a.select do |i|
        ## puts "Checking index #{i} whose value is #{adj_matrix[curr_node][i]}"
        adj_matrix[curr_node][i] == 1

        end

        ## puts "\nCHILD ARRAY returned: #{children}"
        node_array = children + node_array
        ## puts "\nAfter appending CHILD ARRAY, NODE ARRAY is: #{node_array}"

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

Enter Size of Adjacency Matrix: 4

Enter the values of row 1: 0 1 1 0

Enter the values of row 2: 1 0 0 0

Enter the values of row 3: 1 0 1 0

Enter the values of row 4: 0 1 0 0

Enter Source Node: 0

Enter Destination Node: 2

Destination Node 2 Found!

The path between Source Node 0 and Destination Node 2 is:
 [0, 2].

=end
    