from math import sqrt

def update(index,value,blocks,a):
	blocks[int(index/sqrt(len(a)))] += value-a[index]
	a[index]=value

#assuming 0 based indexing
def query(low,high,blocks,a):
	block_size=int(sqrt(len(a)))
	total=0
	while(low % block_size!=0 and low<high):
		total+=a[low]
		low+=1
	
	while(low+block_size<=high):
		total+=blocks[low//block_size]
		low+=block_size
	
	while(low<=high):
		total+=a[low]
		low+=1
	return total

#divide the list in blocks of size sqrt(n), sum of elements in each block is stored in blocks
def formBlocks(a):
	block_size=int(sqrt(len(a)))
	index=-1
	blocks=[0]*(len(a)//block_size+1)
	for i in range(len(a)):
		if(i%block_size==0):
			index+=1
		blocks[index]+=a[i]
	return blocks

'''
Applying square root decomposition to perform range queries
	for finding the sum of numbers in a given range 
	Indexing : 0 based in list
'''
a=[2,3,4,6,8,9,1,-1,0,3]
blocks=formBlocks(a)
#queries
'''
input queries with left and right indices to find the sum in that range
'''
print(query(0,2,blocks,a))	#find sum from index 0 to index 2
#expected output : 9

print(query(3,7,blocks,a))	#find sum from index 3 to index 7
#expected output : 23

print(query(1,4,blocks,a))	#find sum from index 1 to index 4
#expected output : 21

#update 
update(3,1,blocks,a)		#update the value at index 3 with value of 1

#verify if the update was success
print(query(1,4,blocks,a))
#expected output : 18

