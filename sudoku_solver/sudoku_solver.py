from math import floor

def is_possible(sudoku,r,c,num):
    for i in range(0,9):
        if sudoku[i][c] == num:
            return False
        if sudoku[r][i] == num:
            return False
    sr = int(floor(r/3))*3
    sc = int(floor(c/3))*3
    for i in range(sr,sr+3):
        for j in range(sc,sc+3):
            if sudoku[i][j] == num:
                return False
    return True


def solve(sudoku,r,c):
    if r==9:
        return True
    if c==9:
        return solve(sudoku,r+1,0)
    if sudoku[r][c]==0:
        for i in range(1,10):
            if is_possible(sudoku,r,c,i):
                sudoku[r][c] = i
                if solve(sudoku,r,c+1):
                    return True
                sudoku[r][c] = 0
        return False
    else:
        return solve(sudoku,r,c+1)
    

def sudoku_solver(sudoku):
    return solve(sudoku,0,0)

def print_sudoku(sudoku):
    for i in range(0,9):
        print("solved sudoku is : ")
        temp_row = sudoku[i]
        temp_row = [str(x) for x in temp_row]
        temp_row = " ".join(temp_row)
        print(temp_row)

if __name__ == "__main__":
    sudoku = []
    print("provide the sudoku \n\'0\' represents the blank space")
    for i in range(0,9):
        num = input()
        num = num.split(" ")
        arr = [int(x) for x in num]
        sudoku.append(arr)
    ans = sudoku_solver(sudoku)
    if ans:
        print_sudoku(sudoku)
    else:
        print("Can't solve this sudoku ")

'''
sample input :
(cpoied from https://dingo.sbs.arizona.edu/~sandiway/sudoku/examples.html)
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
'''

'''
this code is written by raghav dalmia
wwww.github.com/raghav-dalmia
'''