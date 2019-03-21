class disjointSets:

    def __init__(self,num):
        self.N=num
        self.rank=[0]*(num+1)
        self.parent=[0]*(num+1)
        for i in range(num+1):
            self.parent[i]=i

    def find(self,x):
        if(self.parent[x]!=x):
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def union(self,x,y):
        xr=self.find(x)
        yr=self.find(y)
        if(xr!=yr):
            if(self.rank[xr]<self.rank[yr]):

                self.parent[xr]=yr

            elif(self.rank[yr]<self.rank[xr]):

                self.parent[yr]=xr

            else:
                
                self.parent[yr]=xr
                self.rank[xr]=self.rank[xr]+1

# Example graph with two disjoint sets
''' 
1---2---3     6--4---5
'''
#number of nodes in the graph
n = 6
#initialize the disjoint set for n nodes   
d_set = disjointSets(n)
#number of edges
k = 4
edges=[]
edges.append([1,2]) #edge between 1 and 2
edges.append([2,3]) #edge between 2 and 3
edges.append([4,5]) #edge between 4 and 5
edges.append([4,6]) #edge between 4 and 6
edges.sort()
for i in range(k):
    d_set.union(edges[i][0],edges[i][1])

# check if 4 and 6 are in the same set
if(d_set.find(4)==d_set.find(6)):
    print("YES")
else:
    print("NO")
print("")
# check if 1 and 4 are in the same set
if(d_set.find(1)==d_set.find(4)):
    print("YES")
else:
    print("NO")
print("")

