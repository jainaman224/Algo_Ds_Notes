const matrix = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 0, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
];

const solve = matrix => {
    const check = nextIndex(matrix);
    if (check) {
        const row = check[0];
        const col = check[1];
        for (let i = 1; i <= 9; ++i) {
            if (isValid(matrix, row, col, i)) {
                matrix[row][col] = i;
                if (solve(matrix)) {
                    return true;
                }
                matrix[row][col] = 0;
            }
        }
        return false;
    } else {
        return true;
    }
};

const isValid = (matrix, row, col, num) => {
    //check the entire row
    for (let i = 0; i < matrix[0].length; ++i) {
        if (matrix[row][i] == num && i !== col) {
            return false;
        }
    }
    //check the entire coloumn
    for (let i = 0; i < matrix[col].length; ++i) {
        if (matrix[i][col] == num && i !== row) {
            return false;
        }
    }

    //checking the box
    let brow = parseInt(row / 3) * 3;
    let bcol = parseInt(col / 3) * 3;
    for (let i = brow; i < brow + 3; ++i) {
        for (let j = bcol; j < bcol + 3; ++j) {
            if (matrix[i][j] == num && i != row && j != col) {
                return false;
            }
        }
    }
    return true;
};

const nextIndex = matrix => {
    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < matrix[i].length; ++j) {
            if (matrix[i][j] == 0) {
                return [i, j];
            }
        }
    }
    return false;
};

if (solve(matrix)) {
    console.log(matrix);
} else {
    console.log(`sorry i can't solve`);
}
//output
/*
[ [ 5, 3, 4, 6, 7, 8, 9, 1, 2 ],
  [ 6, 7, 2, 1, 9, 5, 3, 4, 8 ],
  [ 1, 9, 8, 3, 4, 2, 5, 6, 7 ],
  [ 8, 5, 9, 7, 6, 1, 4, 2, 3 ],
  [ 4, 2, 6, 8, 5, 3, 7, 9, 1 ],
  [ 7, 1, 3, 9, 2, 4, 8, 5, 6 ],
  [ 9, 6, 1, 5, 3, 7, 2, 8, 4 ],
  [ 2, 8, 7, 4, 1, 9, 6, 3, 5 ],
  [ 3, 4, 5, 2, 8, 6, 1, 7, 9 ] ]
 */
