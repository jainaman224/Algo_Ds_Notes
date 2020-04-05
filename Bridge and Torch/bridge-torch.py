"""
Bridge and Torch Problem
Bridge and torch problem is a popular puzzle where four people need to cross a 
faulty bridge in minimum time with only two people able to cross at a time. They 
have one torch and every time a pair crosses the bridge, one needs to come back.
Given the time taken by the four people to cross the bridge, we have to compute 
the minimum time taken to cross the bridge.
"""

def bridgeTorch(arr):
    arr.sort()                                  
    if len(arr)>3:                               
        a = arr[0]+arr[-1]+min(2*arr[1],arr[0]+arr[-2])  
        return  a + bridgeTorch(arr[:-2])                  
    else:
        return sum(arr[len(arr)==2:])   

# Driver Function
if __name__ == "__main__":
  print("Enter the time taken by each traveller to cross the Bridge:")
  list_of_travellers = [int(x) for x in input().split()]
  print("The minimum time taken to cross the Bridge is %s" %(bridgeTorch(list_of_travellers)))

"""
Sample Input: 
 
Enter the time taken by each traveller to cross the Bridge:
1 3 4 5
Sample Output: 
The minimum time taken to cross the Bridge is 14
"""
