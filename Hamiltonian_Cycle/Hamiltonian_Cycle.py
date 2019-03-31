class Graph(): 
    def __init__(self, vertices): 
        self.graph = [[0 for column in range(vertices)]\
                            for row in range(vertices)] 
        self.V = vertices  

    def isSafe(self, v, pos, path): 
        # Checking if current vertex and last vertex in path are adjacent 
        if self.graph[ path[pos-1] ][v] == 0: 
            return False

        # Checking if current vertex not already in path 
        for vertex in path: 
            if vertex == v: 
                return False
  
        return True
  
    # Solving hamiltonian cycle problem recursively
    def hamCycleUtil(self, path, pos): 
  
        if pos == self.V: 
            if self.graph[ path[pos-1] ][ path[0] ] == 1: 
                return True
            else: 
                return False
  
        # Trying different vertices as a next candidate in Hamiltonian Cycle. 
        for v in range(1,self.V): 
  
            if self.isSafe(v, pos, path) == True: 
  
                path[pos] = v 
  
                if self.hamCycleUtil(path, pos+1) == True: 
                    return True
                path[pos] = -1  

        return False
  
    def hamCycle(self): 
        path = [-1] * self.V 
  
        # Putting vertex 0 as the first vertex in the path.
        path[0] = 0
  
        if self.hamCycleUtil(path,1) == False: 
            print "Solution does not exist\n"
            return False  
        self.printSolution(path) 
        
        return True
  
    def printSolution(self, path): 
        print "Solution Exists: Following is one Hamiltonian Cycle"
        for vertex in path: 
            print vertex, 
        print path[0], "\n"

g1 = Graph(5) 
g1.graph = [ [0, 1, 0, 1, 0], 
             [1, 0, 1, 1, 1],  
             [0, 1, 0, 0, 1],
             [1, 1, 0, 0, 1],  
             [0, 1, 1, 1, 0], 
            ] g1.hamCycle(); 

g2 = Graph(5) 
g2.graph = [ [0, 1, 0, 1, 0],
             [1, 0, 1, 1, 1],
             [0, 1, 0, 0, 1],
             [1, 1, 0, 0, 0],  
             [0, 1, 1, 0, 0],
            ] g2.hamCycle();

# Solution Exists: Following is one Hamiltonian Cycle
#  0  1  2  4  3  0
