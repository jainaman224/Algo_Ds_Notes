from math import floor

'''check wether number 'num' can be placed at in r'th row and
   c'th column of the given sudoku '''


def is_possible(sudoku, row, col, num):
    for i in range(0, 9):
        # check whether number 'num' is present in the c'th cloumn
        if sudoku[i][col] == num:
            return False

        # check whether number 'num' is present in the r'th row
        if sudoku[row][i] == num:
            return False

    # check whether number 'num' is present in the corresponding 3*3 box
    # row number of first cell of the corresponding 3*3 box
    row_num_of_box = int(floor(row/3))*3
    # column number of first cell of the corresponding 3*3 box
    col_num_of_box = int(floor(col/3))*3

    for i in range(row_num_of_box, row_num_of_box+3):
        for j in range(col_num_of_box, col_num_of_box+3):
            if sudoku[i][j] == num:
                return False
    return True


def solve_sudoku(sudoku, row, col):
    if row == 9:
        return True
    if col == 9:
        return solve_sudoku(sudoku, row+1, 0)
    if sudoku[row][col] == 0:
        for i in range(1, 10):
            if is_possible(sudoku, row, col, i):
                sudoku[row][col] = i
                if solve_sudoku(sudoku, row, col+1):
                    return True
                sudoku[row][col] = 0
        return False
    else:
        return solve_sudoku(sudoku, row, col+1)


def can_solve(sudoku):
    return solve_sudoku(sudoku, 0, 0)


def print_sudoku(sudoku):
    print("solved sudoku is : ")
    for i in range(0, 9):
        temp_row = sudoku[i]
        temp_row = [str(x) for x in temp_row]
        row = " ".join(temp_row)
        print(row)


if __name__ == "__main__":
    sudoku = []
    print("provide the sudoku \n\'0\' represents the blank space")
    for i in range(0, 9):
        elements_of_ith_row = input()
        elements_of_ith_row = elements_of_ith_row.split(" ")
        row = [int(num) for num in elements_of_ith_row]
        sudoku.append(row)
    if can_solve(sudoku):
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
