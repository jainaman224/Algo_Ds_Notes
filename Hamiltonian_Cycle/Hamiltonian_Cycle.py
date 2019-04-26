class Graph(): 
    def __init__(self, v): 
        self.graph = [[0 for column in range(v)]] 
        self.V = v  

    def isPathSafe(self, vertex, index, path): 

        # Checking if current vertex and last vertex in path are adjacent 
        if self.graph[path[index - 1]][vertex] == 0: 
            return False

         # Checking if current vertex not already in path 
        for v in path: 
            if v == vertex: 
                return False

        return True

    # Solving hamiltonian cycle problem recursively
    def helper(self, path, index): 

        if index == self.V: 
            if self.graph[path[index - 1]][path[0]] == 1: 
                return True
            else: 
                return False

        # Trying different vertices as a next candidate in Hamiltonian Cycle. 
        for vertex in range(1, self.V): 

            if self.isPathSafe(vertex, index, path) == True: 

                path[index] = vertex 

                if self.helper(path, index + 1) == True: 
                    return True

                path[index] = -1  

        return False

    def hamiltonian(self): 
        path = [-1] * self.V 

        # Putting vertex 0 as the first vertex in the path.
        path[0] = 0

        if self.helper(path, 1) == False: 
            print "Solution does not exist\n"
            return False  

        for vertex in path: 
            print vertex, 
        print path[0]
        
        print "\n"

        return True 

g = Graph(5) 
g.graph = [ [0, 1, 0, 1, 0], 
             [1, 0, 1, 1, 1],  
             [0, 1, 0, 0, 1],
             [1, 1, 0, 0, 1],  
             [0, 1, 1, 1, 0], 
            ] 

g.hamiltonian(); 

# Sample output
#  0  1  2  4  3  0
