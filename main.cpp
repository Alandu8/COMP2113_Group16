#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;


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


int flag =0;
int col,row;
string arr[15][15];

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
void save_board(string arr[15][15]) {
    ofstream fout;
    string save_address;
    cout << "Please enter the address you want to save the board, it should end with .txt " << endl;
    cin >> save_address;
    fout.open(save_address);

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    fout << "There is the final board:" << endl;
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

    fout.close();
}

// this function is used to take in the user input and change the values inside arr
// this function will avoid the case 1) user input is out of range 2)the user input is already occupied
// the player will input row and then col
void player(int &flag,int col, int row, string arr[15][15],string player1,string &player2,bool &game_signal){
  int check = 0;
  while (check == 0){
    if (flag%2 +1 == 1) {
        cout << player1 << ": ";
    } else {
        cout << player2 << ": ";
    }
    
    cin >> row >> col;
    if (row == -1) {
        game_signal = false;
    }

    if (col>=15 || row >=15){
      cout << "Invalid Input, try again..." << endl;
    }
    else if (arr[row][col]=="●" || arr[row][col]=="○" ||  arr[row][col]=="X"){
      cout << "Invalid Input, try again..." << endl;
    }
    else
      check++;
  }

  if (flag%2==0){
    arr[row][col] = "●";
    flag++;
  }

  else{
    arr[row][col] = "○";
    flag++;
  }
  cout << endl;
}
//11.17 block has problems to solve mode 1 is not working 
// void mode1(){ // version 1
//   block(); 
//   while (true){
//     player(flag,col,row,arr);
//     if (flag>=1)
//       system("clear");
//     print_board();
//   }
// }

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

void classic(string &player1,string &player2){ 
    bool game_signal = true;
    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
    while (game_signal){
        player(flag,col,row,arr,player1,player2,game_signal);
        if (flag>=1){
            system("clear");
        }
        print_board();
    }
    save_board(arr);
}


void blocked_mountains(string &player1,string &player2){
    bool game_signal = true;
    block();
    print_board();
    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
    while (game_signal){
        player(flag,col,row,arr,player1,player2,game_signal);
        if (flag>=1)
        system("clear");
        print_board();
    }
    save_board(arr);
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
