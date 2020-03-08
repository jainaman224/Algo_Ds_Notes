# Python Program to find Minimum Insertion in a string to make it Palindrome.
""" -----------------------------------
Example:
ab : No. of insertion is required 1 (bab)
abcd : No. of insertion is required 3 (dcbabcd)

Dynamic Programming based Solution.
Time Complexity : O(n^2)
Space Complexity : O(n^2)
--------------------------------------- """
# Function for Findind Min.
def Min(a, b):
    """
        This Function is return minimum value B/w a and b.
    """
    return min(a, b)

# Function for Finding Min Insertion.
def find_min_insertion_DP(s, n):
    """
    This Function return min insertion value for string to make palindrome.
    """

    # Create table of size n * n
    t = [[0 for i in range(n)]for i in range(n)]
    l, h, g = 0, 0, 0
    # Fill the Table
    for g in range(1, n):
        l = 0
        for h in range(g, n):
            if s[l] == s[h]:
                t[l][h] = t[l+1][h-1]
            else:
                t[l][h] = (Min(t[l][h-1], t[l+1][h]) + 1)
            l += 1
    return t[0][n - 1]
 
# Main Function.
def main():
    s = "car"  # Input String
    x = find_min_insertion_DP(s, len(s))  # Minimum value.
    print(x)

# Driver Code.
if __name__ == "__main__":
    main()

"""
    [Simple Input 1]
      s = 'car'
    [Simple Output 1]
      min_insertion = 2
    [Simple Input 2]
      s = 'radar'
    [Simple Output 2]
      min_insertion = 0
"""
