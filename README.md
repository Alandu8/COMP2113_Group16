# COMP2113_Group16
COMP 2113 group project for group 16

## Team members:
###### Du Liheng 3035532870  
###### Chen Jiaqi 3035771139  
###### Xing Tian 3035827249  
###### Fang Yu 3035830698  

## Game Description

There is a 19×19 board for two players. Two players will claim a box alternatively. 
The winning strategy is similar to Gomoku, also known as Five in a Row. 
The winner is the first player to construct a continuous chain of five boxes horizontally, vertically, or diagonally, but there are several additional rules in this game.

  - Whether player 1 or player 2 will play first is randomly decided.
  - Initially, there are 20 random exclueded boxes which are not available for both two players. Available boxes are non-exclueded at the beginning or unclaimed by         players. If player choose the unavailable box, he will receive a warning and be asked to change his selection.
  - The first player should claim an available box.
  - After each player's decision, the other player is required to claim an available box. The claiming is an alternative operation.
  - The game will end if one player construct an unbroken chain of five boxes horizontally, vertically, or diagonally. This player will be the winner.

## Game Features

#### 1. Generation of random game sets or events

  - The board is initialised in random: which player will play first.
  - The board will generate a few unplacable positions at the beginning.

#### 2. Data structures for storing game status

  - The program implies "struct" to illustrate the points and use array to store the board.

#### 3. Dynamic memory management

  - When the one/two players give the place they want to put their chess on, one dynamic varible is used to store the 2D coordinates, x and y. After passing the value to the function, the dynamic variable is deleted to free space.

#### 4. File input/output 

  - Input: Using existing board or initialize a new game, choosing between single player mode(play with AI) or double player mode (play with your friends)
  - Output: When players want to exit game in the middle or the game is over, the board is saved in both a txt script file 'saved_board.txt' and a visual-friendly board picture
  
#### 5. Program codes in multiple files

  -

## External Libraries



## Further Info

3 links (TO DO)
