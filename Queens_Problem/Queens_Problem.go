// Given a chess board having N×N cells place N queens on the board in such a way that no queen attacks any other queen.

package main

import "fmt"

func main() {
	var boardSize int
  	fmt.Scan(&boardSize)

	// make board
	board := make([][]int, boardSize)
	for i := range board {
		board[i] = make([]int, boardSize)
	}

	if placeQueen(&board, boardSize) {
		for i := 0; i < boardSize; i++ {
			for j := 0; j < boardSize; j++ {
				fmt.Printf("%d ", board[i][j])
			}
			fmt.Print("\n")
		}
	} else {
		fmt.Println("Not possible")
	}
}
//checks whether this cell can be attacked by other queens or not
func isAttacked(board *[][]int, x, y, boardSize int) bool {
	for i := 0; i < boardSize; i++ {
		//checking if there is a queen in row
		if (*board)[x][i] == 1 {
			return true
		}
		//checking if there is a queen in column
		if (*board)[i][y] == 1 {
			return true
		}
		//checking for diagonals
		for j := 0; j < boardSize; j++ {
			if (i-j == x-y) || (i+j == x+y) {
				if (*board)[i][j] == 1 {
					return true
				}
			}
		}
	}
	return false
}

// PlaceQueen place queens on the board and will return true if it is possible to place all the queens else false
func placeQueen(board *[][]int, boardSize int) bool {
	if boardSize == 0 {
		return true
	}
	for i := 0; i < len(*board); i++ {
		for j := 0; j < len(*board); j++ {
			if !(isAttacked(board, i, j, len(*board))) {
				(*board)[i][j] = 1
				if placeQueen(board, boardSize-1) {
					return true
				}
				(*board)[i][j] = 0
			}
		}
	}
	return false
}

//OUTPUT
//1 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 1 0 0 0 0
