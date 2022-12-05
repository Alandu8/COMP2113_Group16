# COMP2113_Group16 ｜ Gomoku Pro
COMP 2113 group project for group 16

## Team members:
###### Du Liheng 3035532870  
###### Chen Jiaqi 3035771139  
###### Xing Tian 3035827249  
###### Fang Yu 3035830698  

## Game Description

The winning strategy is similar to Gomoku, also known as Five in a Row.  
There is a 15×15 board for two players. Two players will claim a box alternatively. 
The winner is the first player to construct a continuous chain of five boxes horizontally, vertically, or diagonally, but there are several additional rules in this game.

  - The first player should claim an available box.
  - After each player's decision, the other player is required to claim an available box. The claim is an alternative operation.
  - The game will end if one player constructs an unbroken chain of five boxes horizontally, vertically, or diagonally. This player will be the winner.

## Game Features

#### 1. Generation of random game sets or events
  
  - Except the standard mode, we provide two other modes with random incidents.
  - In the blocked mountain mode, the board will randomly generate a few unplaceable positions at the beginning.
  - In the crazzzy mode, three incidents will happen based on certain probabilities:
    - There is a 33.3% chance that a random bomb will be planted in a block. The bomb will remove and block the cell like what happens in Blocked Mode.
    - There is also a 50% chance that the a supported piece of either ● or ○ will be randomly placed on the board. If the block is occupied or blocked, the supported piece will not appear. Meanwhile, for all extra added pieces, no matter ● or ○, it has a 25% chance to be removed in further rounds once it has been added on the chess board.



#### 2. Data structures for storing game status

  - The program uses a double array called `arr` to store the game status and generate the visual chess board.

#### 3. Dynamic memory management

  - In the crazzy mode, a dynamic memory management method is applied to create a vector of vectors in the function `random_supply()`. It is used to store the temporary 50% rate of added cheese and remove them when the 25% removing rate is hit. These two 2 dimensional vectors are `B_set_support_co` for the solid circle ● and `W_set_support_co` for hollow circles ○.

#### 4. File input/output 

  - Input: Using existing board or initializing a new game, choosing between starting a new game or load some existing board and corresponding game status to continue the game.
  - Output: When players want to exit the game in the middle or the game is over, the board is saved in both a txt script file named by themselves'.txt' with a visual-friendly board picture and clear playing record.
  
#### 5. Program codes in multiple files

  - Files are  `main.cpp`, `body.cpp`, `body.h` and `Makefile`. 
  - `main.cpp` is our main function and we will include the functions that we defined in `body.cpp`.
  - we use `Makefile` to link files.

## Further Info

Video link:
https://connecthkuhk-my.sharepoint.com/:v:/g/personal/u3553287_connect_hku_hk/Eebk4vX_ZitMo8aYKCN-MpsB0dYa8eIoxwawI38F1ZEbFQ?e=0Tf76W
