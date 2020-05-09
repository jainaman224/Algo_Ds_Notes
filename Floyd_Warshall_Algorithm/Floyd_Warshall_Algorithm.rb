## Floyd Warshall Algorithm In Ruby

def floyd_warshall(node, edge)
    dist = Array.new(node){|i| Array.new(node){|j| i == j ? 0 : Float::INFINITY}}
    next_node = Array.new(node){Array.new(node)}
    edge.each do |u, v, w|
        dist[u - 1][v - 1] = w
        next_node[u - 1][v - 1] = v - 1
    end

    node.times do |k|
        node.times do |i|
            node.times do |j|
                if dist[i][j] > dist[i][k] + dist[k][j]
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next_node[i][j] = next_node[i][k]
                end
            end
        end
    end

    ## Displaying The Output
    puts "Pair     Distance      Path"
    node.times do |i|
        node.times do |j|
            next if i == j
            u = i
            path = [u]
            path << (u = next_node[u][j])  while u != j
            path = path.map{|u| u + 1}.join(" -> ")
            puts "%d -> %d  %6d         %s" % [i + 1, j + 1, dist[i][j], path]
        end
    end
end

## User Input For Number Of Nodes
puts "Enter the number of Nodes: "
nodes = gets.to_i

## User Input For Number Of Edge Pairs
puts "Enter number of Edge Pairs: "
pair = gets.to_i

puts "\nFor Edge Matrix, Enter Starting Node, Ending Node & Distance Between Them..."

edge_matrix = Array.new(pair) { Array.new(3) }

i = 0
counter = 0

while(counter != pair)
    i = 0
    puts "\nEnter the values of row #{counter + 1}: "
    while(i != 3)
        edge_matrix[counter][i] = gets.to_i
        i += 1
    end
    counter += 1
end

puts

floyd_warshall(nodes, edge_matrix)

= begin

Enter the number of Nodes: 4
Enter number of Edge Pairs: 5

For Edge Matrix, Enter Starting Node, Ending Node & Distance Between Them...

Enter the values of row 1: 1 3 -2

Enter the values of row 2: 2 1 4

Enter the values of row 3: 2 3 3

Enter the values of row 4: 3 4 2

Enter the values of row 5: 4 2 -1

Pair     Distance      Path
1 -> 2      -1         1 -> 3 -> 4 -> 2
1 -> 3      -2         1 -> 3
1 -> 4       0         1 -> 3 -> 4
2 -> 1       4         2 -> 1
2 -> 3       2         2 -> 1 -> 3
2 -> 4       4         2 -> 1 -> 3 -> 4
3 -> 1       5         3 -> 4 -> 2 -> 1
3 -> 2       1         3 -> 4 -> 2
3 -> 4       2         3 -> 4
4 -> 1       3         4 -> 2 -> 1
4 -> 2      -1         4 -> 2
4 -> 3       1         4 -> 2 -> 1 -> 3

= end
