class Node:
    """
        A node class used in A* Pathfinding.
        parent: it is parent of current node
        position: it is current position of node in the maze.
        g: cost from start to current Node
        h: heuristic based estimated cost for current Node to end Node
        f: total cost of present node i.e. :  f = g + h
    """
    
    def __init__(self , parent=None , poistion=None):
        self.parent = parent
        self.position = poistion
        self.g = 0
        self.f = 0
        self.h = 0
        
    def __eq__(self , other):
        return self.position == other.position

class FindPath():
    def __init__(self , maze , cost , start , end):
        self.maze = maze
        self.cost = cost
        self.start = start
        self.end = end
        self.move = [ [-1, 0] , # go up
                      [ 0,-1] , # go left
                      [ 1, 0] , # go down
                      [ 0, 1] , # go right
                      [-1,-1] , # go left-up
                      [-1, 1] , # go left down
                      [ 1,-1] , # go right down
                      [ 1, 1] ] # go right up
        
    def return_path(self,curr_node,cost_matrix):
        path = []
        no_rows , no_columns = np.shape(cost_matrix)
        
        # here we create the initialized result maze with -1 in every position
        res = [[-1 for i in range(no_columns)] for j in range(no_rows)]
        
        #we will iterate over all parents of node and store in path
        curr = curr_node
        while curr is not None:
            path.append(curr.position)
            curr = curr.parent
        path = path[::-1]
        initial_value  = 0
        # we will insert the path in matrix
        for i in range(len(path)):
            res[path[i][0]][path[i][1]] = initial_value
            initial_value += 1
        return res
    
    def search(self):
        """
            Returns a list of tuples as a path from the given start to the given end in the given maze
        """
    
        # we will create start node and end node
        # we will initialize g, h and f value zero
        start_node = Node(None, tuple(self.start))
        start_node.g = 0
        start_node.h = 0
        start_node.f = 0
        
        end_node = Node(None, tuple(self.end))
        end_node.g = 0
        end_node.h = 0
        end_node.f = 0
        # we need to initialize both queue and visited list
        # we will find the lowest cost node to expand next
        queue = []  
        # we will store all visited node
        visited_list = [] 
        # Add the start node
        queue.append(start_node)
        # calculate the maximiuim number of steps we can move in the matrix
        counter = 0
        max_steps = (len(self.maze) // 2) ** 10
        # Get number of rows and columns
        no_rows, no_columns = np.shape(self.maze)
        # Loop until you find the end
        while len(queue) > 0:
            # Every time any node is visited increase the counter
            counter += 1   
            # Get the current node
            current_node = queue[0]
            current_index = 0
            for index, item in enumerate(queue):
                if item.f < current_node.f:
                    current_node = item
                    current_index = index
            # if we hit this point return the path such as it may be no solution or 
            # computation cost is too high
            if counter > max_steps:
                print ("Destination cannot be reached")
                return self.return_path(current_node , self.maze)
            # Pop current node out off
            queue.pop(current_index)
            # mark it visited
            visited_list.append(current_node)
            # check if goal is reached or not
            if current_node == end_node:
                return self.return_path(current_node , self.maze)
            # Generate coordinate from all adjacent coordinates
            coordinates = []
            for move in self.move: 
                # Get node position
                current_node_position = (current_node.position[0] + move[0] , current_node.position[1] + move[1])
                # check if all the moves are in maze limit
                if (current_node_position[0] > (no_rows - 1) or current_node_position[0] < 0 or current_node_position[1] > (no_columns -1) or current_node_position[1] < 0):
                    continue
                # Make sure walkable terrain
                if self.maze[current_node_position[0]][current_node_position[1]] != 0:
                    continue
                # Create new node
                new_node = Node(current_node , current_node_position)
                # Append
                coordinates.append(new_node)
            # Loop through children
            for child in coordinates:
                # Child is on the visited list (search entire visited list)
                if len([visited_child for visited_child in visited_list if visited_child == child]) > 0:
                    continue
                # calculate f, g, and h values
                child.g = current_node.g + self.cost
                # calculated Heuristic costs, this is using eucledian distance
                child.h = (((child.position[0] - end_node.position[0]) ** 2) + ((child.position[1] - end_node.position[1]) ** 2)) 
                child.f = child.g + child.h
                # Child if already in queue and g cost is already lower
                if len([i for i in queue if child == i and child.g > i.g]) > 0:
                    continue
                queue.append(child)
                
class Preprocess:
    def __init__(self , maze , n , m):
        self.maze = maze
        self.n = n
        self.m = m
    
    def check(self , value):
        data=''
        for i in range(len(value)):
            if(value[i] == '[' or value[i] == ']'):
                continue
            else:
                data+=value[i]
        return data
    
    def process_text(self):
        c=0
        matrix = self.maze
        matrix = matrix.split(',')
        data = []
        for i in range(self.n):
            l = []
            for j in range(self.m):
                
                l.append(int(self.check(matrix[c])))
                c += 1
            data.append(l)
        return data
    
if __name__ == '__main__':
    
    no_rows = int(input("Enter number of rows: "))
    no_cols = int(input("Enter number of columns: "))
    matrix  = Preprocess(str(input("Enter Matrix: ")) , no_rows , no_cols).process_text()
    start_x = int(input("Enter x coordinate of starting node: "))
    start_y = int(input("Enter y coordinate of starting node: "))
    end_x = int(input("Enter x coordinate of ending node: "))
    end_y = int(input("Enter y coordinate of ending node: "))
    cost = int(input("Enter cost: "))
    start = [start_x , start_y]
    end = [end_x , end_y]
    path = FindPath(matrix , cost , start , end).search()
    if(path != None):
        print("Path found: ")
        for i in range(len(path)):
            for j in range(len(path[i])):
                if(path[i][j] == -1):
                    print(0 , end=" ")
                else:
                    print(path[i][j] , end=" ")
            print()
    else:
        print("No Path found")

#input:
#    Enter number of rows: 5
#    Enter number of columns: 6
#    Enter Matrix: [[0, 1, 0, 0, 0, 0],
#                [0, 1, 0, 0, 0, 0],
#                [0, 1, 0, 1, 0, 0],
#                [0, 1, 0, 0, 1, 0],
#                [0, 0, 0, 0, 1, 0]]
#    Enter x coordinate of starting node: 0
#    Enter y coordinate of starting node: 0
#    Enter x coordinate of ending node: 4
#    Enter y coordinate of ending node: 5
#    Enter cost: 1
#Path found: 
#    0 0 0 0 0 0 
#    1 0 0 0 0 0 
#    2 0 0 0 7 0 
#    3 0 0 6 0 8 
#    0 4 5 0 0 9 
