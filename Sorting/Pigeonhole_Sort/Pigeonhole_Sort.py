# input should be list of integers
def pigeon_hole(input):
    # calculate size for list( no of pigeon holes)
    max_no = max(input) 
    min_no = min(input)
    size = max_no - min_no + 1
    
    # create holes
    holes = [0]*size
    # populate holes
    for i in input:
        holes[i- min_no]+=1
        
    # sort
    index = 0
    for i in range(size):
        while holes[i]>0:
            holes[i] -=1
            input[index] = i + min_no
            index+=1
    return input
    
test = pigeon_hole([2,3,5,4])
print(test) 

#input = [2,3,5,4]
#output = [2,3,4,5]
