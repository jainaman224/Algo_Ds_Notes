""" -----------> Question <----------------
The Problem is to count all the possible
paths from top left to botton right of a m*n
matrix with Constraints that 
NOTE:
From each cell you can either move only
to right or down.
*-*-*-*-*-*-*-*-*- Example *-*-*-*-*-*-*-
Input: m = 2, n = 3     Output: 3

Explanation: There are 3 Paths
(0 ,0)-->(0, 1)-->(0, 2)-->(1, 2)
(0 ,0)-->(0, 1)-->(1, 1)-->(1, 2)
(0 ,0)-->(1, 0)-->(1, 1)-->(1, 2)
----------------> END <-------------------"""
"""
    Recursive Method
    Time Complexity : exponential 
"""
def number_of_path(m, n):
    """
        If either m = 1 or n = 1
    """
    if m == 1 or n == 1:
        return 1
    return number_of_path(m-1,n) + number_of_path(m,n-1)

# Main Function.
def main():
    m = 2
    n = 3
    print(number_of_path(m, n))

# Driver Code.
if __name__ == "__main__":
    main()
"""
    simple Input: m = 2, n = 3
    simple Output: 3
"""
