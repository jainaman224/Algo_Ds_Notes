'''Segment Tree with Lazy Propagation is used when you want to perform some operation
within an array range with range updation. Let's us suppose you want to perform minimum
operation in certain range[a:b+1] and after performing minimum operation you are updating
array index in range [l:r+1]. If you apply brute force approach then you will end
up with O(n^2) complexity. If you use segment tree then your algorithm complexity will be
O(nlogn) i.e. more efficient than bruteforce approach.

'''

INF = 99999
tree = [0]*1000
lazy = [0]*1000

# Build Segment Tree
def build_tree(arr, node, start, end):
    
    '''Input
        arr: Input array
       node: Current node of tree
      start: starting index of input array i.e 0
        end: Last index of input array i.e. len(arr)-1
    '''
    if start > end:
        return
    if start == end:
        tree[node] = arr[start]
        return
    
    # Build left child
    build_tree(arr, node*2, start, (start+end)// 2)
    # Build right child
    build_tree(arr, node*2+1, (start+end)//2+1, end)
    # Perform min operation to store our required value in tree node.
    tree[node] = min(tree[node*2], tree[node*2+1])

# Increment all values from index x to y by val
def update(node, start, end, val, x, y):

    '''Input
         node: Current node
        start: Starting index of input array
          end: Last index of input array
          val: The val you want to increase
       [x..y]: Increment value in range [x,y] by val  
    
    '''
    if lazy[node] != 0:
         
         # Update tree node
         tree[node] += lazy[node]

         if start != end:
              # Mark childs as lazy
              lazy[node*2] += lazy[node]
              lazy[node*2] += lazy[node]
         # Reset lazy node     
         lazy[node] = 0
    
    # If Segment Tree is not in the range[x..y] i.e. range[x..y] is not feasible
    if start > end or start > y or end < x:
         return
    
    # If given range[x..y] is feasible
    if start >= x and end <= y:

         # Increment current tree node by val
         tree[node] += val

         if start != end:
              
              # Increment left lazy child by val
              lazy[node*2] += val
              # Increment right lazy child
              lazy[node*2+1] += val
         return
    
    # Update left child
    update(node*2, start, (start+end)//2, val, x, y)
    # Update right child
    update(node*2+1, (start+end)//2+1, end, val, x, y)
    # Updating parent of affected nodes with min values
    tree[node] = min(tree[node*2], tree[node*2+1])


def query(node, start, end, l, r):
    
    '''Input
        node: Current node of tree
       start: Starting index of input array
         end: Last index of input array 
      [l..r]: In this range you want to find minimum 

      Return: Minimum value between range [l..r]
    '''
    
    # If the query is our of range of Segment Tree
    if start > end or start > r or end < l:
        return INF
    
    # Update current tree node
    if lazy[node] != 0:
        tree[node] += lazy[node]
        
        # Mark childs as lazy
        if start != end:
             lazy[node*2] += lazy[node]
             lazy[node*2+1] += lazy[node]

        # Reset current node
        lazy[node] = 0

    if start >= l and end <= r:
        return tree[node]
    
    # Find minimum element in left child tree
    min1 = query(node*2, start, (start+end)//2, l, r)
    # Find minimum element in right child tree
    min2 = query(node*2+1, (start+end)//2+1, end, l, r)
    # Combine ans
    ans =min(min1, min2)
    return ans

'''Input:
     A : input array
     First update: Update range [0..7] by 2
     Second update: Update range [2..4] by 1
     Query : Find minimum in range [1..5]

   Output:
     Minimum in range [1..5]: 2  

'''

# Input array
A =[1, 2, 3, 4, 5, 6, 7, 8]

# Build Segment Tree
build_tree(A, 1, 0, 7)

# First update
update(1, 0, 7, 2, 0, 7)

# Second updatae
update(1, 0, 7, 1, 2, 4)

# Query
print("Minimum in range [1..5]:", query(1, 0, 7, 1, 5))

'''Output:
   Minimum in range [1..5]: 2 '''
