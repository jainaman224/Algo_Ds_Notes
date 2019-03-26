/* N-Queen's Problem
* Language: JavaScript
*/

/*To check if the queen is under attack, sideways or diagonally*/
const underAttack = (board, row, col) => {

	for(let j = 0; j < col; j++){ //Checks the left side of the board
		if(board[row][j])
			return true;
		}

	for(let i = row, j = col; i >= 0 && j >= 0; i--, j--){ //Checks the diagonals in the upper part of left side
		if(board[i][j])
			return true;
		}

	for(let i = row, j = col; i < board[0].length && j >= 0; i++, j--){ //Checks the diagonals n the lower part of the left side
		if(board[i][j])
			return true;
		}

	return false;
};

//To place the queens in the correct positions
function NQueens(board, col){

	if(col >= board.length) //Checks if all queens are placed
		return true;

	for(let i = 0; i < board.length; i++){
		if(!underAttack(board, i, col)){

		//Placing the queens in the correct position
		board[i][col] = 'Q';

			if(NQueens(board, col + 1)){ //Recursive call to place rest of the queens
				return true;
			}

		board[i][col] = 0; //Backtracking
		}
	}
	return false;
}

//To place queens in the correct positions
const placeQueens = (n) => {

	//To check if the input is less than 4, if so it throws an error
	if(n < 4)
		throw new TypeError(`Invalid input '${n}' received!`);	

	//Initialize matrix with input n
	let board = [...Array(n)].map(x => Array(n).fill(0)),
	print = "";

	//Checks if there is any solution available
	if(NQueens(board, 0) === false)
		console.log('No solution!');

	//Prints one of the possible solutions
	for(let i = 0; i < board.length; i++){
		for(let j = 0; j < board[0].length; j++){
			print += board[i][j] + ' ';
		}
		console.log(print);
		print = '';
	}
};

console.log(placeQueens(4));

/*Input*/
//n = 4

/*Output*/
/*
0 0 Q 0 
Q 0 0 0 
0 0 0 Q 
0 Q 0 0
*/
