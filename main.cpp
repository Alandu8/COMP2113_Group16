#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

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
//black -> ● 
//white -> ○


int flag = 0;
int col,row;
char mode;
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
void save_board(string arr[15][15],string player1, string player2, int col, int row, bool game_signal,string save_address, int flag,char mode) {
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
        if (mode == 'a')
            fout << "Classic" << endl;
        else if (mode == 'b')
            fout << "Blocked Mountain" << endl;
        else if (mode == 'c')
            fout << "Wild Party" << endl;
        fout << endl;
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
        fout << "There is the final board:" << endl;
    }

// ------------------------------------------------------------

//this will print at the end of file I/O
	if (row == -1 || game_signal == false){
        // if the game is paused
        if (row == -1){
            fout << "There was " << flag << " moves." << endl;
            fout << "The current board..." << endl;
        }
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
        save_board(arr,player1,player2,col,row,game_signal,save_address,flag,mode);
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
	  save_board(arr,player1,player2,col,row,game_signal,save_address,flag,mode);
	  flag++;
  }

  else{
	  arr[row][col] = "○";
	  save_board(arr,player1,player2,col,row,game_signal,save_address,flag,mode);
	  flag++;
  }
  cout << endl;
}
int Rand(int i) {return rand()%i;}

void block() { //initialize board with blocks stopping user input
    
    int number = 20; //number of blocks, can be modified by user later
    srand ( unsigned ( time(0) ) );//problem with random seed, random_shuffle not random
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
    random_shuffle(board_item.begin(), board_item.end(), Rand);

    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            arr[i][j] = board_item[i*15+j];
        }
    }
}

int straight_five(string arr[15][15],int row,int col){
    //row
    for(int i = 0; i < 5; i++){
        if(col - i >= 0 &&
        col - i + 4 < 15 &&
        arr[row][col-i] != " " &&
        arr[row][col-i] != "X" &&
        arr[row][col-i] == arr[row][col-i+1] &&
        arr[row][col-i] == arr[row][col-i+2] &&
        arr[row][col-i] == arr[row][col-i+3] &&
        arr[row][col-i] == arr[row][col-i+4]){return 1;}
    }

    //column
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 &&
        row - i + 4 < 15 &&
        arr[row-i][col] != " " &&
        arr[row-i][col] != "X" &&
        arr[row-i][col] == arr[row-i+1][col] &&
        arr[row-i][col] == arr[row-i+2][col] &&
        arr[row-i][col] == arr[row-i+3][col] &&
        arr[row-i][col] == arr[row-i+4][col]){return 1;}
    }

    // diaginal (lower left to upper right)
    for(int i = 0; i < 5; i++){
        if(row + i < 15 &&
        row + i - 4 >= 0 &&
        col - i >= 0 &&
        col - i + 4 < 15 &&
        arr[row+i][col-i] != " " &&
        arr[row+i][col-i] != "X" &&
        arr[row+i][col-i] == arr[row+i-1][col-i+1] &&
        arr[row+i][col-i] == arr[row+i-2][col-i+2] &&
        arr[row+i][col-i] == arr[row+i-3][col-i+3] &&
        arr[row+i][col-i] == arr[row+i-4][col-i+4]){return 1;}
    }

    // the othe diginal 
    for(int i = 0; i < 5; i++){
        if(row - i >= 0 &&
        row - i - 4 < 15 &&
        col - i >= 0 &&
        col - i + 4 < 15 &&
        arr[row-i][col-i] != " " &&
        arr[row-i][col-i] != "X" &&
        arr[row-i][col-i] == arr[row-i+1][col-i+1] &&
        arr[row-i][col-i] == arr[row-i+2][col-i+2] &&
        arr[row-i][col-i] == arr[row-i+3][col-i+3] &&
        arr[row-i][col-i] == arr[row-i+4][col-i+4]){return 1;}
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
    
    while (success(arr)){
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
    if (game_signal == false){
        if (flag%2 == 0) 
        /*
        after the success turns false 
        we need to flag -= 1 
        to make sure flag%2==0 is player1
        */
                cout << player2 << " is the winner!" << endl;
            else
                cout << player1 << " is the winner!" << endl;
    }
    save_board(arr,player1,player2,col,row,game_signal,save_address,flag,mode);
    if (flag == 15*15-1){ // this is the case that the board is full and no one win
        cout << "This is a tie game, game over..." << endl;
        exit(1);
    }
}


void blocked_mountains(string &player1,string &player2){
    bool game_signal = true;
    block();
    print_board();
    
    while (success(arr)){
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
    if (game_signal == false){
        if (flag%2 == 0) 
        /*
        after the success turns false 
        we need to flag -= 1 
        to make sure flag%2==0 is player1
        */
                cout << player2 << " is the winner!" << endl;
            else
                cout << player1 << " is the winner!" << endl;
    }
    save_board(arr,player1,player2,col,row,game_signal,save_address,flag,mode);
    if (flag == 15*15-1){ // this is the case that the board is full and no one win
        cout << "This is a tie game, game over..." << endl;
        exit(1);
    }
    
}

void random_bomb(){
    //There is a 33% chance that a random bomb planted in a block. 
    //The bomb will remove and restrict the block.

    //33% judgement
    srand(time(NULL)+100);
    int if_bomb;
    if_bomb = rand()%3;

    //bomb planted    
    if (if_bomb == 0){
        int bomb_row;
        int bomb_col;
        srand(time(NULL)+101);
        bomb_row = rand()%15;
        bomb_col = rand()%15;
        arr[bomb_row][bomb_col] = "X";
    }
}

void random_convert(){
    //There is a 10% chance that the piece is converted when the player placed it. 
    //i.e. the "○"  will become "●", and the "●" will become "○".

    //10% judgement
    srand(time(NULL)+110);
    int if_convert;
    if_convert = rand()%10;

    //covert the piece    
    if (if_convert == 0){
        if (arr[row][col] == "○"){
            arr[row][col] = "●";
        }
        if (arr[row][col] == "●"){
            arr[row][col] = "○";
        }
    }
}

void random_support(){
    //There is a 50% chance that the a supported piece will be randomly placed in the board.
    //If the block is occupied or restricted, the supported piece will not appear. 


    //50% judgement
    srand(time(NULL)+130);
    int if_support;
    if_support = rand()%2;

    //A supported piece will appear randomly in the board if the place is not occupied or restricted
    if (if_support == 0){

        if (flag%2 == 0){
            int support_row;
            int support_col;
            srand(time(NULL)+131);
            support_row = rand()%15;
            support_col = rand()%15;
            if (arr[support_row][support_col] !="●" || arr[support_row][support_col] !="○" ||  arr[support_row][support_col] !="X"){
                arr[support_row][support_col] = "●";
            }
        }

        if (flag%2 == 1){
            int support_row;
            int support_col;
            srand(time(NULL)+132);
            support_row = rand()%10;
            support_col = rand()%10;
            if (arr[support_row][support_col] !="●" || arr[support_row][support_col] !="○" ||  arr[support_row][support_col] !="X"){
                arr[support_row][support_col] = "○";
            }
        }
    }
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

void file_input(string fn,string &player1, string &player2,char &mode,string &save_address){
    ifstream fin;
    fin.open(fn);
    int num_line = 0,row,col,p1=0,p2=0;
    string line;
    int count = 0;
    save_address = fn;
    // line 3 gives the mode
    while (getline(fin,line)){
        if (line.substr(0,9) == "There was")
            break;
        num_line++;
        if (num_line == 3){ // this line tells the mode
            if (line[0] == 'C'){ // the classic mode 
                mode = 'a';
            }
            else if (line[0] == 'B') {// the second mode
                mode = 'b';
            }
            else if (line[0] == 'W'){// the third mode
                mode = 'c';
            }
        }
        if (num_line >= 5){ //from this line it is the user input 
            //get the name of the player1
            if (num_line == 5){
                while (line[p1]!=':'){
                    player1+=line[p1];
                    p1++;
                }
            } // i store the length of the name for player 1
            // i + 2 and i + 4 is the row and col input 
            else if (num_line == 6){
                while (line[p2]!=':'){
                    player2+=line[p2];
                    p2++;
                }
            } // j + 2 and j + 4 is the row and col input  
            // odd line is the player1 and the even line is the player2
            if (num_line%2==1){
                //this means the player1 input 
                row = line[p1+2]-48;
                col = line[p1+4]-48;
                arr[row][col] = "●";
                flag++;
                //cout << row << " " << col << endl;
            }
            
            if (num_line%2==0){
                // this means the player2 input 
                row = line[p2+2]-48;
                col = line[p2+4]-48;
                //arr[row][col] = "○";
                flag++;
                arr[row][col] = "○";
                //cout << row << " " << col << endl;
            }
        } 
    }
}


int main(int argc, char** argv) {
    for (int i = 0; i<15; i++) {
            for (int j = 0; j<15; j++) {
                arr[i][j] = " "; //after input, change to ● (black) or ○ (white)
            }
    }
    string player1,player2,mode_indicator;
    if (argc<2){ //there is no file input if argc < 2
        mode_indicator = initialize(player1,player2);

        // starting game

        if (mode_indicator == "a"){
            mode = 'a';
            cout << "You have chosen classic mode" << endl;
            cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
            classic(player1,player2);
        } else {
            if (mode_indicator == "b"){
                mode = 'b';
                cout << "You have chosen blocked mode" << endl;
                cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
                blocked_mountains(player1,player2);
            } else {
                if (mode_indicator == "c"){
                    mode = 'c';
                    cout << "You have chosen wild mode, let's go crazzzy!" << endl;
                    cout <<  "Game starts! You may interrupt the game by entering [-1]" << endl;
                    wild_parties(player1,player2);
                } else {
                    cout << "Error in game mode indicator! Please re-start" << endl;
                    exit(1);
                }
            }
        }
    }
    else { 
        // there is file input 
        string fn = argv[1];
        // file_input(fn,player1,player2,arr,flag);
        // cout << player1 << " " << player2 << " " << flag << endl;
        file_input(fn,player1,player2,mode,save_address);
        if (mode == 'a'){
            classic(player1,player2);
        }
        else if (mode == 'b'){
            blocked_mountains(player1,player2);
        }
        else if (mode == 'c'){
            wild_parties(player1,player2);
        }
    }
}
