#include <bits/stdc++.h>
using namespace std;

#define max_mine 99
#define max_side 25
#define max_move 526 // 25*25-99
int SIDE;
int MINES;

void clrscr()
{
    std::cout << "\33[2J\33[1;1H" << std::flush;
}

bool isvalid(int row, int col)
{
    return (row >= 0) && (row < SIDE) && (col >= 0) && (col < SIDE);
}

bool ismine(int row, int col, char board[][max_side])
{
    if(board[row][col] == 'B')
        return (true);
    else
        return (false);
}

void move(int *x, int *y)
{
    printf("\nEnter your move as (row col) -> ");
    scanf("%d %d", x, y);
    return;
}

void board(char myboard[][max_side])
{
    clrscr();
    printf("\n\n\t\t\t    ");
    for(int i = 0; i < SIDE; i++)
    {
        if (i > 9)
            printf(" %d ", i / 10);
        else
            printf("  ");
    }
    printf("\n\t\t\t    ");
    for(int i = 0; i < SIDE; i++)
        printf(" %d ", i % 10);
    printf("\n\n");
    for(int i = 0; i < SIDE; i++)
    {
        printf("\t\t\t    ");
        for(int j = 0; j < SIDE; j++)
        {
            printf("%c ", myboard[i][j]);
        }
        printf(" %2d", i);
        printf("\n");
    }
    return;
}

int countadjacent(int row, int col, int mines[][2], char realboard[][max_side])
{
    int count = 0;
    if(isvalid(row - 1, col) == true)
    {
        if(ismine(row - 1, col, realboard) == true)
            count++;
    }
    if(isvalid(row + 1, col) == true)
    {
        if(ismine(row + 1, col, realboard) == true)
            count++;
    }
    if(isvalid(row, col + 1) == true)
    {
        if(ismine(row, col + 1, realboard) == true)
            count++;
    }
    if(isvalid(row, col - 1) == true)
    {
        if(ismine(row, col - 1, realboard) == true)
            count++;
    }
    if(isvalid(row - 1, col - 1) == true)
    {
        if(ismine(row - 1, col - 1, realboard) == true)
            count++;
    }
    if(isvalid(row - 1, col + 1) == true)
    {
        if(ismine(row - 1, col + 1, realboard) == true)
            count++;
    }
    if(isvalid(row + 1, col - 1) == true)
    {
        if(ismine(row + 1, col - 1, realboard) == true)
            count++;
    }
    if(isvalid(row + 1, col + 1) == true)
    {
        if(ismine(row + 1, col + 1, realboard) == true)
            count++;
    }
    return (count);
}

bool playuntil(char myboard[][max_side], char realboard[][max_side], int mines[][2], int row, int col, int *moves_left)
{
    if(myboard[row][col] != '-')
        return false;
    int i, j;
    if(realboard[row][col] == 'B')
    {
        myboard[row][col] = 'B';
        for(i = 0; i < MINES; i++)
            myboard[mines[i][0]][mines[i][1]] = 'B';
        board(myboard);
        printf ("\nYou lost!\n");
        return (true);
    }
    else
    {
        int count = countadjacent(row, col, mines, realboard);
        (*moves_left)--;
        myboard[row][col] = count + '0';
        if(!count)
        {
            if(isvalid(row - 1, col) == true)
            {
                if(ismine(row - 1, col, realboard) == false)
                    playuntil(myboard, realboard, mines, row - 1, col, moves_left);
            }
            if (isvalid (row + 1, col) == true)
            {
                if (ismine (row + 1, col, realboard) == false)
                    playuntil(myboard, realboard, mines, row + 1, col, moves_left);
            }
            if (isvalid (row, col + 1) == true)
            {
                if (ismine (row, col + 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row, col + 1, moves_left);
            }
            if (isvalid (row, col - 1) == true)
            {
                if (ismine (row, col - 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row, col - 1, moves_left);
            }
            if (isvalid (row - 1, col + 1) == true)
            {
                if (ismine (row - 1, col + 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row - 1, col + 1, moves_left);
            }
            if (isvalid (row - 1, col - 1) == true)
            {
                if (ismine (row - 1, col - 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row - 1, col - 1, moves_left);
            }
            if (isvalid (row + 1, col + 1) == true)
            {
                if (ismine (row + 1, col + 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row + 1, col + 1, moves_left);
            }
            if (isvalid (row + 1, col - 1) == true)
            {
                if (ismine (row + 1, col - 1, realboard) == false)
                    playuntil(myboard, realboard, mines, row + 1, col - 1, moves_left);
            }
        }
        return (false);
    }
}

void placemines(int mines[][2],char realboard[][max_side])
{
    bool mark[max_side*max_side];
    memset(mark, false, sizeof(mark));
    for(int i = 0; i < MINES;)
    {
        int random = rand() % (SIDE * SIDE);
        int x = random / SIDE;
        int y = random % SIDE;
        if(mark[random] == false) //add mine if not present at position random
        {
            mines[i][0] = x;
            mines[i][1] = y;
            realboard[mines[i][0]][mines[i][1]] = 'B';
            mark[random] = true;
            i++;
        }
    }
}

void initialise(char realboard[][max_side], char myboard[][max_side])
{
    srand(time(NULL)); //initalising random so that same config doesn't arise
    int i, j;
    for(i = 0; i < SIDE; i++)
        for(j = 0; j < SIDE; j++)
        {
            myboard[i][j] = realboard[i][j] = '-';
        }
    return;
}

void cheatmines (char realboard[][max_side])
{
    printf ("The mines locations are-\n");
    board (realboard);
    return;
}

void replacemine(int row, int col, char board[][max_side])
{
    for(int i = 0; i < SIDE; i++)
    {
        for(int j = 0; j < SIDE; j++)
        {
            if(board[i][j] != 'B')
            {
                board[i][j] = 'B';
                board[row][col] = '-';
                return;
            }
        }
    }
}

void play()
{
    bool gameover = false;
    char realboard[max_side][max_side],myboard[max_side][max_side];
    int moves_left = SIDE*SIDE-MINES;
    int x,y;
    int mines[max_mine][2]; //stores (x,y) of all mines
    initialise(realboard, myboard);
    placemines(mines, realboard);
    //if you want cheat and win 
    //cheatmines(realboard);
    int currentmoveindex = 0;
    while(gameover == false)
    {
        printf ("Current Status of Board : \n");
        board(myboard);
        move(&x, &y);
        //if first move is mine
        if(currentmoveindex == 0)
        {
            if(ismine(x, y, realboard) == true) //first attempt is a mine
                replacemine(x, y, realboard); //replace the mine at that location
        }
        currentmoveindex++;
        gameover = playuntil(myboard, realboard, mines, x, y, &moves_left);
        if((gameover == false) && (moves_left == 0))
        {
            printf ("\nYou won !\n");
            gameover = true;
        }
    }
}

void chdiff()
{
    clrscr();
    cout << "\nMINESWEEPER GAME";
    cout << "\n\nCHOOSE YOUR DIFFICULTY LEVEL : ";
    cout << "\n\n0.BEGINNER\n1.MEDIUM\n2.HARD";
    cout << "\n\nENTER YOUR LEVEL (0-2) : ";
    int ch;
    cin >> ch;
    if(ch == 0)
    {
        SIDE = 9; 
        MINES = 10;
    }
    else if(ch == 1)
    {
        SIDE = 16;
        MINES = 40;
    }
    else if(ch == 2)
    {
        SIDE = 24;
        MINES = 99;
    }
    else
        exit(0);
}

int main()
{
    chdiff();
    play();
    return 0;
}

/*
   Input:
   MINESWEEPER GAME
CHOOSE YOUR DIFFICULTY LEVEL : 
0.BEGINNER
1.MEDIUM
2.HARD
ENTER YOUR LEVEL (0-2) :0
Output: 
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - - - - - -   0                                                                                      
                            - - - - - - - - -   1                                                                                      
                            - - - - - - - - -   2  
                            - - - - - - - - -   3                                                                                      
                            - - - - - - - - -   4                                                                                      
                            - - - - - - - - -   5                                                                                      
                            - - - - - - - - -   6                                                                                      
                            - - - - - - - - -   7                                                                                      
                            - - - - - - - - -   8                                                                                      
                                                                                                                                       
EnteEnter your move as (row col) -> 4 6
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            - - 1 0 1 - 1 0 0   2                                                                                      
                            - - 1 0 1 1 1 0 0   3                                                                                      
                            - - 2 1 0 0 0 1 1   4                                                                                      
                            - - - 2 1 1 0 1 -   5                                                                                      
                            - - - - - 1 0 1 -   6                                                                                      
                            - - - - - 1 1 2 -   7                                                                                      
                            - - - - - - - - -   8                                                                                      
                                                                                                                                       
Enter your move as (row col) ->  7 3
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            - - 1 0 1 - 1 0 0   2                                                                                      
                            - - 1 0 1 1 1 0 0   3                                                                                      
                            - - 2 1 0 0 0 1 1   4                                                                                      
                            - - - 2 1 1 0 1 -   5                                                                                      
                            - - - - - 1 0 1 -   6                                                                                      
                            - - - 1 - 1 1 2 -   7                                                                                      
                            - - - - - - - - -   8   
Enter your move as (row col) -> 8 6
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            - - 1 0 1 - 1 0 0   2                                                                                      
                            - - 1 0 1 1 1 0 0   3                                                                                      
                            - - 2 1 0 0 0 1 1   4                                                                                      
                            - - - 2 1 1 0 1 -   5                                                                                      
                            - - - - - 1 0 1 -   6                                                                                      
                            - - - 1 - 1 1 2 -   7                                                                                      
                            - - - - - - 1 - -   8    
                            
Enter your move as (row col) -> 6 1
                            
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            - - 1 0 1 - 1 0 0   2                                                                                      
                            - - 1 0 1 1 1 0 0   3                                                                                      
                            - - 2 1 0 0 0 1 1   4                                                                                      
                            - - - 2 1 1 0 1 -   5                                                                                      
                            - 1 - - - 1 0 1 -   6                                                                                      
                            - - - 1 - 1 1 2 -   7                                                                                      
                            - - - - - - 1 - -   8   
 Enter your move as (row col) -> 8 3
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - - 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            - - 1 0 1 - 1 0 0   2                                                                                      
                            - - 1 0 1 1 1 0 0   3                                                                                      
                            2 3 2 1 0 0 0 1 1   4                                                                                      
                            0 1 - 2 1 1 0 1 -   5                                                                                      
                            0 1 1 2 - 1 0 1 -   6                                                                                      
                            0 0 0 1 1 1 1 2 -   7                                                                                      
                            0 0 0 0 0 0 1 - -   8  
                            
                            
 Enter your move as (row col) -> 8 8
 
                            0 1 2 3 4 5 6 7 8                                                                                          
                                                                                                                                       
                            - - - B 1 0 0 0 0   0                                                                                      
                            - - 1 1 2 1 1 0 0   1                                                                                      
                            B - 1 0 1 B 1 0 0   2                                                                                      
                            B B 1 0 1 1 1 0 0   3                                                                                      
                            2 3 2 1 0 0 0 1 1   4                                                                                      
                            0 1 B 2 1 1 0 1 B   5                                                                                      
                            0 1 1 2 B 1 0 1 -   6                                                                                      
                            0 0 0 1 1 1 1 2 -   7                                                                                      
                            0 0 0 0 0 0 1 B B   8                                                                                      
                                                                                                                                       
You lost!  
*/
