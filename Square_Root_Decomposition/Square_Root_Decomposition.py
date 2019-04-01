from math import sqrt

def update(index,value,blocks,input_arr):
    blocks[int(index/sqrt(len(input_arr)))] += value-input_arr[index]
    input_arr[index]=value

#assuming 0 based indexing
def query(low,high,blocks,input_arr):
    block_size=int(sqrt(len(input_arr)))
    total=0
    while(low % block_size!=0 and low<high):
        total+=input_arr[low]
        low+=1
    
    while(low+block_size<=high):
        total+=blocks[low//block_size]
        low+=block_size

    while(low<=high):
        total+=input_arr[low]
        low+=1
    return total

#divide the list in blocks of size sqrt(n), sum of elements in each block is stored in blocks
def formBlocks(input_arr):
    block_size=int(sqrt(len(input_arr)))
    index=-1
    blocks=[0]*(len(input_arr)//block_size+1)
    for i in range(len(input_arr)):
        if(i%block_size==0):
            index+=1
        blocks[index]+=input_arr[i]
    return blocks

'''
Applying square root decomposition to perform range queries
    for finding the sum of numbers in a given range 
    Indexing : 0 based in list
'''
input_arr=[2,3,4,6,8,9,1,-1,0,3]
blocks=formBlocks(input_arr)
#queries
'''
input queries with left and right indices to find the sum in that range
'''
print(query(0,2,blocks,input_arr)) #find sum from index 0 to index 2

print(query(3,7,blocks,input_arr)) #find sum from index 3 to index 7

print(query(1,4,blocks,input_arr)) #find sum from index 1 to index 4

#update 
update(3,1,blocks,input_arr)        #update the value at index 3 with value of 1

#verify if the update was success
print(query(1,4,blocks,input_arr))

'''
Expected output:
9
23
21
18
'''
