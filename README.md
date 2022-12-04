# COMP2113_Group16
COMP 2113 group project for group 16

## Team members:
###### Du Liheng 3035532870  
###### Chen Jiaqi 3035771139  
###### Xing Tian 3035827249  
###### Fang Yu 3035830698  

## Game Description

There is a 15×15 board for two players. Two players will claim a box alternatively. 
The winning strategy is similar to Gomoku, also known as Five in a Row. 
The winner is the first player to construct a continuous chain of five boxes horizontally, vertically, or diagonally, but there are several additional rules in this game.

  - Whether player 1 or player 2 will play first is randomly decided.
  - Initially, there are 20 random exclueded boxes which are not available for both two players. Available boxes are non-exclueded at the beginning or unclaimed by         players. If player choose the unavailable box, he will receive a warning and be asked to change his selection.
  - The first player should claim an available box.
  - After each player's decision, the other player is required to claim an available box. The claiming is an alternative operation.
  - The game will end if one player construct an unbroken chain of five boxes horizontally, vertically, or diagonally. This player will be the winner.

## Game Features

#### 1. Generation of random game sets or events
  
  - Except the standard mode, we provide two other modes with random incidents.
  - In the blocked mountain mode, he board will randomly generate a few unplacable positions at the beginning.
  - In the crazzzy mode, three incidents will happen based on certain probabilities:
    - There is a 33.3% chance that a random bomb will be planted in a block. The bomb will remove and block the cell like what happens in Blocked Mode.
    - There is also a 10% chance that the piece is converted when the player placed it. For example, the hollow circle ○ will become solid circle ●, and the solid circle ● will become hollow circle ○.
    - There is also a 50% chance that the a supported piece of either ● or ○ will be randomly placed in the board. If the block is occupied or blocked, the supported piece will not appear. 

#### 2. Data structures for storing game status

  - The program use a double array called `arr` to store the game status and generate the visual chess board.

#### 3. Dynamic memory management

  - In the crazzy mode, a dynamic memory management method is applied to create a vector of vector in function `random_supply()`. It is used to store the temporary 50% rate added chesses and remove them when the 25% removing rate is hit. These two 2d vectors are `B_set_support_co` for the solid circle ● and `W_set_support_co` for hollow circle ○.

#### 4. File input/output 

  - Input: Using existing board or initialize a new game, choosing between starting a new game or load some existing board and corresponding game status to continue the game.
  - Output: When players want to exit game in the middle or the game is over, the board is saved in both a txt script file named by themselves'.txt' with a visual-friendly board picture and clear playing record.
  
#### 5. Program codes in multiple files

  - Files are  `main.cpp`, `body.cpp`, `body.h` and `Makefile`. 
  - `main.cpp` is our main function and we will include the functions that we defined in `body.cpp`.
  - we use `Makefile` to link files.

## External Libraries



## Further Info

3 links (TO DO)
