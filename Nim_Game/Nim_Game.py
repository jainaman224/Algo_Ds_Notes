'''
    NIM GAME

    Problem Statement :
    Given two players and n no. of piles of stones. Each pile contains some variable
    no. of stones. Each player takes turn one by one, and in each turn, they are required
    to select one pile and remove 1 or more stones from that pile.

    Suppose you know the initial configuration of piles and also,
    the player starting the game. If both players play optimally and the player, who 
    is unable to make a move in the last is declared a loser,
    We need to find out the winner of the game.

'''
import math 
'''
    Nim sum : XOR sum of no. of stones in all piles.

    Nim game rule :
    1. The nim rule says that if the nim sum of the configuration of stone piles is 0,
    then the player with the move will lose the game. 
    2. If the nim sum is 0 at any point of time, there is no way that it will be 0 in 
    the following turn as removal of any no. of stones would make it non-zero.
    3. If the nim sum is non-zero at any point of time, there is one possible way to 
    make it 0 in the following turn by removal of a specific amount of stones from the
    configuration.

    Thus, using these rules, the winner can easily be predicted :
    If the nim sum of initial configuration is non-zero, the starting player can always 
    make it 0 for the next turn, which will be a losing position for the second player.
    And, thus he will win.
    In other case, if he removes some stones from a zero-nim sum piles, the nim sum wouldn't 
    remain 0 and hence, it would be a winning position for the second player.
'''

def calculateWinner(starting_player, piles, no_of_piles):
    nim_sum = 0
    for i in range(0, no_of_piles):
        nim_sum = (nim_sum^piles[i])    
    if nim_sum:
        return (starting_player)    # If nim sum is non-zero, starting player wins.
    return (starting_player+1)%2    # If nim sum is zero, the second player wins.

starting_player = 0
no_of_piles = 5
piles = [3,4,1,7,6]
print("Player",calculateWinner(starting_player, piles, no_of_piles),"will win.")

'''
Input : starting_player = 0,
        piles = {3,4,1,7,6}
Output: Player 0 will win.
'''
