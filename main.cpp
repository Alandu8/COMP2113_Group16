#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

// create a board class to manipulate the chess board
//black -> ● ◉
//white -> ○


int flag =0;
int col,row;
string arr[15][15];

void print_board(){
    cout << "    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14" << endl;
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

// this function is used to take in the user input and change the values inside arr
// this function will avoid the case 1) user input is out of range 2)the user input is already occupied
// the player will input row and then col
void player(int &flag,int col, int row, string arr[15][15]){
  int check = 0;
  while (check == 0){
    cout << "Player " << flag%2 +1 << ": ";
    cin >> row >> col;
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

int main() {

    for (int i = 0; i<15; i++) {
        for (int j = 0; j<15; j++) {
            arr[i][j] = " "; //initially is blank or x(blocked), after input, change to ● (black) or ○ (white)
        }
    }
    block();
    while (true){ // define a function which will return true if 5 in a line
        player(flag,col,row,arr);
        if (flag>=1){
          system("clear");
        }
        print_board();
    }
}
