# input should be list of integers
def pigeon_hole(input):
    # calculate size for list( no of pigeon holes)
    max_no = max(input) 
    min_no = min(input)
    size = max_no - min_no + 1
    
    # create holes
    holes = [0] * size
    # populate holes
    for i in input:
        holes[i- min_no] += 1
        
    # sort
    index = 0
    for i in range(size):
        while holes[i] > 0:
            holes[i] -= 1
            input[index] = i + min_no
            index = index + 1
    return input

print("Enter number of elements")
n = int(input())
print("Enter elements of array")
array = [int(x) for x in input().split(' ')]
pigeon_hole(array)
print(array)

'''
Input:
array = [1, 4, 32, 2]

Output 
array = [1, 2, 4, 32]
'''
