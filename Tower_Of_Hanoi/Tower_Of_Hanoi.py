# Tower of Hanoi problem using recursion

def TowerOfHanoi(num, source, destination, auxillary): 
	if num == 1: 
		print("Move disk 1 from rod", source, "to rod", destination)
		return
	TowerOfHanoi(num - 1, source, auxillary, destination) 
	print("Move disk", num, "from rod", source, "to rod", destination)
	TowerOfHanoi(num - 1, auxillary, destination, source) 
		
# Main code
num = int(input("Enter the number"))
TowerOfHanoi(num, 'A', 'C', 'B') 
# A, C, B are the name of rods 
# A is source rod, B is auxillary rod, C is destination rod
