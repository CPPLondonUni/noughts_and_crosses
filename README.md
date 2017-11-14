
# C++ London University Session 6 Group Exercise #

## Noughts and Crosses ##

Your task for this evening is to write a console-based, two player 
noughts-and-crosses (AKA tic-tac-toe) game.

## Requirements ##

The game should proceed as follows:

 1. Ask player 1 for their name, followed by player 2. These names should then be 
    used to address the players for the remainder of the game.
 
 2. Ask player 1 to choose a token (nought or cross). Player 2 will use the
    opposite token.
   
 3. Ask player 1 to choose a cell. How you read the input
    is up to you. Redraw the board with player 1's token drawn in the
    appropriate cell.
    
 4. Ask player 2 to choose a cell. If this cell is already taken, inform
    the player and ask them to choose again. Redraw the board showing all
    the tokens placed so far.
    
 5. Repeat steps 3 and 4 until a player has won, or the game as
    ended in a draw. If there is a winner, that player has 2 points added
    to their total score, and the other player receives 0 points. If the game is a draw,
    both players receive 1 point.
    
 6. Print the current total scores for both players.
    
 7. Ask whether the players wish to play another game, or quit. If they
    wish to play again, restart the game, but *alternate the starting player*. For
    example, if player 1 started the last game then player 2 starts this game,
    and vice versa.
    
 8. If the players choose not to start a new game, announce the overall winner
    (if any).
    
## Getting started ##

The file `tictactoe.hpp` contains the interface for a simple library to help
you build the game. It consists of a `board` class, an enumeration `entry`
representing the state of each cell of the grid (`empty`, `nought` or `cross`),
and an output steaming function to print the grid.

The file `game.cpp` contains an empty `main()` routine for you to fill in with
your game code

Also declared in `tictactoe.hpp` are two helper functions `check_winner()` and
`check_draw()`, which can be used to check whether a player has won, or if the
game has ended in a draw respectively. However, these are NOT IMPLEMENTED
correctly: if you want to use them in your game, you will
need to provide a correct implementation in `tictactoe.cpp`.

You are free to change or add to any of the given files in any way you
like, or add new files to the project. The provided functions are merely intended
to help you get started -- you are  not required to use them.

**Have fun!**
