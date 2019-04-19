LONG_INT_MAX = 1 << 64 - 1

def dijkstra(graph, source)
    number_vertex = graph.length

    # array that will store cost to vertices from source vertex
    distance = Array.new(number_vertex, LONG_INT_MAX)

    # array that shows vertices that are included in the shortest path tree
    shortest_path_tree = Array.new(number_vertex, false)
    distance[source] = 0

    for i in 0..number_vertex-1
        
        # finding vertex with shortest path from source vertex that is not shortest path tree
        pivot = -1
        for j in 0..number_vertex-1
            if shortest_path_tree[j] == false and (pivot == -1 or distance[j] < distance[pivot]) then
                pivot = j
            end
        end
        # include found vertex to the shortes path tree
        shortest_path_tree[pivot] = true

        # updating the weights of all adjacent vertices with 'pivot' vertex 
        for vertex in 0..number_vertex-1
            if shortest_path_tree[vertex] == false && graph[pivot][vertex] != 0 &&
                distance[pivot] + graph[pivot][vertex] < distance[vertex] then
                distance[vertex] = distance[pivot] + graph[pivot][vertex]            
            end
        end                  
    end

    puts "Distance from Source:"
    puts "Vertex\t\tDistance"
    for i in 0..number_vertex-1
        print i, "\t\t", distance[i], "\n"
    end
end

# creating 10x10 weight matrix for graph
graph = [[0, 14, 0, 7, 0, 0, 0, 8, 0, 10],
        [14, 0, 8, 0, 0, 0, 0, 11, 0, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2, 0],
        [7, 0, 7, 0, 9, 12, 0, 0, 0, 5],
        [0, 0, 0, 9, 0, 0, 0, 0, 0, 0],
        [0, 0, 4, 0, 0, 0, 2, 0, 0, 11],
        [0, 0, 0, 12, 0, 2, 0, 1, 6, 15],
        [8, 11, 0, 0, 0, 0, 1, 0, 7, 0],
        [0, 0, 2, 0, 0, 0, 6, 7, 0, 0],
        [10, 0, 0, 5, 0, 11, 15, 0, 0, 0]]

dijkstra(graph, 0);

=begin Output

    Distance from Source:
    Vertex		Distance
    0		0
    1		14
    2		14
    3		7
    4		16
    5		11
    6		9
    7		8
    8		15
    9		10

=end

