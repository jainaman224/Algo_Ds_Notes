
class Graph
    attr_accessor :num_verticies

    def initialize(num_verticies)
        @num_verticies = num_verticies
        @adj_list = Array.new(num_verticies) {|i| Array.new}
    end

    def add_edge(source, destination)
        @adj_list[source].push(destination)
    end

    def dfs(start)
        used_verticies = Array.new(num_verticies, false)

        private_dfs(start, used_verticies)
        
    end

    private

    def private_dfs(vertex, used_verticies)
        print vertex, ' '
        used_verticies[vertex] = true

        @adj_list[vertex].each { |adj_vertex| 
            if used_verticies[adj_vertex] == false
            then private_dfs(adj_vertex, used_verticies)
            end
            
        }

    end

end 

def test1
    # create a graph with 8 verticies
    graph = Graph.new(8)

    # Create edges vetween verticies
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 2)
    graph.add_edge(1, 4)
    graph.add_edge(2, 0)
    graph.add_edge(2, 3)
    graph.add_edge(3, 3)
    graph.add_edge(3, 6)
    graph.add_edge(4, 0)
    graph.add_edge(4, 5)
    graph.add_edge(5, 6)
    graph.add_edge(5, 7)
    graph.add_edge(6, 2)
    graph.add_edge(7, 3)

    print "Depth First traversal is: "
    graph.dfs(0)
    puts ""

    # Expected Output
    # Depth First Traversal is: 0 1 2 3 6 4 5 7 
end

def test2
    # create a graph with 7 verticies
    graph = Graph.new(7)

    # Create edges vetween verticies
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(1, 4)
    graph.add_edge(2, 5)
    graph.add_edge(2, 6)

    print "Depth First traversal is: "
    graph.dfs(0)
    puts ""

    # Expected Output
    # Depth First Traversal is: 0 1 3 4 2 5 6
end

test1()
test2()

