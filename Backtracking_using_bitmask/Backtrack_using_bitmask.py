<<<<<<< HEAD
<<<<<<< HEAD
#Here we use bit patterns to keep track of queen placements 
#for the columns, left diagonals and right diagonals.

def totalNQueens(n):
    #Helps identify valid solutions
    all_ones = 2 ** n - 1  
    #Keeps track of the # of valid solutions
    count = 0 
=======
# Here we use bit patterns to keep track of queen placements for the columns, left diagonals and right diagonals.

def totalNQueens(n):
    all_ones = 2 ** n - 1  #Helps identify valid solutions
    count = 0 #Keeps track of the # of valid solutions
>>>>>>> 42bb684... Backtracking using Bitmasking
=======
#Here we use bit patterns to keep track of queen placements 
#for the columns, left diagonals and right diagonals.

def totalNQueens(n):
    #Helps identify valid solutions
    all_ones = 2 ** n - 1  
    #Keeps track of the # of valid solutions
    count = 0 
>>>>>>> d83e063... Update Backtrack_using_bitmask.py

    #Checks all possible board configurations
    def helper(ld, column, rd):
        nonlocal count

        #All columns are occupied,so the solution must be complete
        if column == all_ones:
            count += 1
            return

        #Gets a bit sequence with "1"s whereever there is an open "slot"
        possible_slots = ~(ld | column | rd) & all_ones

        #Loops as long as there is a valid place to put another queen.
        while possible_slots:
            current_bit = possible_slots & -possible_slots
            possible_slots -= current_bit
            helper((ld | current_bit) >> 1,
                   column | current_bit,
                   (rd | current_bit) << 1)

    helper(0, 0, 0)
    return count

if __name__ == '__main__': 
    n = int(input())
<<<<<<< HEAD
<<<<<<< HEAD
    d = (1 << n) - 1
    cnt = totalNQueens(n)
    print(cnt);

'''
Sample Input:
4
Sample Output:
2
Sample Input:
5
Sample Output:
10
'''
=======
    d = (1<<n)-1
    cnt = totalNQueens(n)
    print(cnt);


# Sample Input: 
# 4
# Sample Output: 
# 2

# Sample Input: 
# 5
# Sample Output: 
# 10
>>>>>>> 42bb684... Backtracking using Bitmasking
=======
    d = (1 << n) - 1
    cnt = totalNQueens(n)
    print(cnt);

'''
Sample Input:
4
Sample Output:
2
Sample Input:
5
Sample Output:
10
'''
>>>>>>> d83e063... Update Backtrack_using_bitmask.py
