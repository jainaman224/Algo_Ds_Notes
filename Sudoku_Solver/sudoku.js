var table;
var gameId = 0;
var puzzle = [];
var solution = [];
var isPuzzleSolved = false;
var canSolved = true;
var timer = 0;
var checkingTimerpause = false;
var intervalId;
var gameOn = false;
var remaining = [9, 9, 9, 9, 9, 9, 9, 9, 9];
function newGame(difficulty) {
   var grid = getGridInit();
    var rows = grid;
    var cols = getColumns(grid);
    var blks = getBlocks(grid);
    var psNum = generatePossibleNumber(rows, cols, blks);
    solution = solveGrid(psNum, rows, true);
    timer = 0;
    for (var i in remaining)
        remaining[i] = 9;

    puzzle = makeItPuzzle(solution, difficulty);

        gameOn = difficulty < 5 && difficulty >= 0;
    ViewPuzzle(puzzle);
    updateRemainingTable();
    if (gameOn)
        startTimer();
}
function getGridInit() {
    var rand = [];
    
    for (var i = 1; i <= 9; i++) {
        var row = Math.floor(Math.random() * 9);
        var col = Math.floor(Math.random() * 9);
        var accept = true;
        for (var j = 0; j < rand.length; j++) {

            
            if (rand[j][0] == i | (rand[j][1] == row & rand[j][2] == col)) {
                accept = false;
                i--;
                break;
            }
        }
        if (accept) {
            rand.push([i, row, col]);
        }
    }    
    var result = [];
    for (var i = 0; i < 9; i++) {
        var row = "000000000";
        result.push(row);
    }
    for (var i = 0; i < rand.length; i++) {
        result[rand[i][1]] = replaceCharAt(result[rand[i][1]], rand[i][2], rand[i][0]);
    }

    return result;
}


function getColumns(grid) {
    var result = ["", "", "", "", "", "", "", "", ""];
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++)
            result[j] += grid[i][j];
        /*try {
            result[j] += grid[i][j];
        } catch (err) {
            alert(grid);
        }*/

    }
    return result;
}


function getBlocks(grid) {
    var result = ["", "", "", "", "", "", "", "", ""];
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++)
            result[Math.floor(i / 3) * 3 + Math.floor(j / 3)] += grid[i][j];
    }
    return result;
}


function replaceCharAt(string, index, char) {
    if (index > string.length - 1) return string;
    return string.substr(0, index) + char + string.substr(index + 1);
}


function generatePossibleNumber(rows, columns, blocks) {
    var psb = [];

    
    
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            psb[i * 9 + j] = "";
            if (rows[i][j] != 0) {
                psb[i * 9 + j] += rows[i][j];
            } else {
                for (var k = '1'; k <= '9'; k++) {
                    if (!rows[i].includes(k))
                        if (!columns[j].includes(k))
                            if (!blocks[Math.floor(i / 3) * 3 + Math.floor(j / 3)].includes(k))
                                psb[i * 9 + j] += k;
                }
            }
        }
    }
    return psb;
}

function solveGrid(possibleNumber, rows, startFromZero) {
    var solution = [];

    var result = nextStep(0, possibleNumber, rows, solution, startFromZero);
    if (result == 1)
        return solution;
}
function nextStep(level, possibleNumber, rows, solution, startFromZero) {
    
    var x = possibleNumber.slice(level * 9, (level + 1) * 9);
    
    var y = generatePossibleRows(x);
    if (y.length == 0)
        return 0;

    
    var start = startFromZero ? 0 : y.length - 1;
    var stop = startFromZero ? y.length - 1 : 0;
    var step = startFromZero ? 1 : -1;
    var condition = startFromZero ? (start <= stop) : (start >= stop);

    
    for (var num = start; condition; num += step) {
        var condition = startFromZero ? (num + step <= stop) : (num + step >= stop);
        for (var i = level + 1; i < 9; i++)
            solution[i] = rows[i];
        solution[level] = y[num];
        if (level < 8) {
            var cols = getColumns(solution);
            var blocks = getBlocks(solution);

            var poss = generatePossibleNumber(solution, cols, blocks);
            if (nextStep(level + 1, poss, rows, solution, startFromZero) == 1)
                return 1;
        }
        if (level == 8)
            return 1;
    }
    return -1;
}


function generatePossibleRows(possibleNumber) {
    var result = [];

    function step(level, PossibleRow) {
        if (level == 9) {
            result.push(PossibleRow);
            return;
        }

        for (var i in possibleNumber[level]) {
            if (PossibleRow.includes(possibleNumber[level][i]))
                continue;
            step(level + 1, PossibleRow + possibleNumber[level][i]);
        }
    }

    step(0, "");

    return result;
}


function makeItPuzzle(grid, difficulty) {
    /*
        difficulty:
        
        
        
        
        
    */

    
    
    
    if (!(difficulty < 5 && difficulty > -1))
        difficulty = 13;
    var remainedValues = 81;
    var puzzle = grid.slice(0);

    
    function clearValue(grid, x, y, remainedValues) {
        function getSymmetry(x, y) {
            var symX = 8 - x;  
            var symY = 8 - y;
            return [symX, symY];
        }
        var sym = getSymmetry(x, y);
        if (grid[y][x] != 0) {
            grid[y] = replaceCharAt(grid[y], x, "0")
            remainedValues--;
            if (x != sym[0] && y != sym[1]) {
                grid[sym[1]] = replaceCharAt(grid[sym[1]], sym[0], "0")
                remainedValues--;
            }
        }
        return remainedValues;
    }

    
    while (remainedValues > (difficulty * 5 + 20)) {
        var x = Math.floor(Math.random() * 9);
        var y = Math.floor(Math.random() * 9);
        remainedValues = clearValue(puzzle, x, y, remainedValues);
    }
    return puzzle;
}


function ViewPuzzle(grid) {
    for (var i = 0; i < grid.length; i++) {
        for (var j = 0; j < grid[i].length; j++) {
            var input = table.rows[i].cells[j].getElementsByTagName('input')[0];
            addClassToCell(table.rows[i].cells[j].getElementsByTagName('input')[0]);
            if (grid[i][j] == "0") {
                input.disabled = false;
                input.value = "";
            }
            else {
                input.disabled = true;
                input.value = grid[i][j];
                remaining[grid[i][j] - 1]--;
            }
        }
    }
}


function readInput() {
    var result = [];
    for (var i = 0; i < 9; i++) {
        result.push("");
        for (var j = 0; j < 9; j++) {
            var input = table.rows[i].cells[j].getElementsByTagName('input')[0];
            if (input.value == "" || input.value.length > 1 || input.value == "0") {
                input.value = ""
                result[i] += "0";
            }
            else
                result[i] += input.value;
        }
    }
    return result;
}








function checkValue(value, row, column, block, defaultValue, currectValue) {
    if (value === "" || value === '0')
        return 0;
    if (!(value > '0' && value < ':'))
        return 4;
    if (value === defaultValue)
        return 0;
    if ((row.indexOf(value) != row.lastIndexOf(value))
        || (column.indexOf(value) != column.lastIndexOf(value))
        || (block.indexOf(value) != block.lastIndexOf(value))) {
        return 3;
    }
    if (value !== currectValue)
        return 2;
    return 1;
}


function addClassToCell(input, className) {
    
    input.classList.remove("right-cell");
    input.classList.remove("worning-cell");
    input.classList.remove("wrong-cell");

    if (className != undefined)
        input.classList.add(className);
}


function updateRemainingTable() {
    for (var i = 1; i < 10; i++) {
        var item = document.getElementById("remain-" + i);
        item.innerText = remaining[i - 1];
        item.classList.remove("red");
        item.classList.remove("gray");
        if (remaining[i - 1] === 0)
            item.classList.add("gray");
        else if (remaining[i - 1] < 0 || remaining[i - 1] > 9)
            item.classList.add("red");
    }
}


function startTimer() {
    var timerDiv = document.getElementById("timer");
    clearInterval(intervalId);

    
    checkingTimerpause = false;
    intervalId = setInterval(function () {
        if (!checkingTimerpause) {
            timer++;
            var min = Math.floor(timer / 60);
            var sec = timer % 60;
            timerDiv.innerText = (("" + min).length < 2 ? ("0" + min) : min) + ":" + (("" + sec).length < 2 ? ("0" + sec) : sec);
        }
    }, 1000);
}








function solveSudoku(changeUI) {

    
    puzzle = readInput();

    var columns = getColumns(puzzle);
    var blocks = getBlocks(puzzle);

    
    var errors = 0;
    var correct = 0;

    for (var i = 0; i < puzzle.length; i++) {
        for (var j = 0; j < puzzle[i].length; j++) {
            var result = checkValue(puzzle[i][j], puzzle[i], columns[j], blocks[Math.floor(i / 3) * 3 + Math.floor(j / 3)], -1, -1);
            correct = correct + ((result === 2) ? 1 : 0);
            errors = errors + ((result > 2) ? 1 : 0);
            addClassToCell(table.rows[i].cells[j].getElementsByTagName('input')[0], result > 2 ? "wrong-cell" : undefined)
        }
    }

    
    if (errors > 0) {
        canSolved = false;
        return 2;
    }

    canSolved = true;
    isPuzzleSolved = true;

    
    if (correct === 81) {
        return 1;
    }


    
    var time = Date.now();

    
    solution = solveGrid(generatePossibleNumber(puzzle, columns, blocks), puzzle, true);

    
    
    time = Date.now() - time;

    if (changeUI)
        document.getElementById("timer").innerText = Math.floor(time / 1000) + "." + ("000" + (time % 1000)).slice(-3);


    if (solution === undefined) {
        isPuzzleSolved = false;
        canSolved = false;
        return 3;
    }

    if (changeUI) {
        remaining = [0, 0, 0, 0, 0, 0, 0, 0, 0];
        updateRemainingTable();
        ViewPuzzle(solution);
    }
    return 0;
}


function hideMoreOptionMenu() {
    var moreOptionList = document.getElementById("more-option-list");
    if (moreOptionList.style.visibility == "visible") {
        moreOptionList.style.maxWidth = "40px";
        moreOptionList.style.minWidth = "40px";
        moreOptionList.style.maxHeight = "10px";
        moreOptionList.style.opacity = "0";
        setTimeout(function () {
            moreOptionList.style.visibility = "hidden";
        }, 175);
    }
}





window.onload = function () {

    
    table = document.getElementById("puzzle-grid");
    
    var rippleButtons = document.getElementsByClassName("button");
    for (var i = 0; i < rippleButtons.length; i++) {
        rippleButtons[i].onmousedown = function (e) {
            
            var x = e.pageX - this.offsetLeft;
            var y = e.pageY - this.offsetTop;

            
            var rippleItem = document.createElement("div");
            rippleItem.classList.add('ripple');
            rippleItem.setAttribute("style", "left: " + x + "px; top: " + y + "px");

            
            var rippleColor = this.getAttribute('ripple-color');
            if (rippleColor)
                rippleItem.style.background = rippleColor;
            this.appendChild(rippleItem);

            
            setTimeout(function () {
                rippleItem.parentElement.removeChild(rippleItem);
            }, 1500);
        };
    }
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            var input = table.rows[i].cells[j].getElementsByTagName('input')[0];

            
            input.onchange = function () {

                
                addClassToCell(this);

                
                function checkInput(input) {
                    if (input.value[0] < '1' || input.value[0] > '9') {
                        if (input.value != "?" && input.value != "؟") {
                            input.value = "";
                            alert("only numbers [1-9] and question mark '?' are allowed!!");
                            input.focus()
                        }
                    }
                }
                checkInput(this);

                
                if (this.value > 0 && this.value < 10)
                    remaining[this.value - 1]--;
                if (this.oldvalue !== "") {
                    if (this.oldvalue > 0 && this.oldvalue < 10)
                        remaining[this.oldvalue - 1]++;
                }

                
                canSolved = true;

                updateRemainingTable();
            };

            
            input.onfocus = function () {
                this.oldvalue = this.value;
            };
        }
    }
}


window.onclick = function (event) {
    var d1 = document.getElementById("dialog");
    var d2 = document.getElementById("about-dialog");
    var m1 = document.getElementById("more-option-list");

    if (event.target == d1) {
        hideDialogButtonClick("dialog");
    } else if (event.target == d2) {
        hideDialogButtonClick("about-dialog");
    } else if (m1.style.visibility == "visible") {
        hideMoreOptionMenu();
    }
}


function HamburgerButtonClick() {
    var div = document.getElementById("hamburger-menu");
    var menu = document.getElementById("nav-menu");
    div.style.display = "block";
    div.style.visibility = "visible";
    setTimeout(function () {
        div.style.opacity = 1;
        menu.style.left = 0;
    }, 50);
}


function startGameButtonClick() {
    var difficulties = document.getElementsByName('difficulty');
    
    
    
    
    
    
    

    
    var difficulty = 5;

    
    for (var i = 0; i < difficulties.length; i++) {
        if (difficulties[i].checked) {
            newGame(4 - i);
            difficulty = i;
            break;
        }
    }
    if (difficulty > 4)
        newGame(5);

    hideDialogButtonClick('dialog');
    gameId++;
    document.getElementById("game-number").innerText = "game #" + gameId;


    
    
    document.getElementById("moreoption-sec").style.display = "block";
    document.getElementById("pause-btn").style.display = "block";
    document.getElementById("check-btn").style.display = "block";
    document.getElementById("isunique-btn").style.display = "none";
    document.getElementById("solve-btn").style.display = "none";

    
    document.getElementById("timer-label").innerText = "Time";
    document.getElementById("timer").innerText = "00:00";
    document.getElementById("game-difficulty-label").innerText = "Game difficulty";


    document.getElementById("game-difficulty").innerText = difficulty < difficulties.length ? difficulties[difficulty].value : "solved";
}


function pauseGameButtonClick() {
    var icon = document.getElementById("pause-icon");
    var label = document.getElementById("pause-text");

    
    if (checkingTimerpause) {
        icon.innerText = "pause";
        label.innerText = "Pause";
        table.style.opacity = 1;
    }
    else {
        icon.innerText = "play_arrow";
        label.innerText = "Continue";
        table.style.opacity = 0;
    }

    checkingTimerpause = !checkingTimerpause;
}


function checkButtonClick() {

    
    if (gameOn) {

        
        timer += 60;
        var currentGrid = [];

        
        currentGrid = readInput();

        var columns = getColumns(currentGrid);
        var blocks = getBlocks(currentGrid);

        var errors = 0;
        var currects = 0;

        for (var i = 0; i < currentGrid.length; i++) {
            for (var j = 0; j < currentGrid[i].length; j++) {
                if (currentGrid[i][j] == "0")
                    continue;

                
                var result = checkValue(currentGrid[i][j], currentGrid[i], columns[j], blocks[Math.floor(i / 3) * 3 + Math.floor(j / 3)], puzzle[i][j], solution[i][j]);

                
                addClassToCell(table.rows[i].cells[j].getElementsByTagName('input')[0], result === 1 ? "right-cell" : (result === 2 ? "worning-cell" : (result === 3 ? "wrong-cell" : undefined)));

                if (result === 1 || result === 0) {
                    currects++;
                } else if (result === 3) {
                    errors++;
                }
            }
        }

        
        
        if (currects === 81) {
            gameOn = false;
            checkingTimerpause = true;
            document.getElementById("game-difficulty").innerText = "Solved";
            clearInterval(intervalId);
            alert("Congrats, You solved it.");
        } else if (errors === 0 && currects === 0) {
            alert("Congrats, You solved it, but this is not the solution that I want.");
        }
    }
}


function restartButtonClick() {

    if (gameOn) {
        
        for (var i in remaining)
            remaining[i] = 9;

        
        ViewPuzzle(puzzle);

        
        updateRemainingTable();

        
        
        timer = -1;
    }
}


function SurrenderButtonClick() {

    if (gameOn) {
        
        for (var i in remaining)
            remaining[i] = 9;

        
        ViewPuzzle(solution);

        
        updateRemainingTable();

        
        gameOn = false;
        checkingTimerpause = true;
        clearInterval(intervalId);

        
        document.getElementById("game-difficulty").innerText = "Solved";
    }
}


function hintButtonClick() {
    if (gameOn) {

        
        var empty_cells_list = [];
        var wrong_cells_list = [];
        for (var i = 0; i < 9; i++) {
            for (var j = 0; j < 9; j++) {
                var input = table.rows[i].cells[j].getElementsByTagName('input')[0];
                if (input.value == "" || input.value.length > 1 || input.value == "0") {
                    empty_cells_list.push([i, j])
                }
                else {
                    if (input.value !== solution[i][j])
                        wrong_cells_list.push([i, j])
                }
            }
        }

        
        if (empty_cells_list.length === 0 && wrong_cells_list.length === 0) {
            gameOn = false;
            checkingTimerpause = true;
            document.getElementById("game-difficulty").innerText = "Solved";
            clearInterval(intervalId);
            alert("Congrats, You solved it.");
        } else {

            
            timer += 60;

            
            var input
            if ((Math.random() < 0.5 && empty_cells_list.length > 0) || wrong_cells_list.length === 0) {
                var index = Math.floor(Math.random() * empty_cells_list.length)
                input = table.rows[empty_cells_list[index][0]].cells[empty_cells_list[index][1]].getElementsByTagName('input')[0];
                input.oldvalue = input.value;
                input.value = solution[empty_cells_list[index][0]][empty_cells_list[index][1]];
                remaining[input.value - 1]--;
            } else {
                var index = Math.floor(Math.random() * wrong_cells_list.length)
                input = table.rows[wrong_cells_list[index][0]].cells[wrong_cells_list[index][1]].getElementsByTagName('input')[0];
                input.oldvalue = input.value;
                remaining[input.value - 1]++;
                input.value = solution[wrong_cells_list[index][0]][wrong_cells_list[index][1]];
                remaining[input.value - 1]--;
            }

            
            updateRemainingTable();
        }

        
        var count = 0
        for (var i = 0; i < 6; i++) {
            setTimeout(function () {
                if (count % 2 == 0)
                    input.classList.add("right-cell");
                else
                    input.classList.remove("right-cell");
                count++;
            }, i * 750)
        }
    }
}

function showDialogClick(dialogId) {
    
    hideHamburgerClick();

    var dialog = document.getElementById(dialogId);
    var dialogBox = document.getElementById(dialogId + "-box");
    dialogBox.focus();
    dialog.style.opacity = 0;
    dialogBox.style.marginTop = "-500px";
    dialog.style.display = "block";
    dialog.style.visibility = "visible";

    
    setTimeout(function () {
        dialog.style.opacity = 1;
        dialogBox.style.marginTop = "64px";
    }, 200);
}


function moreOptionButtonClick() {
    var moreOptionList = document.getElementById("more-option-list");

    
    setTimeout(function () {
        if (moreOptionList.style.visibility == "hidden") {
            moreOptionList.style.visibility = "visible";
            setTimeout(function () {
                moreOptionList.style.maxWidth = "160px";
                moreOptionList.style.minWidth = "160px";
                moreOptionList.style.maxHeight = "160px";
                moreOptionList.style.opacity = "1";
            }, 50);
        }
    }, 50);
}

function hideDialogButtonClick(dialogId) {
    var dialog = document.getElementById(dialogId);
    var dialogBox = document.getElementById(dialogId + "-box");
    dialog.style.opacity = 0;
    dialogBox.style.marginTop = "-500px";

    setTimeout(function () {
        dialog.style.visibility = "collapse";
        
    }, 500);
}


function hideHamburgerClick() {
    var div = document.getElementById("hamburger-menu");
    var menu = document.getElementById("nav-menu");
    menu.style.left = "-256px";

    setTimeout(function () {
        div.style.opacity = 0;
        
        div.style.visibility = "collapse";
    }, 200);
}




function sudokuSolverMenuClick() {

    
    hideHamburgerClick();

    
    if (gameOn) {
        gameOn = false;
        clearInterval(intervalId);
    }


    solution = [];
    canSolved = true;
    isPuzzleSolved = false;

    
    var grid = [];
    for (var i = 0; i < 9; i++) {
        grid.push("");
        for (var j = 0; j < 9; j++) {
            grid[i] += "0";
        }
    }

    
    ViewPuzzle(grid);

    
    remaining = [9, 9, 9, 9, 9, 9, 9, 9, 9];
    updateRemainingTable();

    
    
    document.getElementById("moreoption-sec").style.display = "none";
    document.getElementById("pause-btn").style.display = "none";
    document.getElementById("check-btn").style.display = "none";
    document.getElementById("isunique-btn").style.display = "block";
    document.getElementById("solve-btn").style.display = "block";

    
    
    
    
    document.getElementById("timer-label").innerText = "Solve time";
    document.getElementById("timer").innerText = "00:00";
    document.getElementById("game-difficulty-label").innerText = "Is unique";
    document.getElementById("game-difficulty").innerText = "Unknown";
    document.getElementById("game-number").innerText = "#Soduko_Solver"

    
    document.getElementById("puzzle-grid").rows[0].cells[0].getElementsByTagName('input')[0].focus();
}

function solveButtonClick() {

    if (gameOn) {
        gameOn = false;
        clearInterval(intervalId);
    }
    
    var result = solveSudoku(true);
    switch (result) {
        case 0:
            alert("SOLVED");
            break;
        case 1:
            alert("This grid is already solved")
            break;
        case 2:
            alert("This grid can't be solved because of an invalid input")
            break;
        case 3:
            alert("this grid has no solution");
            break;
    }
}

function isUniqueButtonClick() {
    
    

    if (!isPuzzleSolved) {
        if (canSolved)
            solveSudoku(false);
    }
    if (!isPuzzleSolved) {
        alert("Can't check this grid because it is unsolvable!");
        return;
    }

    
    var columns = getColumns(puzzle);
    var blocks = getBlocks(puzzle);
    var solution2 = solveGrid(generatePossibleNumber(puzzle, columns, blocks), puzzle, false);

    
    var unique = true;
    for (var i = 0; i < solution.length; i++) {
        for (var j = 0; j < solution[i].length; j++) {
            if (solution[i][j] !== solution2[i][j]) {
                unique = false;
                break;
            }
            if (!unique)
                break;
        }
    }

 
    document.getElementById("game-difficulty").innerText = unique ? "Yes" : "No";
}