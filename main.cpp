#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;
//  11

// load rules of our game
void load_rule(){
    ifstream fin;
	fin.open("instruction.txt"); // need to be written

    if ( fin.fail() ){
		cout << "Error in file opening!"
			<< endl;
 		exit(1);
 	}

    string line;

	while ( getline(fin, line) ) {
		cout << line << endl;
 	}

	fin.close();
}

// create a board class to manipulate the chess board
//black -> ● ◉
//white -> ○


int flag = 0;
int col,row;
string arr[15][15];
string save_address;

void print_board(){
    cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14" << endl;
    for (int i = 0; i<15; i++) {
        cout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
        if (i >= 10) {
            cout << i << '|';
            for (int j = 0; j<15; j++) {
                cout << ' ' << arr[i][j] << " |";
        }
        }
        else {
            cout << ' ' << i << '|';
                for (int j = 0; j<15; j++) {
                    cout << ' ' << arr[i][j] << " |";
        }
        }
        cout << endl;
    }
    cout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
}

// use for save board
void save_board(string arr[15][15],string player1, string player2, int col, int row, bool game_signal,string save_address, int flag) {
    ofstream fout;

//     cout << "Please enter the address you want to save the board, it should end with .txt " << endl;
//     cin >> save_address;     this has been added in the initialization function
    fout.open(save_address, ios::app);

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

	else if (flag == 0){ // ensure this will only appear once
        time_t now = time(0);
        char* dt = ctime(&now);
        fout << "The board paused/ended on: " << dt << endl;
    }
//store the user input --------------------------------------------
    if (flag == 15*15-1){ // this is the case that the board is full and no one win
        fout << "This is a tie game, game over..." << endl;
        fout.close();
        exit(1);
    }
    
	if (game_signal == false)
		flag-=1;

    if (flag%2==0 && row != -1){ // this means player1
		if (game_signal == true)
        	fout << player1 << ": " << row << " " << col << endl;
    }
    else if (flag%2 == 1 && row != -1){ //this means player2
		if (game_signal == true)
        	fout << player2 << ": " << row << " " << col << endl;
    }
// ----------------------------------------------------------------

// this will print if someone is win --------------------------
    if (game_signal == false){// this means the game is over
        fout << endl;
        fout << "There is the final board:" << endl;
    }
// ------------------------------------------------------------

//this will print at the end of file I/O
	if (row == -1 || game_signal == false){
		fout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14" << endl;
		for (int i = 0; i<15; i++) {
			fout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
			if (i >= 10) {
				fout << i << '|';
				for (int j = 0; j<15; j++) {
					fout << ' ' << arr[i][j] << " |";
				}
			}
			else {
				fout << ' ' << i << '|';
					for (int j = 0; j<15; j++) {
						fout << ' ' << arr[i][j] << " |";
					}
			}
			fout << endl;
		}
		fout << "  ·---+---+---+---+---+---+---+---+---+---+---+---+---+---+---·" << endl;
		if (game_signal == false){
            if (flag%2 == 0)
                fout << player1 << " is the winner!" << endl;
            else
                fout << player2 << " is the winner!" << endl;
		}
	}

    fout.close();
}

// this function is used to take in the user input and change the values inside arr
// this function will avoid the case 1) user input is out of range 2)the user input is already occupied
// the player will input row and then col, flag is used todetermine it is player 1 or player 2
void player(int &flag,int &col, int &row, string arr[15][15],string player1,string player2,bool &game_signal){
  int check = 0;
  while (check == 0){
	  if (flag%2 +1 == 1) {
		  cout << player1 << ": ";
	  }
	  else {
          cout << player2 << ": ";
      }

    // fix the wrong type of input lead to infinite loop
    cin >> row;
	while (cin.fail() == 1){
		cin.clear();
		cin.ignore();
		cout << "Invalid Row Input, try again..." << endl;
		cin >> row;
	}

    if (row == -1) {
        save_board(arr,player1,player2,col,row,game_signal,save_address,flag);
        exit(1);
    }

	cin >> col;
	while (cin.fail() == 1){
		cin.clear();
		cin.ignore();
		cout << "Invalid Col Input, try again..." << endl;
		cin >> col;
	}
	// fix infinite loop ------------------------------------------------------

    if (col>=15 || row >=15){
    	cout << "Invalid Input, try again..." << endl;
    }
    else if (arr[row][col]=="●" || arr[row][col]=="○" ||  arr[row][col]=="X"){
    	cout << "Invalid Input, try again..." << endl;
    }
    else
    	check++; // if the user input is valid then the while loop will end
  }
/* above code has figured different situations of user input

----------------------------------------------------------------

code below changes the value of the 2D array (board)*/
  if (flag%2==0){
	  arr[row][col] = "●";
	  save_board(arr,player1,player2,col,row,game_signal,save_address,flag);
	  flag++;
  }

  else{
	  arr[row][col] = "○";
	  save_board(arr,player1,player2,col,row,game_signal,save_address,flag);
	  flag++;
  }
  cout << endl;
}

void block() { //initialize board with blocks stopping user input
    int number = 20; //number of blocks, can be modified by user later
    srand(time(0)); //problem with random seed, random_shuffle not random
    vector<string> board_item;
    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            board_item.push_back(arr[i][j]);
        }
    }
    vector<string>::iterator itr = board_item.begin();
    for (int i = 0; i< number; i++) {
        *itr = "X";
        itr++;
    }
    random_shuffle(board_item.begin(), board_item.end());

    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            arr[i][j] = board_item[i*15+j];
        }
    }
}



int straight_five(string arr[15][15],int row,int col){
  //row success
    for(int i = 0; i < 5; i++){
        if(col - i >= 0 && col - i + 4 < 15){
          if (arr[row][col-i] == arr[row][col-i+1] &&
          arr[row][col-i] == arr[row][col-i+2] &&
          arr[row][col-i] == arr[row][col-i+3] &&
          arr[row][col-i] == arr[row][col-i+4] &&
          arr[row][col-i] != " ")
            return 1;
        }
    }

  //column success
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 && row - i + 4 < 15){
          if (arr[row-i][col] == arr[row-i+1][col] &&
          arr[row-i][col] == arr[row-i+2][col] &&
          arr[row-i][col] == arr[row-i+3][col] &&
          arr[row-i][col] == arr[row-i+4][col] &&
          arr[row-i][col] != " ")
            return 1;
        }

    }

  // diaginal success (ascending)
    for(int i = 0; i < 5; i++){
        if(row + i < 15 && row + i - 4 >= 0 && col - i >= 0 && col - i + 4 < 15){
          if (arr[row+i][col-i] == arr[row+i-1][col-i+1] &&
          arr[row+i][col-i] == arr[row+i-2][col-i+2] &&
          arr[row+i][col-i] == arr[row+i-3][col-i+3] &&
          arr[row+i][col-i] == arr[row+i-4][col-i+4] &&
          arr[row+i][col-i]!=" ")
            return 1;
        }
    }

  // diagonal success (decending)
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 && row - i - 4 < 15 && col - i >= 0 && col - i + 4 < 15){
          if (arr[row-i][col-i] == arr[row-i+1][col-i+1] &&
          arr[row-i][col-i] == arr[row-i+2][col-i+2] &&
          arr[row-i][col-i] == arr[row-i+3][col-i+3] &&
          arr[row-i][col-i] == arr[row-i+4][col-i+4] &&
          arr[row-i][col-i]!=" ")
            return 1;
        }
    }

    return 0;
}

bool success(string arr[15][15]) {
    for (int row = 0; row < 15; row++){
        for (int col = 0; col < 15; col++){
            if (straight_five(arr, row, col) == 1){
				row = -1;
				return false;
			}
        }
    }
    return true;
}


void classic(string &player1,string &player2){
    bool game_signal = true;
	print_board();
    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
    while (game_signal == true){
        player(flag,col,row,arr,player1,player2,game_signal);
        if (flag>=1){
            system("clear");
        }
        print_board();
		game_signal = success(arr);
        if (game_signal){ // this means the game_signal is still true
            if (flag == 15*15-1){
                cout << "this is a tie game, game is finished." << endl;
                game_signal = false; //change the value to end the while loop
            }
        }
    }
    game_signal = success(arr);
    save_board(arr,player1,player2,col,row,game_signal,save_address,flag);
}


void blocked_mountains(string &player1,string &player2){
    bool game_signal = true;
    block();
    print_board();
    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
    while (game_signal == true){
        player(flag,col,row,arr,player1,player2,game_signal);
        if (flag>=1)
        system("clear");
        print_board();
		game_signal = success(arr);
        if (game_signal){ // this means the game_signal is still true
            if (flag ==15*15-1){
                cout << "this is a tie game, game is finished." << endl;
                game_signal = false;
            }
        }
    }
    game_signal = success(arr);
    save_board(arr,player1,player2,col,row,game_signal,save_address,flag);
}

void wild_parties(string &player1,string &player2){
    bool game_signal = true;
    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
}

// initialize game:
// 1. choose mode: A.classic, B.blocked mountains (having blocked cells), C. wild parties (several cooool things may happen)
// 2. save and load chess board
// 3. Rename Players !!to be implemented
string initialize(string &player1,string &player2){
    string indicator;
    cout << "*---------------------------------------------------*" << endl;
    cout << "Welcome to Gomoku Pro! Enjoy your game" << endl;
    cout << "Do you want to read game instruction (recommended)? Please input [y/n]" << endl;
    cin >> indicator;
    if (indicator == "y"){
        load_rule();
    }
	cout << "Please enter the address you want to save the board, it should end with .txt" << endl;
    cin >> save_address;
    cout <<  "What's Player1's name? Please enter here:" << endl;
    cin >> player1;
    cout <<  "What's Player2's name? Please enter here:" << endl;
    cin >> player2;

    cout <<  "Please choose game mode by entering corresponding number key" << endl;
    cout <<  "[a]: Classic Mode | [b]: Blocked Mode | [c]: Wild Mode" << endl;
    cout <<  "What to know more about these modes? Please input [y]" << endl;
    cin >> indicator;
    if (indicator == "y"){
        load_rule();
    }
    return indicator;

}

int main() {
    string player1,player2,mode_indicator;
    mode_indicator = initialize(player1,player2);
	//need to assign " " to arr[i][j]
	for (int i = 0; i<15; i++) {
    	for (int j = 0; j<15; j++) {
        	arr[i][j] = " "; //after input, change to ● (black) or ○ (white)
    	}
  	}
    // starting game

    if (mode_indicator == "a"){
        cout << "You have chosen classic mode" << endl;
        classic(player1,player2);
    } else {
        if (mode_indicator == "b"){
            cout << "You have chosen blocked mode" << endl;
            blocked_mountains(player1,player2);
        } else {
            if (mode_indicator == "c"){
                cout << "You have chosen wild mode, let's go crazzzy!" << endl;
                wild_parties(player1,player2);
            } else {
                cout << "Error in game mode indicator! Please re-start" << endl;
                exit(1);
            }
        }
    }
}
