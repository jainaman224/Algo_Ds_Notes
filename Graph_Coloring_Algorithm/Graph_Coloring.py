

class Graph(): 

	def __init__(self, number_of_vertices): 
		self.V = number_of_vertices 
		self.graph = [[0 for column in range(number_of_vertices)]] 

	# A function to check if the currently assigned colour is valid for vertex v 
	def Valid(self, vertex, colour, each_colour): 
		for i in range(self.V): 
			if self.graph[vertex][i] == 1 and colour[i] == each_colour: 
				return False
		return True
	
	# A recursive helper function to solve n different colours -> the coloring problem 
	def helper(self, number_of_colours, colour, v): 
		if v == self.V: 
			return True

		for each_colour in range(1, number_of_colours+1): 
			if self.Valid(v, colour, each_colour) == True: 
				colour[v] = each_colour 
				if self.helper(number_of_colours, colour, v+1) == True: 
					return True
				colour[v] = 0

	def Graph_Colouring(self, number_of_colours): 
		colour = [0] * self.V 
		if self.helper(number_of_colours, colour, 0) == False: 
			return False

		# The solution exists and print the solution according to assigned colours
		for each_colour in colour: 
			print each_colour, 
		return True

# Taking graph in a 2-D matrix
graph1 = Graph(4) 
graph1.graph = [[0,1,1,1], [1,0,1,0], [1,1,0,1], [1,0,1,0]] 


number_of_colours = 3
graph1.Graph_Colouring(number_of_colours) 


#   OUTPUT:

#   1 2 3 2


