def Sum(ft, index): 

    """
     ft     : Fenwich Tree
     index  : Index upto which you want to find prefix sum

     Initialize the result "s" then increment the value of 
     index "index".
     Returns sum of arr[0..index]. This function assumes 
     that the array is preprocessed and partial sums of 
     array elements are stored in ft[]. 
    """
    s=0
    index = index + 1
    while index > 0:  
        s += ft[index]
        index -= index & (-index) 
    return s 

def update(ft, size, index, val):
    
    """
      ft    : Fenwick Tree
      index : Index of ft to be updated
      size  : Length of the original array
      val   : Add val to the index "index"

      Traverse all ancestors and add 'val'.
      Add 'val' to current node of Fenwick Tree. 
      Update index to that of parent in update View. 

    """ 

    index += 1
    while index <= size: 
        ft[index] += val 
        index += index & (-index) 

def construct(arr, size): 

    """
      arr  : The original array
      size : The length of the given array

      This function will construct the Fenwick Tree 
      from the given array of length "size" and 
      return it.

    """

    ft = [0]*(size+1) 
    for i in range(size): 
        update(ft, size, i, arr[i]) 
    return ft 

"""
  TEST CASE
 -----------
  Input
  freq : [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9]
  Print sum of freq[0...5] 
  Update position 4 by adding 16
  Print sum of freq[2....7] after update
  Update position 5 by adding 10
  Print sum of freq[2....7] after update 

"""

# freq is the given array    
freq = [2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9] 

# construct function will return the Fenwich Tree.
ft = construct(freq,len(freq))

#Printing freq[0....5]
print(Sum(ft,5))

#Updating position 4 by adding 16
update(ft,len(freq),4,16) 

# Printing sum of freq[2...7] after update
print(Sum(ft,7)-Sum(ft,2))

#Updating position 5 by adding 10
update(ft,len(freq),5,10)

# Printing sum of freq[2...7] after update
print(Sum(ft,7)-Sum(ft,2))

"""
  OUTPUT
 --------
 12
 33
 43
"""

