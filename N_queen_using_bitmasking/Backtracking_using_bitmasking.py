# Here we use bit patterns to keep track of queen placements for the columns, left diagonals and right diagonals.
# 1 in the bit pattern denotes that there is a queen attacking that column or diagonal line and 0 means that no queens are attacking that position
            
def totalNQueens(n):
    all_ones = 2 ** n - 1
    count = 0

    def helper(ld, column, rd):
        nonlocal count
        if column == all_ones:
            count += 1
            return
        possible_slots = ~(ld | column | rd) & all_ones
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
